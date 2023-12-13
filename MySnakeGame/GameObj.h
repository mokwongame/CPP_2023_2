#pragma once

#include "LibConsole.hpp"
#include "Point2.h"

#define WALL_X1	(0)
#define WALL_Y1 (2)
#define WALL_X2	(80)
#define WALL_Y2 (29)

class GameObj
{
public:
	GameObj(void) {}

	Point2 getPt(void) const { return m_pt; }
	void setPt(const Point2& pt) { m_pt = pt; }
	void setRandPt(void);
	void setShape(char shape, int nBackCol, int nTextCol)
	{
		m_shape = shape;
		m_nBackCol = nBackCol;
		m_nTextCol = nTextCol;
	}

	void draw(void);
	void erase(void);
	bool isHit(const Point2& pt);

private:

protected:
	Point2 m_pt;
	char m_shape = ' ';
	int m_nBackCol = mglib::BLACK;
	int m_nTextCol = mglib::WHITE;
};

inline void GameObj::setRandPt(void)
{
	using namespace mglib;

	int x = randrange(WALL_X1 + 1, WALL_X2);
	int y = randrange(WALL_Y1 + 1, WALL_Y2);
	setPt(Point2(x, y));
}

inline void GameObj::draw(void)
{
	using namespace std;
	using namespace mglib;

	setbacktextcol(m_nBackCol, m_nTextCol);
	gotoxy(m_pt.getX(), m_pt.getY());
	cout << m_shape;
}

inline void GameObj::erase(void)
{
	using namespace std;
	using namespace mglib;

	setbacktextcol(mglib::BLACK, mglib::WHITE);
	gotoxy(m_pt.getX(), m_pt.getY());
	cout << ' ';
}

inline bool GameObj::isHit(const Point2& pt)
{
	return (pt.getX() == m_pt.getX()) && (pt.getY() == m_pt.getY());
}
