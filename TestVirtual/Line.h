#pragma once

//#include <math.h> // C 언어의 수학 함수
#include <cmath> // C++ 언어의 수학 함수
#include "Shape.h"

class Line : public Shape
{
public:
	Line(void) {}
	Line(const PointD& pt1, const PointD& pt2)
	{
		m_pt = pt1;
		m_pt2 = pt2;
	}

	// 부모와 자식 클래스의 함수 선언이 동일: 메소드 재정의(override)
	double getLen(void) const
	{
		double dx = m_pt2.getX() - m_pt.getX();
		double dy = m_pt2.getY() - m_pt.getY();
		return sqrt(dx * dx + dy * dy); // 제곱근 함수(square root)
	}

private:
	PointD m_pt2;
};