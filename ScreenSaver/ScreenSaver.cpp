// ScreenSaver.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h> // 운영체제 접근 헤더 파일: Sleep() 함수
#include "MyCircle.h" // 원 그리기
#include "LibGameTool.hpp" // 난수 발생

int main()
{
	using namespace std;
	using namespace mglib;
	// 난수 발생 초기화
	randseed();
	// 화면 지우기: clear screen
	clrscr();
	// 무한 루프
	while (1) // 판단식 () 안이 1이라서 항상 true
	{
		// 키보드 히트: keyboard hit
		if (_kbhit()) break; // 키보드 히트이면 루프 파괴(break)
		double rad = randrange(1, 10 + 1); // 1,2,3, ..., 10
		double x = randrange(7, 17 + 1); // 7,8,9, ..., 17
		double y = randrange(7, 17 + 1);
		MyCircle circle(rad, x, y);
		circle.draw('*');
		::Sleep(3000); // 3000 msec 동안 잠자기(sleep)
		circle.draw(' '); // 공백으로 원 그리기 -> 원 지우기
	}
	return 0;
}