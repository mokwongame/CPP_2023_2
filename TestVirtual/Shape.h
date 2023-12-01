#pragma once

#include "Point_template.h"

typedef Point<double> PointD; // Point<double> ��� �������� PointD�� ���

class Shape
{
public:
	Shape(void) {}
	Shape(double x, double y)
	{
		m_pt.setPt(x, y);
	}
	Shape(const PointD& pt)
	{
		m_pt = pt;
	}

	PointD getPt(void) const { return m_pt; }
	// �޼ҵ� ���� �տ� virtual�� ���� ���� �Լ��� ��
	virtual void move(double dx, double dy)
	{
		PointD pt(m_pt.getX() + dx, m_pt.getY() + dy);
		m_pt = pt;
	}
	double getLen(void) const
	{
		return 0.;
	}
	double getArea(void) const
	{
		return 0.;
	}

protected:
	PointD m_pt;
};

inline std::ostream& operator<<(std::ostream& stream, const Shape& shape)
{
	stream << shape.getPt();
	return stream;
}