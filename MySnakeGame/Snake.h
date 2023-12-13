#pragma once

#include "GameObj.h"

enum class SnakeDirType
{
	SDT_NULL = 0, SDT_LEFT, SDT_RIGHT, SDT_UP, SDT_DOWN
};

class Snake : public GameObj
{
public:
	Snake(void) {}

	SnakeDirType getDir(void) const { return m_nDir; }
	void setDir(SnakeDirType nDir) { m_nDir = nDir; }

	void move(void);

private:
	SnakeDirType m_nDir = SnakeDirType::SDT_NULL;

	void movePt(void);
};

inline void Snake::move(void)
{
	erase();
	movePt();
	draw();
}

inline void Snake::movePt(void)
{
	switch (m_nDir)
	{
	case SnakeDirType::SDT_LEFT:
		m_pt.move(-1, 0);
		m_shape = '<';
		break;
	case SnakeDirType::SDT_RIGHT:
		m_pt.move(1, 0);
		m_shape = '>';
		break;
	case SnakeDirType::SDT_UP:
		m_pt.move(0, -1);
		m_shape = '^';
		break;
	case SnakeDirType::SDT_DOWN:
		m_pt.move(0, 1);
		m_shape = 'v';
		break;
	}
}
