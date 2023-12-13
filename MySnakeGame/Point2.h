#pragma once

#include <iostream>

// ��ũ�� ��ǥ��
// - ����: ���� ��� (0, 0)
// - x�� Ư��:���ʿ��� �������� ���� ���� Ŀ�� ->
// - y�� Ư��: ������ �Ʒ��� ���� ���� Ŀ�� |v
// ��ǥ�� ������ ����

class Point2
{
public:
	Point2(void) {}
	Point2(int x, int y) { setPt(x, y); }
	Point2(const Point2& pt) { setPt(pt.m_x, pt.m_y); }

	int getX(void) const { return m_x; }
	int getY(void) const { return m_y; }
	void setPt(int x, int y) { m_x = x, m_y = y; }

	void move(int dx, int dy) // (dx, dy)��ŭ ���� ������ �̵�(move)
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