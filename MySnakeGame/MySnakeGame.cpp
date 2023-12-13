// MySnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 점 2개로 직사각형 정의: pt1(좌측 상단점), pt2(우측 하단점)
#define WALL_X1	(0)
#define WALL_Y1 (2)
#define WALL_X2	(80)
#define WALL_Y2 (29)

#include <iostream>
#include <Windows.h>
#include "Point2.h"
#include "Wall.h"
#include "Fruit.h"
#include "Snake.h"

int main()
{
	using namespace std;
	using namespace mglib;

	Point2 pt(2, 3);
	cout << pt << endl;
	pt.move(-5, 5);
	cout << pt << endl;

	Wall wall;
	wall.setRect(Point2(WALL_X1, WALL_Y1), Point2(WALL_X2, WALL_Y2));
	wall.setShape('=', BLUE, YELLOW);
	wall.draw();

	Fruit fruit;
	fruit.setPt(Point2(10, 20));
	fruit.setShape('O', RED, YELLOW);
	fruit.draw();

	Snake snake;
	snake.setPt(Point2(4, 5));
	snake.setShape('.', GREEN, BLUE);
	snake.draw();

	while (1)
	{
		::Sleep(200); // 단위: msec; :: 의미 - 전역 namespace
		snake.setDir(SnakeDirType::SDT_RIGHT);
		snake.move();
	}
}
