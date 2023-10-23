// TestClassDef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// C 언어: printf() in <stdlib.h>
// C++ 헤더 파일 확장자: *.hpp
#include <iostream> // C++ 언어의 표준 입출력 헤더 파일
#include "MyCircle.h"

int main()
{
	using namespace std; // 아래부터는 std::을 쓸 필요 없음
	using namespace mglib;
	//cout << "Hello World!\n";

	// 코드 블록 정의: 지역 변수는 이 코드 블록 내부에서만 사용되고 }를 만나면 소멸됨
	{
		settextcol(RED);
		// 인스턴스(instance == example): 클래스를 사용할 수 있는 상태로 선언이나 정의된 형태
		// 변수 선언과 비슷하게 클래스 선언, 인스턴스 생성
		MyCircle myCircle; // 클래스명 == 자료형, 인스턴스명 == 변수명; 인스턴스명은 보통 소문자로 시작
		// 인스턴스의 멤버 접근: . 점 연산자 사용(구조체와 비슷)
		myCircle.setRad(1.2); // 입력이 double
		myCircle.setRad(20);	// 입력이 int
		myCircle.setRad();	// 입력이 없음 -> 기본값으로 설정
		myCircle.setCenter(-2., 4.);
		myCircle.setCenter();
		myCircle.setCenter(5.); // x는 입력한 값 사용; y는 기본값 사용
		myCircle.print();
	} // 지역 변수인 인스턴스 myCircle이 소멸됨
	{
		gotoxy(0, 0); // 커서를 (x, y) = (0, 0) 지점으로 이동
		settextcol(GREEN);
		cout << endl << "====================" << endl << endl;
		//MyCircle myCircle(1., -2., -3.);
		MyCircle myCircle{ 1., -2., -3. };
		myCircle.print();
	}
	{
		settextcol(BLUE);
		cout << endl << "====================" << endl << endl;
		MyCircle myCircle(100.);
		myCircle.print();
	}
	{
		settextcol(YELLOW);
		cout << endl << "====================" << endl << endl;
		MyCircle myCircle(30., 40.);
		myCircle.print();
	}
	cout << endl << "프로그램 종료" << endl;
}