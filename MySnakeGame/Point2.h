#pragma once

#include <iostream>

// 스크린 좌표계
// - 원점: 왼쪽 상단 (0, 0)
// - x축 특성:왼쪽에서 오른쪽을 가면 값이 커짐 ->
// - y축 특성: 위에서 아래로 가면 값이 커짐 |v
// 좌표는 음수가 없음

class Point2
{
public:
	Point2(void) {}
	Point2(int x, int y) { setPt(x, y); }
	Point2(const Point2& pt) { setPt(pt.m_x, pt.m_y); }

	int getX(void) const { return m_x; }
	int getY(void) const { return m_y; }
	void setPt(int x, int y) { m_x = x, m_y = y; }

	void move(int dx, int dy) // (dx, dy)만큼 원래 값에서 이동(move)
	{
		m_x += dx;
		m_y += dy;
	}
	void move(const Point2& dpt)
	{
		move(dpt.m_x, dpt.m_y);
	}

private:
	int m_x = 0, m_y = 0;
};

std::ostream& operator<<(std::ostream& stream, const Point2& pt)
{
	stream << "(" << pt.getX() << ", " << pt.getY() << ")";
	return stream;
}