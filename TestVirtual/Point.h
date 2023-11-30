#pragma once

#include <iostream>

class Point
{
public:
	Point(void) {}
	Point(double x, double y)
	{
		setPt(x, y);
	}

	double getX(void) const { return m_x; }
	double getY(void) const { return m_y; }
	void setPt(double x, double y)
	{
		m_x = x, m_y = y;
	}


private:
	double m_x = 0., m_y = 0.;
};

inline std::ostream& operator<<(std::ostream& stream, const Point& pt)
{
	stream << "(" << pt.getX() << ", " << pt.getY() << ")";
	return stream;
}