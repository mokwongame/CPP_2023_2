// SnakeGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h> // Sleep이 선언된 운영 체제 함수를 위한 헤더 파일
#include "Wall.h"
#include "Fruit.h"
#include "Snake.h"

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

	x = randrange(1, 50); // 1, 2, ..., 49
	y = randrange(3, 22); // 3, 4, 5, ..., 21

	Snake snake;
	snake.setPt(Point2(x, y));
	snake.setShape('>', GREEN, BLUE);
	snake.draw();

	// 프레임 업데이트
	while (1)
	{
		// 사용자 입력
		SnakeDirType nDir;
		nDir = SnakeDirType::SDT_RIGHT;
		snake.setDir(nDir);
		// snake 이동
		snake.move();
		// 잠시 정지
		::Sleep(250); // 단위: msec; :: 의미 - 글로벌 네임스페이스(전역 함수, 전역 멤버)
	}
}