#include <iostream>
#include "Point2Template.h"

int main()
{
	using namespace std;

	// 예외 처리: try-catch
	try // 우리가 실행할 코드
	{
		Point2<int> pt1;
		pt1.setPt(0, 0);
		pt1.move(-2, -3);
		cout << pt1 << endl;
		if (pt1.getX() < 0 || pt1.getY() < 0)
		{
			int i = pt1.getX();
			throw i; // 예외가 발생할 경우에 i를 던짐(throw)
		}

		Point2<double> pt2;
		pt2.setPt(0., 0.);
		pt2.move(2.7, 3.7);
		cout << pt2 << endl;
	}
	catch (int e) // 예외(exception)를 받기
	{
		cout << "정수 " << e << "를 받음" << endl;
	}
}