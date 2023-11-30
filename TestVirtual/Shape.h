#pragma once

#include "Point.h"

class Shape
{
public:
	Shape(void) {}
	Shape(double x, double y)
	{
		m_pt.setPt(x, y);
	}
	Shape(const Point& pt)
	{
		m_pt = pt;
	}

	Point getPt(void) const { return m_pt; }
	// �޼ҵ� ���� �տ� virtual�� ���� ���� �Լ��� ��
	virtual void move(double dx, double dy)
	{
		Point pt(m_pt.getX() + dx, m_pt.getY() + dy);
		m_pt = pt;
	}

private:
	Point m_pt;
};

inline std::ostream& operator<<(std::ostream& stream, const Shape& shape)
{
	stream << shape.getPt();
	return stream;
}