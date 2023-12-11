#pragma once

#include "Point2.h"
#include "LibConsole.hpp"
#include "LibGameTool.hpp"

class Fruit
{
public:
	Fruit(void) {}
	~Fruit() {}

	void setPt(const Point2& pt)
	{
		m_pt = pt;
	}
	void setShape(char ch, int nBack, int nText)
	{
		m_shape = ch;
		m_nBackCol = nBack, m_nTextCol = nText;
	}

	void draw(void);
	bool isHit(const Point2& pt);

private:
	Point2 m_pt;
	char m_shape = ' ';
	int m_nBackCol = mglib::BLACK, m_nTextCol = mglib::WHITE;
};

inline void Fruit::draw(void)
{
	using namespace std;
	using namespace mglib;
	setbacktextcol(m_nBackCol, m_nTextCol); // 배경색과 글자색을 함께 변경
	gotoxy(m_pt.getX(), m_pt.getY());
	cout << m_shape;
	setbacktextcol(BLACK, WHITE);
}

inline bool Fruit::isHit(const Point2& pt)
{
	return (pt.getX() == m_pt.getX()) && (pt.getY() == m_pt.getY());
}
