#pragma once

#include <iostream>

// ++, --의 스텝을 임의대로 설정
class MyDouble // 코딩 스타일: Pascal case
{
public:
	MyDouble(double x = 0.)
	{
		setX(x);
	}
	// 복사 생성자
	MyDouble(const MyDouble& myDouble)
	{
		m_x = myDouble.m_x;
		m_step = myDouble.m_step;
	}

	double getX(void) const
	{
		return m_x;
	}
	void setX(double x)
	{
		m_x = x;
	}
	void setStep(double step)
	{
		m_step = step;
	}

	MyDouble& operator=(const MyDouble& myDouble)
	{
		m_x = myDouble.m_x;
		m_step = myDouble.m_step;
		// 현재 클래스(MyDouble)의 인스턴스 반환
		return *this; // this는 현재 인스턴스의 포인터; *this: 포인터의 값 -> 현재 인스턴스
	}
	MyDouble& operator++(void)
	{
		m_x += m_step; // m_x = m_x + m_step;
		return *this;
	}
	MyDouble operator++(int i) // i는 더미(dummy)
	{
		MyDouble tmp(*this); // 현재 인스턴스의 복사본을 tmp에 저장
		m_x += m_step; // m_x = m_x + m_step;
		return tmp;
	}
	MyDouble& operator--(void)
	{
		m_x -= m_step; // m_x = m_x + m_step;
		return *this;
	}

private:
	double m_x = 0.0; // double 저장값
	double m_step = 1.0; // 스텝
};

inline std::ostream& operator<<(std::ostream& stream, const MyDouble& myDouble)
{
	stream << myDouble.getX();
	return stream;
}