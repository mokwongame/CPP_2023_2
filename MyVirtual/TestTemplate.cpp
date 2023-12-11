#include <iostream>
#include "Point2Template.h"

int main()
{
	using namespace std;

	// ���� ó��: try-catch
	try // �츮�� ������ �ڵ�
	{
		Point2<int> pt1;
		pt1.setPt(0, 0);
		pt1.move(-2, -3);
		cout << pt1 << endl;
		if (pt1.getX() < 0 || pt1.getY() < 0)
		{
			int i = pt1.getX();
			throw i; // ���ܰ� �߻��� ��쿡 i�� ����(throw)
		}

		Point2<double> pt2;
		pt2.setPt(0., 0.);
		pt2.move(2.7, 3.7);
		cout << pt2 << endl;
	}
	catch (int e) // ����(exception)�� �ޱ�
	{
		cout << "���� " << e << "�� ����" << endl;
	}
}