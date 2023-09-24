// ClassDef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "MyCircle.h"
#include "LibConsole.hpp"

// 원 그리기

int main()
{
	using namespace std;
	MyCircle myCircle; // 인스턴스 생성: 자료형을 class명으로 생각한 변수 선언처럼 사용
	myCircle.setRad(10.2);
	myCircle.setCenter(15, 15);
	cout << "반지름 = " << myCircle.getRad() << endl; // 클래스의 멤버 접근: . 을 사용; 구조체(struct)의 멤버 접근과 동일
	cout << "중심 좌표 = (" << myCircle.getCenterX() << ", " << myCircle.getCenterY() << ")" << endl;
	cout << "ID = " << myCircle.getID() << endl;
	myCircle.draw('=');
	mglib::gotoxy(0, 26);
}
