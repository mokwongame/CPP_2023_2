// MyScreenSaver.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h> // 운영 체제인 Windows 기능을 쓰는 함수를 include
#include "MyCircle.h" // 원 그리기 클래스 include(포함)
#include "LibGameTool.hpp"	// 난수 발생 멤버 include

#define RAD_MAX	(15)
#define CENTER_X_MAX	(20)
#define CENTER_Y_MAX	(20)
#define LOGO_DELAY		(2000)
#define CIRCLE_DELAY	(1500)
#define AREA_Y_POS		(25)

void showLogo(void)
{
	using namespace std;
	using namespace mglib;
	// 이스케이프 문자 시작: \ -> 출력 원하면 \\를 쓰면 됨
	settextcol(GREEN);
	cout << "   _____                             _____                 " << endl;
	cout << "  / ____|                           / ____|                " << endl;
	cout << " | (___   ___ _ __ ___  ___ _ __   | (___   __ ___   _____ " << endl;
	cout << "  \\___ \\ / __| '__/ _ \\/ _ \\ '_ \\   \\___ \\ / _` \\ \\ / / _ \\" << endl;
	cout << "  ____) | (__| | |  __/  __/ | | |  ____) | (_| |\\ V /  __/" << endl;
	cout << " |_____/ \\___|_|  \\___|\\___|_| |_| |_____/ \\__,_| \\_/ \\___|" << endl;
	settextcol(YELLOW);
	cout << "===================" << endl;
	cout << " My First Screen Saver" << endl;
	cout << " Mokwon Game Ver. 1.0" << endl;
	cout << "===================" << endl;
}

void showArea(const MyCircle& circle) // & 의미: 참조자(reference); 참조자는 원본의 복사본 만들지 않고 원본에 참조 위치로 접근만 함
// const 의미: 입력 circle을 const(상수)로 취급 -> 값을 바꾸지 않음
{
	using namespace std;
	double area = circle.getArea(); // 원의 면적
	mglib::gotoxy(0, AREA_Y_POS);
	cout << "현재 원의 면적 = " << area << "       ";
}

int main()
{
	using namespace std;
	using namespace mglib;

	randseed(); // 난수 초기화
	showLogo();
	::Sleep(LOGO_DELAY); // 잠자기(실행 정지): 단위는 msec; namespace 접근 :: 사용; :: 앞에 namespace 이름이 없으면 global namespace(쉽게 말해 전역 함수)
	clrscr(); // 화면 지우기(clear screen)
	while (1) // 무한 반복 구문: (...) 판단식이 항상 1이 되면 true라서 무한 반복
	{
		// 키보드를 누르면 빠져나가기
		if (_kbhit()) break; // 키보드(keyboard)를 누르면(hit) true를 return; 반복문에 break를 호출하면 반복문을 강제 종료
		int rad = randrange(1, RAD_MAX + 1); // (rmin, rmax): rmin과 rmax-1 사이의 정수를 난수로 발생
		int x = randrange(1, CENTER_X_MAX + 1); // __max(): 최대값 선택
		x = __max(x, rad);
		int y = randrange(1, CENTER_Y_MAX + 1);
		y = __max(y, rad);
		int nTextColor = randrange(DARK_BLUE, WHITE + 1);
		int nBackColor = randrange(BLACK, WHITE + 1);
		MyCircle circle(rad, x, y); // MyCircle은 클래스명, myCircle은 변수명(인스턴스명); 클래스명(자료형으로 간주) 인스턴스명 -> 변수 선언과 동일
		circle.draw('*', nTextColor, nBackColor);
		showArea(circle);
		::Sleep(CIRCLE_DELAY);
		circle.draw(' '); // 공백으로 원을 그리기 -> 예전에 그린 원이 지워짐
	}
	return 0;
}