#pragma once

#include <iostream>

class MyPoint
{
public:
	MyPoint(void) {}
	MyPoint(double x, double y = 0.) { setXy(x, y); }
	MyPoint(const MyPoint& pt); // 복사 생성자: 자기 자신 클래스으로 현재 인스턴스를 초기화; 복사 생성자가 없으면 기본 복사 생성자가 호출됨(프로퍼티를 전부 복사)
	~MyPoint() {}

	double getX(void) const { return m_x; }
	double getY(void) const { return m_y; }
	void setXy(double x, double y) { m_x = x, m_y = y; }
	void print(void) const;
	MyPoint add(const MyPoint& pt); // const 의미: pt를 변경하지 않음; & 의미: 복사본 없이 pt 원본에 접근해서 처리

	// 연산자 중복, 오버로딩(overloading): 반환형 operator연산기호(입력 변수) {...}
	// 일항 연산자: 입력이 1개
	MyPoint operator+(const MyPoint& pt);
	MyPoint& operator+=(const MyPoint& pt);
	MyPoint& operator=(const MyPoint& pt); // 이 연산자 중복이 없으면 기본 할당 연산자가 동작함(프로퍼티를 전부 복사)
	double& operator[](int nPos); // nPos == 0, x좌표; nPos == 1, y좌표

	// 이항 연산자: 입력이 2개
	// 프렌드 의미: 멤버는 아니지만 private 프로퍼티에 접근이 가능한 메소드
	// friend는 가능하지 쓰지 않음; 특별한 경우(이항 연산자 정의처럼)는 사용
	friend MyPoint operator-(const MyPoint& pt1, const MyPoint& pt2);
	friend std::ostream& operator<<(std::ostream& stream, const MyPoint& pt);
	friend std::istream& operator>>(std::istream& stream, MyPoint& pt);

private:
	// 2차원 좌표: (x, y)
	double m_x = 0.;
	double m_y = 0.;
};

inline MyPoint::MyPoint(const MyPoint& pt)
{
	m_x = pt.m_x;
	m_y = pt.m_y;
	std::cout << "복사: " << *this << std::endl;
}

inline void MyPoint::print(void) const
{
	using namespace std;
	cout << "(" << getX() << ", " << getY() << ")";
}

inline MyPoint MyPoint::add(const MyPoint& pt)
{
	MyPoint result(m_x + pt.m_x, m_y + pt.m_y);
	return result;
}

inline MyPoint MyPoint::operator+(const MyPoint& pt)
{
	MyPoint result(m_x + pt.m_x, m_y + pt.m_y);
	return result;
}

// MyPoint& 의미: 반환할 때 복사본이 아닌 원본 접근 위치(reference, 참조자)를 반환
inline MyPoint& MyPoint::operator+=(const MyPoint& pt)
{
	m_x += pt.m_x; // m_x = m_x + pt.m_x
	m_y += pt.m_y; // m_y = m_y + pt.m_y
	return (*this); // this: 현재 인스턴스의 포인터; *this: this가 가리키는 값 == 현재 인스턴스
}

inline MyPoint& MyPoint::operator=(const MyPoint& pt)
{
	m_x = pt.m_x;
	m_y = pt.m_y;
	std::cout << "할당: " << *this << std::endl;
	return *this;
}

// double& 의미: 반환할 때 복사본이 아닌 원본 접근 위치(reference, 참조자)를 반환
inline double& MyPoint::operator[](int nPos)
{
	if (nPos == 0) return m_x;
	else if (nPos == 1) return m_y;
	else
	{
		std::cout << "잘못된 index: " << nPos << std::endl;
		return m_x;
	}
}

// MyPoint의 friend라서 private 프로퍼티에 접근 가능
inline MyPoint operator-(const MyPoint& pt1, const MyPoint& pt2)
{
	return MyPoint(pt1.m_x - pt2.m_x, pt1.m_y - pt2.m_y);
}

inline std::istream& operator>>(std::istream& stream, MyPoint& pt)
{
	stream >> pt.m_x >> pt.m_y;
	if (!stream) // 입력 받은 후에 stream이 0이 아니면 에러 발생
	{
		pt = MyPoint(0., 0.);
	}
	return stream;
}

// ostream: cout, file까지 모두 포함한 출력 스트림
inline std::ostream& operator<<(std::ostream& stream, const MyPoint& pt)
{
	using namespace std;
	//cout << "(" << pt.m_x << ", " << pt.m_y << ")"; // friend이어야만 private 멤버에 접근 가능
	cout << "(" << pt.getX() << ", " << pt.getY() << ")";
	return stream;
}
