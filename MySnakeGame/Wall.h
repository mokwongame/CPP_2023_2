#pragma once

#include "LibConsole.hpp"
#include "GameObj.h"

// �� 2���� ���簢�� ����: pt1(���� �����), pt2(���� �ϴ���)
class Wall : public GameObj
{
public:
	Wall(void) {}

	void setRect(const Point2& pt1, const Point2& pt2)
	{
		m_pt = pt1;
		m_pt2 = pt2;
	}
	// GameObj�� draw() �޼ҵ带 ������(override)
	void draw(void);
	bool isHit(const Point2& pt);

private:
	Point2 m_pt2;	// m_pt1 == m_pt�̹Ƿ� m_pt1�� ����
	//Point2 m_pt1, m_pt2;
};

inline void Wall::draw(void)
{
	using namespace std;
	using namespace mglib;
	setbacktextcol(m_nBackCol, m_nTextCol);
	for (int x = m_pt.getX(); x <= m_pt2.getX(); x++)
	{
		int y = m_pt.getY(); // ���
		gotoxy(x, y);
		cout << m_shape;
		y = m_pt2.getY(); // �ϴ�
		gotoxy(x, y);
		cout << m_shape;
	}

	for (int y = m_pt.getY() + 1; y <= m_pt2.getY() - 1; y++)
	{
		int x = m_pt.getX(); // ����
		gotoxy(x, y);
		cout << m_shape;
		x = m_pt2.getX(); // ����
		gotoxy(x, y);
		cout << m_shape;
	}
}

inline bool Wall::isHit(const Point2& pt) // pt�� snake�� ��ǥ
{
	return (pt.getX() <= m_pt.getX()) || (pt.getX() >= m_pt2.getX()) || (pt.getY() <= m_pt.getY()) || (pt.getY() >= m_pt2.getY());
}
