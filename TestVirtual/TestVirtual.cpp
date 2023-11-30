// TestVirtual.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Point.h"
#include "Shape.h"

int main()
{
	using namespace std;
	Point pt(1., 2.);
	cout << "(x, y) = " << pt << endl;

	Shape shape(3.4, 5.6);
	shape.move(-1., -5);
	cout << "shape = " << shape << endl;
}