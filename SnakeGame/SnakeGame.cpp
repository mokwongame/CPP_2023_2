// SnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Wall.h"

/* [스네이크 게임]
* 구성 요소: Wall, Snake, Fruit -> 객체(class) 구성
* 게임 엔진: SnakeGame
*/

int main()
{
	using namespace std;
	using namespace mglib;

	Point2 pt1(1, 2);
	cout << pt1 << endl;
	pt1.move(10, -5);
	cout << pt1 << endl;

	Wall wall;
	wall.setRect(Point2(0, 2), Point2(50, 22));
	wall.setShape('=', BLUE, YELLOW);
	wall.draw();

	while (1) {}
}