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
	// 메소드 정의 앞에 virtual을 쓰면 가상 함수가 됨
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