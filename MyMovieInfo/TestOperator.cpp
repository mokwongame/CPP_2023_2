#include <iostream>
#include "MyDouble.h"

int main()
{
	using namespace std;
	MyDouble x(1.2);
	x.setStep(5.);
	cout << x << endl;
	MyDouble y;
	y = x;
	++y;
	y++;
	// fun(y) -> y�� ��; fun(++y) -> y+1�� ��; fun(y++) -> y�� ��
	cout << "y = " << y << endl;
	MyDouble z(y);
	--z;
	cout << "z = " << z << endl;
}