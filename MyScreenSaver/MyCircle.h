#pragma once // 이 헤더 파일을 한 번만(once) 잘(pragmatic) 포함시키라는 뜻

#include <iostream>
#include "LibConsole.hpp"

#define PI	(3.141592) // 원주율

// 파일명: MyCircle.h
// 객체(object): 문제를 풀기 위한 코드 블록의 기본 구조
// 클래스(class): 객체의 설계도
// 권고 사항: 파일명 == 클래스명
// 클래스명은 보통 대문자로 시작
class MyCircle // MyCircle이 클래스명
{
public: // public 그룹: 아래 있는 멤버는 모두 public
	// 멤버 함수(method: 메소드, 방법)는 보통 public 그룹에 정의
	// 생성자(constructor): 메소드명 == 클래스명; 클래스가 생성될 때(인스턴스가 만들어질 때) 자동적으로 호출되는 메소드(멤버 함수); 반환하는 자료형은 쓸 수 없음; 클래스를 쓰기 위한 기본적인 초기화 실행
	MyCircle(void)
	{
		//std::cout << "생성자(void) 호출" << std::endl;
	}
	MyCircle(double rad, double x, double y)
	{
		//std::cout << "생성자(rad, x, y) 호출" << std::endl;
		setRad(rad); // m_rad = rad; 대신 메소드 호출(일관성 위해)
		setCenter(x, y);
	}
	MyCircle(double rad) : // 생성자의 초기화 리스트
		m_rad(rad) // m_rad = rad
	{
		//std::cout << "생성자(rad) 호출" << std::endl;
	}
	MyCircle(double x, double y) : // 생성자의 초기화 리스트
		m_x(x),
		m_y(y)
	{
		//std::cout << "생성자(x, y) 호출" << std::endl;
	}
	// 소멸자, 파괴자(destructor): 메소드명 == ~클래스명; 인스턴스가 소멸될 때 자동적으로 호출; 입력 자료형 X, 출력 자료형 X; 메모리 정리할 때 주로 사용
	~MyCircle()
	{
		//std::cout << "소멸자 호출" << std::endl;
	}
	// 프로퍼티 획득 함수(getter)
	double getRad(void) const { return m_rad; } // 인라인 함수로 처리; 함수 입출력 정의 뒤 const(상수) 의미: 이 함수는 멤버 변수를 변경하지 않음(쓰지 않음)
	double getCenterX(void) const { return m_x; }
	double getCenterY(void) const { return m_y; }
	double getArea(void) const;

	// 프로퍼티 설정 함수(setter)
	//void setRad(double rad)
	void setRad(double rad = 1.0) // 입력이 없으면 기본값으로 1을 입력
	{
		//std::cout << "double 입력 " << std::endl;
		m_rad = rad;
	} // C 언어와 동일하게 멤버 함수 선언; private 멤버라도 클래스 안에서는 접근 가능
	void setRad(int nRad)
	{
		//std::cout << "int 입력" << std::endl;
		m_rad = nRad;
	}
	void setCenter(double x = 0., double y = 0.);

	void print(void) const;
	void draw(char mark = '*', int nTextColor = mglib::WHITE, int nBackColor = mglib::BLACK) const; // 함수의 디폴트값을 '*'로 선택

private: // private 그룹: 아래 있는 멤버는 모두 private(클래스 외부에서 접근 불가)
	// 멤버 변수(property: 프로퍼티, 성질, 속성)는 private 그룹에 정의
	double m_rad = 0.; // 반지름(radius); 접두어 m_는 멤버(member)를 표시; C 언어처럼 초기화
	double m_x = 0., m_y = 0.; // 원의 중심 좌표; C 언어처럼 초기화
protected: // protected 그룹
};

inline void MyCircle::print(void) const
{
	using namespace std;
	cout << "rad = " << getRad() << endl; // 같은 클래스의 멤버인 경우는 접근하기 위한 MyCircle:: 생략 가능
	cout << "x = " << getCenterX() << endl; // m_x는 private 멤버
	cout << "y = " << getCenterY();
}

inline void MyCircle::draw(char mark, int nTextColor, int nBackColor) const
{
	// using namespace mglib
	// 원의 x 좌표 = rad*cos(theta) + x0; x0는 중심의 x 좌표
	// 원의 y 좌표 = rad*sin(theta) + y0; y0는 중심의 y 좌표
	mglib::settextcol(nTextColor);
	mglib::setbackcol(nBackColor);
	for (int i = 0; i < 360; i++) // i는 360도 기준 각도
	{
		double ang = i / 180. * PI; // 각도 -> 라디안
		double x = getRad() * cos(ang) + getCenterX();
		double y = getRad() * sin(ang) + getCenterY();
		int nX = int(x + 0.5); // 반올림
		int nY = int(y + 0.5); // 반올림
		mglib::gotoxy(nX, nY);
		std::cout << mark;
	}
	mglib::settextcol(mglib::WHITE);
	mglib::setbackcol(mglib::BLACK);
}

inline double MyCircle::getArea(void) const
{
	return PI * getRad() * getRad();
}