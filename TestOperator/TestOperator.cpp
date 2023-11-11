// TestOperator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "MyPoint.h"

int main()
{
	using namespace std;
	MyPoint pt1(1, 2);
	MyPoint pt2(3, 4);
	MyPoint pt3 = pt1.add(pt2);
	MyPoint pt4 = pt1 + pt2;
	pt3.print(); cout << endl;
	pt4.print(); cout << endl;
	cout << pt3[0] << endl;
	cout << pt4[1] << endl;
	MyPoint pt5 = pt1;
	pt2 = pt5 += pt4;
	cout << endl;
	cout << "pt5 = "; pt5.print(); cout << endl;
	cout << "pt2 = "; pt2.print(); cout << endl;

	MyPoint pt6 = pt1 - pt2;
	cout << "pt6 = "; pt6.print(); cout << endl;
}