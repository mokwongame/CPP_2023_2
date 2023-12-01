#define _USE_MATH_DEFINES

#include <iostream>
#include "Point_template.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"

int main()
{
	using namespace std;
	// Shape�� �̿��ؼ� Line, Circle ��ɿ� ���� -> Shape�� �θ� Ŭ������ Line, Circle�� ��ǥ���� ������ ����
	Shape* ptr = nullptr; // null pointer
	ptr = new Line(PointD(1., 2.), PointD(3., 4.)); // upcasting(�ڽ� -> �θ�� ��ȯ)
	cout << "line len = " << ptr->getLen() << endl;
	cout << "line area = " << ptr->getArea() << endl;
	ptr->checkPt(PointD(2., 5.));
	ptr->checkPt(PointD(-2., 5.));
	delete ptr;

	// �������� ptr�� ������, �̹����� Circle �Ӽ��� ����
	ptr = new Circle(PointD(-5.4, 6.7), 2.4);
	cout << "circle len = " << ptr->getLen() << endl;
	cout << "circle area = " << ptr->getArea() << endl;
	delete ptr;

	// Rect ����� ����
}