#include <iostream>
#include "MyPoint.h"

int main()
{
	using namespace std;
	MyPoint pt1(-1, -2);
	cout << "pt1 = " << pt1 << endl;
	MyPoint pt2;
	//cout << "point 입력: ";
	//cin >> pt2;
	//cout << pt2 << endl;
	MyPoint pt3(pt1);
	cout << "pt3 = " << pt3 << endl;
	pt3 = pt1; // 할당 연산자가 정의되지 않으면 프로퍼티 전부를 복사
	cout << "pt3 = " << pt3 << endl;
	pt3 = pt1 + pt1;
	cout << "pt3 = " << pt3 << endl;
	MyPoint pt4 = pt1 - pt3;
	cout << "pt4 = " << pt4 << endl;
}