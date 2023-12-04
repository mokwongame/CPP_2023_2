// SnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Wall.h"
#include "Fruit.h"

/* [스네이크 게임]
* 구성 요소: Wall, Snake, Fruit -> 객체(class) 구성
* 게임 엔진: SnakeGame
*/

int main()
{
	using namespace std;
	using namespace mglib;

	randseed();

	Point2 pt1(1, 2);
	cout << pt1 << endl;
	pt1.move(10, -5);
	cout << pt1 << endl;

	Wall wall;
	wall.setRect(Point2(0, 2), Point2(50, 22));
	wall.setShape('=', BLUE, YELLOW);
	wall.draw();

	int x = randrange(1, 50); // 1, 2, ..., 49
	int y = randrange(3, 22); // 3, 4, 5, ..., 21

	Fruit fruit;
	fruit.setPt(Point2(x, y));
	fruit.setShape('O', RED, YELLOW);
	fruit.draw();

	while (1) {}
}