#pragma once

#include <iostream>
#include <math.h> // �ﰢ �Լ� ����
#include "MyCircle.h"
#include "LibConsole.hpp"

#define PI	(3.141592)

// �� �׸���: �߽� ��ǥ(x, y), ������(rad)
// class Ŭ������ {...};
class MyCircle // ���ϸ� == Ŭ������(������ �ǰ� ����)
{
	// ���� �����ڰ� ������ private ���
	int m_nID = 0;
	// public, private: ���� ������(access modifier)
	// ��� ����: ����, �Լ�, ������ ���, ����ü, ...
public: // public ���(�ܺο��� ���� ����) ����; : �ؿ� �ִ� �ڵ� ����� ������ �Լ��� ��� public; ���ο��� ���� ����
	// ��� ����: ������Ƽ(property) - ��ü�� ����, ���¸� ��Ÿ��
	// ��� �Լ�: �޼ҵ�(method) - ��ü�� ���, ���, ��ü�� �ൿ ���
	double getRad(void) const { return m_rad; } // const ������: ���� �޼ҵ尡 ������Ƽ�� �������� ����
	double getCenterX(void) const { return m_x; }
	double getCenterY(void) const { return m_y; }
	double getID(void) const { return m_nID; }
	//void setRad(double rad) { m_rad = rad; }
	// �Լ����� ���� �� ����; �Է� ������ �޶�� �� -> �ٸ� �Լ��� �ν�
	void setRad(double rad);
	void setRad(long nRad) { setRad((double)nRad); }
	void setCenter(double x, double y);
	void draw(char c) const;
	void print(void) const; // const �ǹ�: ������Ƽ�� �������� ����

private: // private ���(�ܺο��� ���� �Ұ���) ����: Ŭ���� ���� {...} ���� ���� ����
	double m_rad = 0.; // ������ ����; m_(Ŭ������ ������ ��); = 0.: �������� 0���� �ʱ�ȭ
	double m_x = 0., m_y = 0.; // �߽� ��ǥ
}; // ĸ��ȭ: ����� ���� ������ ���� Ȥ�� �Ұ����ϰ� ���� ����; ���� ����

// Ŭ���� ����� ���: Ŭ������::�����
inline void MyCircle::setRad(double rad) // �޼ҵ带 ��� ���Ͽ� ������ ���� �ݵ�� �ζ��� �Լ� ����
{
	m_rad = rad;
}

inline void MyCircle::setCenter(double x, double y)
{
	m_x = x, m_y = y; // ǥ���� 1��, ���� 2��
	//m_x = x; m_y = y; // ǥ���� 2��
}

// ��ũ�� ��ǥ��: ����(0, 0) - ���� ���; ���� �ϴ� �������� ���� x�� y ��ǥ�� Ŀ��
inline void MyCircle::draw(char c) const
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

inline void MyCircle::print(void) const
{
	using namespace std;
	cout << "radius = " << getRad() << "; x = " << getCenterX() << ", y = " << getCenterY() << endl;
}
