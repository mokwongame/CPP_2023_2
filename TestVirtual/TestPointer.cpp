#define _USE_MATH_DEFINES

#include <iostream>
#include "Point_template.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"

int main()
{
	using namespace std;
	// Shape을 이용해서 Line, Circle 기능에 접근 -> Shape은 부모 클래스라서 Line, Circle의 대표성을 가지고 있음
	Shape* ptr = nullptr; // null pointer
	ptr = new Line(PointD(1., 2.), PointD(3., 4.)); // upcasting(자식 -> 부모로 변환)
	cout << "line len = " << ptr->getLen() << endl;
	cout << "line area = " << ptr->getArea() << endl;
	delete ptr;

	// 변수명은 ptr로 같지만, 이번에는 Circle 속성을 가짐
	ptr = new Circle(PointD(-5.4, 6.7), 2.4);
	cout << "circle len = " << ptr->getLen() << endl;
	cout << "circle area = " << ptr->getArea() << endl;
	delete ptr;
}