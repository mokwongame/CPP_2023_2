#include <iostream>
#include <math.h> // 삼각 함수 정의
#include "MyCircle.h"
#include "LibConsole.hpp"

#define PI	(3.141592)

// 메소드를 소스 파일에 정의할 때는 함수 정의 사용
//void MyCircle::setRad(double rad)
//{
//}

// 함수 정의
void MyCircle::setCenter(double x, double y)
{
	m_x = x, m_y = y; // 표현식 1개, 연산 2개
	//m_x = x; m_y = y; // 표현식 2개
}

// 스크린 좌표계: 원점(0, 0) - 좌측 상단; 우측 하단 방향으로 가면 x와 y 좌표가 커짐
void MyCircle::draw(char c)
{
	using namespace mglib;
	for (int i = 0; i < 360; i++) // i: 각도
	{
		double rad = i * PI / 180.; // 각도 -> 라디안
		double x = getRad() * cos(rad) + getCenterX(); // x 좌표: cos()
		double y = getRad() * sin(rad) + getCenterY(); // y 좌표: sin()
		int nX = int(x + 0.5); // 반올림
		//int nX = (int)(x + 0.5); // type casting(자료형 선정): double -> int
		int nY = int(y + 0.5);
		gotoxy(nX, nY);
		std::cout << c;
	}
}
