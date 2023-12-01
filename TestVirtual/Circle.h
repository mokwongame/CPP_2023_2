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

	virtual double getLen(void) const
	{
		// 3.14�� pi�� M_PI�� ���ǵ�
		return 2. * M_PI * m_rad;
	}
	virtual double getArea(void) const
	{
		return M_PI * m_rad * m_rad;
	}

private:
	double m_rad; // ������
};