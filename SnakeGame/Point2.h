#pragma once

#include <iostream>

// 2차원 좌표 점 (x, y)
class Point2
{
public:
	Point2(void) {}
	Point2(int x, int y)
	{
		setPt(x, y);
	}
	Point2(const Point2& pt) // 복사 생성자
	{
		setPt(pt);
	}
	~Point2() {}

	int getX(void) const { return m_x; }
	int getY(void) const { return m_y; }
	Point2 getPt(void) const { return Point2(m_x, m_y); }
	void setPt(int x, int y)
	{
		m_x = x, m_y = y;
	}
	void setPt(const Point2& pt)
	{
		m_x = pt.m_x, m_y = pt.m_y;
	}

	void move(int dx, int dy);

private:
	int m_x = 0, m_y = 0;
};

inline void Point2::move(int dx, int dy)
{
	m_x += dx;
	m_y += dy;
}

inline std::ostream& operator<<(std::ostream& stream, const Point2& pt)
{
	stream << "(" << pt.getX() << ", " << pt.getY() << ")";
	return stream;
}