#pragma once

#include "Point2.h"
#include "LibConsole.hpp"
#include "LibGameTool.hpp"

enum class SnakeDirType
{
	SDT_NULL = 0, SDT_LEFT, SDT_RIGHT, SDT_UP, SDT_DOWN
};

class Snake
{
public:
	Snake(void) {}
	~Snake() {}

	Point2 getPt(void) const
	{
		return m_pt;
	}
	void setPt(const Point2& pt)
	{
		m_pt = pt;
	}
	void setShape(char ch, int nBack, int nText)
	{
		m_shape = ch;
		m_nBackCol = nBack, m_nTextCol = nText;
	}
	void setDir(SnakeDirType nDir)
	{
		m_nDir = nDir;
	}

	void draw(void);
	void clear(void);
	void move(void);

private:
	Point2 m_pt;
	char m_shape = ' ';
	int m_nBackCol = mglib::BLACK, m_nTextCol = mglib::WHITE;
	SnakeDirType m_nDir = SnakeDirType::SDT_NULL;
};

inline void Snake::draw(void)
{
	using namespace std;
	using namespace mglib;
	setbacktextcol(m_nBackCol, m_nTextCol); // 배경색과 글자색을 함께 변경
	gotoxy(m_pt.getX(), m_pt.getY());
	cout << m_shape;
	setbacktextcol(BLACK, WHITE);
}

inline void Snake::clear(void)
{
	using namespace std;
	using namespace mglib;

	setbacktextcol(BLACK, WHITE);
	gotoxy(m_pt.getX(), m_pt.getY());
	cout << ' '; // 원래 배경 그리기
}

inline void Snake::move(void)
{
	if (m_nDir == SnakeDirType::SDT_NULL) return;
	clear();
	switch (m_nDir)
	{
	case SnakeDirType::SDT_LEFT:
		m_pt.move(-1, 0);
		break;
	case SnakeDirType::SDT_RIGHT:
		m_pt.move(1, 0);
		break;
	case SnakeDirType::SDT_UP:
		m_pt.move(0, -1);
		break;
	case SnakeDirType::SDT_DOWN:
		m_pt.move(0, 1);
		break;
	}
	draw();
}
