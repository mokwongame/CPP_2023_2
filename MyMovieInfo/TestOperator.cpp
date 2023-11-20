#include <iostream>
#include "MyDouble.h"

int main()
{
	using namespace std;
	MyDouble x(1.2);
	cout << x << endl;
	MyDouble y;
	y = x;
	cout << "y = " << y << endl;
}