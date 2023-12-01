﻿// TestVirtual.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include "Point_template.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"

int main()
{
	using namespace std;
	Point<double> pt(1.5, 2.3);
	cout << "(x, y) = " << pt << endl;

	Point<int> pt2(2, -5);
	cout << "(x, y) = " << pt2 << endl;

	Shape shape(3.4, 5.6);
	shape.move(-1., -5);
	cout << "shape = " << shape << endl;
	cout << "shape len = " << shape.getLen() << endl;

	Line line(PointD(1., 2.), PointD(3., 4.));
	cout << "line len = " << line.getLen() << endl;
	cout << "line area = " << line.getArea() << endl;
}