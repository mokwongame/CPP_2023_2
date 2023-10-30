#include <iostream>
#include "MyCircle.h"

int main()
{
	using namespace std;
	double rad = 7;
	double x = 12;
	double y = 12;
	MyCircle circle(rad, x, y);
	circle.print();
	circle.draw('+');
	return 0;
}