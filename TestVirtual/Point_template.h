#pragma once

#include <iostream>

#define TEMP template<typename T>

TEMP class Point
{
public:
	Point(void) {}
	Point(T x, T y)
	{
		setPt(x, y);
	}

	T getX(void) const { return m_x; }
	T getY(void) const { return m_y; }
	void setPt(T x, T y)
	{
		m_x = x, m_y = y;
	}


private:
	T m_x, m_y;
};

TEMP inline std::ostream& operator<<(std::ostream& stream, const Point<T>& pt)
{
	stream << "(" << pt.getX() << ", " << pt.getY() << ")";
	return stream;
}

#undef TEMP