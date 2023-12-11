#pragma once

#include <iostream>
#include "Point2.h"
#include "LibConsole.hpp"

// �㺭��: ��ǥ ��(Point2) 2���� �ʿ�
// ��ũ�� ��ǥ���� ����: ���� ����� (0, 0)
class Wall
{
public:
	Wall(void) {}
	~Wall() {}

	// ���簢���� �׸��� ���� ��ǥ �� 2��
	void setRect(const Point2& pt1, const Point2& pt2)
	{
		m_pt1 = pt1, m_pt2 = pt2;
	}
	void setShape(char ch, int nBack, int nText)
	{
		m_shape = ch;
		m_nBackCol = nBack, m_nTextCol = nText;
	}

	void draw(void);
	bool isHit(const Point2& pt);

private:
	Point2 m_pt1, m_pt2; // m_pt1: ���� ���, m_pt2: ���� �ϴ�
	char m_shape = ' ';
	int m_nBackCol = mglib::BLACK, m_nTextCol = mglib::WHITE;
};

inline void Wall::draw(void)
{
	using namespace std;
	using namespace mglib;
	setbacktextcol(m_nBackCol, m_nTextCol); // ������ ���ڻ��� �Բ� ����
	// ���� �� �׸���
	for (int i = m_pt1.getX(); i <= m_pt2.getX(); i++)
	{
		int y = m_pt1.getY();
		gotoxy(i, y);
		cout << m_shape;
		y = m_pt2.getY();
		gotoxy(i, y);
		cout << m_shape;
	}
	// ���� �� �׸���
	for (int j = m_pt1.getY() + 1; j <= m_pt2.getY() - 1; j++)
	{
		int x = m_pt1.getX();
		gotoxy(x, j);
		cout << m_shape;
		x = m_pt2.getX();
		gotoxy(x, j);
		cout << m_shape;
	}
	setbacktextcol(BLACK, WHITE);
}

inline bool Wall::isHit(const Point2& pt)
{
	return (pt.getX() <= m_pt1.getX()) || (pt.getX() >= m_pt2.getX()) || (pt.getY() <= m_pt1.getY()) || (pt.getY() >= m_pt2.getY());
}
