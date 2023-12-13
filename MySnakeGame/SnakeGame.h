#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "LibGameTool.hpp"
#include "Wall.h"
#include "Fruit.h"
#include "Snake.h"

#define GAME_DELAY	(100)

class SnakeGame
{
public:
	SnakeGame(void);

	void play(void);

private:
	Wall m_wall;
	Fruit m_fruit;
	Snake m_snake;
	int m_nScore = 0;

	void initObj(void);
	void checkInput(void);
	void printScore(void);
	void makeFruit(void);
};

inline SnakeGame::SnakeGame(void)
{
	mglib::randseed();
	initObj();
	printScore();
}

inline void SnakeGame::play(void)
{
	using namespace std;
	using namespace mglib;

	while (1)
	{
		checkInput();
		m_snake.move();
		if (m_fruit.isHit(m_snake.getPt()))
		{
			m_nScore++;
			printScore();
			makeFruit();
		}
		else if (m_wall.isHit(m_snake.getPt()))
		{
			gotoxy(0, 0);
			cout << "Game Over!" << endl;
			break;
		}
		::Sleep(GAME_DELAY);
	}
}

inline void SnakeGame::initObj(void)
{
	using namespace mglib;

	m_wall.setRect(Point2(WALL_X1, WALL_Y1), Point2(WALL_X2, WALL_Y2));
	m_wall.setShape('=', BLUE, YELLOW);
	m_wall.draw();

	m_fruit.setRandPt();
	m_fruit.setShape('O', RED, YELLOW);
	m_fruit.draw();

	m_snake.setRandPt();
	m_snake.setShape('.', GREEN, BLUE);
	m_snake.draw();
}

inline void SnakeGame::checkInput(void)
{
	using namespace mglib;
	if (_kbhit()) // keyboard hit; 키보드가 눌러지면 true를 반환; 이 함수는 conio.h
	{
		int key = getkey(); // char도 가능하지만 함수키, 화살표 키를 받기 위해 int로 정의
		SnakeDirType nDir;
		switch (key)
		{
		case 'a': case IK_LEFT:
			nDir = SnakeDirType::SDT_LEFT;
			break;
		case 'd': case IK_RIGHT:
			nDir = SnakeDirType::SDT_RIGHT;
			break;
		case 'w': case IK_UP:
			nDir = SnakeDirType::SDT_UP;
			break;
		case 's': case IK_DOWN:
			nDir = SnakeDirType::SDT_DOWN;
			break;
		default: nDir = SnakeDirType::SDT_NULL;
		}
		if (nDir != SnakeDirType::SDT_NULL) m_snake.setDir(nDir);
	}
}

inline void SnakeGame::printScore(void)
{
	using namespace std;
	using namespace mglib;

	setbacktextcol(BLACK, WHITE);
	gotoxy(0, 0);
	cout << "점수 = " << m_nScore;
}

inline void SnakeGame::makeFruit(void)
{
	m_fruit.setRandPt();
	m_fruit.draw();
}
