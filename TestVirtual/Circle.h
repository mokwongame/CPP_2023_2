#pragma once

#include <cmath>
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(const PointD& pt, double rad)
	{
		m_pt = pt;
		m_rad = rad;
	}

	double getLen(void) const
	{
		// 3.14인 pi는 M_PI로 정의됨
		return 2. * M_PI * m_rad;
	}
	double getArea(void) const
	{
		return M_PI * m_rad * m_rad;
	}

private:
	double m_rad; // 반지름
};