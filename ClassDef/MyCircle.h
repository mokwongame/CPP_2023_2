#pragma once

// 원 그리기: 중심 좌표(x, y), 반지름(rad)
// class 클래스명 {...};
class MyCircle // 파일명 == 클래스명(강력한 권고 사항)
{
	// 접근 한정자가 없으면 private 취급
	int m_nID = 0;
	// public, private: 접근 제한자(access modifier)
	// 멤버 정의: 변수, 함수, 열거형 상수, 구조체, ...
public: // public 멤버(외부에서 접근 가능) 정의; : 밑에 있는 코드 블록의 변수와 함수는 모두 public; 내부에서 접근 가능
	// 멤버 변수: 프로퍼티(property) - 객체의 성질, 상태를 나타냄
	// 멤버 함수: 메소드(method) - 객체의 기능, 방법, 객체의 행동 방식
	double getRad(void) const { return m_rad; } // const 제한자: 현재 메소드가 프로퍼티를 변경하지 않음
	double getCenterX(void) const { return m_x; }
	double getCenterY(void) const { return m_y; }
	double getID(void) const { return m_nID; }
	//void setRad(double rad) { m_rad = rad; }
	// 함수명이 같을 수 있음; 입력 변수가 달라야 함 -> 다른 함수로 인식
	void setRad(double rad);
	void setRad(long nRad) { setRad((double)nRad); }
	void setCenter(double x, double y);
	void draw(char c);

private: // private 멤버(외부에서 접근 불가능) 정의: 클래스 내부 {...} 에서 접근 가능
	double m_rad = 0.; // 반지름 선언; m_(클래스의 멤버라는 뜻); = 0.: 반지름을 0으로 초기화
	double m_x = 0., m_y = 0.; // 중심 좌표
}; // 캡슐화: 멤버에 대한 접근이 가능 혹은 불가능하게 선택 가능; 정보 은닉

// 클래스 멤버를 명시: 클래스명::멤버명
inline void MyCircle::setRad(double rad) // 메소드를 헤더 파일에 정의할 때는 반드시 인라인 함수 정의
{
	m_rad = rad;
}
