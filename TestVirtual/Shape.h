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
	// �޼ҵ� ���� �տ� virtual�� ���̸� ���� �Լ��� ��
	virtual double getLen(void) const
	{
		return 0.;
	}
	virtual double getArea(void) const
	{
		return 0.;
	}

protected:
	PointD m_pt;
	// x�� �Ʒ� ���� ����� ���� ó��
	double m_xmin = 0.;
	double m_xmax = 10.;
	// y�� �Ʒ� ���� ����� ���� ó��
	double m_ymin = 0.;
	double m_ymax = 10.;
};

inline std::ostream& operator<<(std::ostream& stream, const Shape& shape)
{
	stream << shape.getPt();
	return stream;
}