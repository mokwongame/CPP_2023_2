#pragma once

#include <iostream>
#include "Point2.h"
#include "LibConsole.hpp"

// 담벼락: 좌표 점(Point2) 2개가 필요
// 스크린 좌표계의 원점: 왼쪽 상단이 (0, 0)
class Wall
{
public:
	Wall(void) {}
	~Wall() {}

	// 직사각형을 그리기 위한 좌표 점 2개
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

private:
	Point2 m_pt1, m_pt2; // m_pt1: 좌측 상단, m_pt2: 우측 하단
	char m_shape = ' ';
	int m_nBackCol = mglib::BLACK, m_nTextCol = mglib::WHITE;
};

inline void Wall::draw(void)
{
	using namespace std;
	using namespace mglib;
	setbacktextcol(m_nBackCol, m_nTextCol); // 배경색과 글자색을 함께 변경
	// 가로 줄 그리기
	for (int i = m_pt1.getX(); i <= m_pt2.getX(); i++)
	{
		int y = m_pt1.getY();
		gotoxy(i, y);
		cout << m_shape;
		y = m_pt2.getY();
		gotoxy(i, y);
		cout << m_shape;
	}
	// 세로 줄 그리기
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