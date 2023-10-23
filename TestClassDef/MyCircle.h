#pragma once // 이 헤더 파일을 한 번만(once) 잘(pragmatic) 포함시키라는 뜻

#include <iostream>

// 파일명: MyCircle.h
// 객체(object): 문제를 풀기 위한 코드 블록의 기본 구조
// 클래스(class): 객체의 설계도
// 권고 사항: 파일명 == 클래스명
// 클래스명은 보통 대문자로 시작
class MyCircle // MyCircle이 클래스명
{
public: // public 그룹: 아래 있는 멤버는 모두 public
	// 멤버 함수(method: 메소드, 방법)는 보통 public 그룹에 정의
	// 프로퍼티 획득 함수(getter)
	double getRad(void) const { return m_rad; } // 인라인 함수로 처리; 함수 입출력 정의 뒤 const(상수) 의미: 이 함수는 멤버 변수를 변경하지 않음(쓰지 않음)
	double getCenterX(void) const { return m_x; }
	double getCenterY(void) const { return m_y; }
	// 프로퍼티 설정 함수(setter)
	//void setRad(double rad)
	void setRad(double rad = 1.0) // 입력이 없으면 기본값으로 1을 입력
	{
		std::cout << "double 입력 " << std::endl;
		m_rad = rad;
	} // C 언어와 동일하게 멤버 함수 선언; private 멤버라도 클래스 안에서는 접근 가능
	void setRad(int nRad)
	{
		std::cout << "int 입력" << std::endl;
		m_rad = nRad;
	}
	void setCenter(double x = 0., double y = 0.);

	void print(void) const;

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