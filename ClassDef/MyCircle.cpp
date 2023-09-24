#include <iostream>
#include <math.h> // �ﰢ �Լ� ����
#include "MyCircle.h"
#include "LibConsole.hpp"

#define PI	(3.141592)

// �޼ҵ带 �ҽ� ���Ͽ� ������ ���� �Լ� ���� ���
//void MyCircle::setRad(double rad)
//{
//}

// �Լ� ����
void MyCircle::setCenter(double x, double y)
{
	m_x = x, m_y = y; // ǥ���� 1��, ���� 2��
	//m_x = x; m_y = y; // ǥ���� 2��
}

// ��ũ�� ��ǥ��: ����(0, 0) - ���� ���; ���� �ϴ� �������� ���� x�� y ��ǥ�� Ŀ��
void MyCircle::draw(char c)
{
	using namespace mglib;
	for (int i = 0; i < 360; i++) // i: ����
	{
		double rad = i * PI / 180.; // ���� -> ����
		double x = getRad() * cos(rad) + getCenterX(); // x ��ǥ: cos()
		double y = getRad() * sin(rad) + getCenterY(); // y ��ǥ: sin()
		int nX = int(x + 0.5); // �ݿø�
		//int nX = (int)(x + 0.5); // type casting(�ڷ��� ����): double -> int
		int nY = int(y + 0.5);
		gotoxy(nX, nY);
		std::cout << c;
	}
}
