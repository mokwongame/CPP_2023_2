#pragma once

#include "LibConsole.hpp"
#include "GameObj.h"

// 점 2개로 직사각형 정의: pt1(좌측 상단점), pt2(우측 하단점)
class Wall : public GameObj
{
public:
	Wall(void) {}

	void setRect(const Point2& pt1, const Point2& pt2)
	{
		m_pt = pt1;
		m_pt2 = pt2;
	}
	// GameObj의 draw() 메소드를 재정의(override)
	void draw(void);
	bool isHit(const Point2& pt);

private:
	Point2 m_pt2;	// m_pt1 == m_pt이므로 m_pt1을 생략
	//Point2 m_pt1, m_pt2;
};

inline void Wall::draw(void)
{
	using namespace std;
	using namespace mglib;
	setbacktextcol(m_nBackCol, m_nTextCol);
	for (int x = m_pt.getX(); x <= m_pt2.getX(); x++)
	{
		int y = m_pt.getY(); // 상단
		gotoxy(x, y);
		cout << m_shape;
		y = m_pt2.getY(); // 하단
		gotoxy(x, y);
		cout << m_shape;
	}

	for (int y = m_pt.getY() + 1; y <= m_pt2.getY() - 1; y++)
	{
		int x = m_pt.getX(); // 좌측
		gotoxy(x, y);
		cout << m_shape;
		x = m_pt2.getX(); // 우측
		gotoxy(x, y);
		cout << m_shape;
	}
}

inline bool Wall::isHit(const Point2& pt) // pt는 snake의 좌표
{
	return (pt.getX() <= m_pt.getX()) || (pt.getX() >= m_pt2.getX()) || (pt.getY() <= m_pt.getY()) || (pt.getY() >= m_pt2.getY());
}
