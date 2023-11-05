#pragma once // �� ��� ������ �� ����(once) ��(pragmatic) ���Խ�Ű��� ��

#include <iostream>
#include "LibConsole.hpp"

#define PI	(3.141592) // ������

// ���ϸ�: MyCircle.h
// ��ü(object): ������ Ǯ�� ���� �ڵ� ������ �⺻ ����
// Ŭ����(class): ��ü�� ���赵
// �ǰ� ����: ���ϸ� == Ŭ������
// Ŭ�������� ���� �빮�ڷ� ����
class MyCircle // MyCircle�� Ŭ������
{
public: // public �׷�: �Ʒ� �ִ� ����� ��� public
	// ��� �Լ�(method: �޼ҵ�, ���)�� ���� public �׷쿡 ����
	// ������(constructor): �޼ҵ�� == Ŭ������; Ŭ������ ������ ��(�ν��Ͻ��� ������� ��) �ڵ������� ȣ��Ǵ� �޼ҵ�(��� �Լ�); ��ȯ�ϴ� �ڷ����� �� �� ����; Ŭ������ ���� ���� �⺻���� �ʱ�ȭ ����
	MyCircle(void)
	{
		//std::cout << "������(void) ȣ��" << std::endl;
	}
	MyCircle(double rad, double x, double y)
	{
		//std::cout << "������(rad, x, y) ȣ��" << std::endl;
		setRad(rad); // m_rad = rad; ��� �޼ҵ� ȣ��(�ϰ��� ����)
		setCenter(x, y);
	}
	MyCircle(double rad) : // �������� �ʱ�ȭ ����Ʈ
		m_rad(rad) // m_rad = rad
	{
		//std::cout << "������(rad) ȣ��" << std::endl;
	}
	MyCircle(double x, double y) : // �������� �ʱ�ȭ ����Ʈ
		m_x(x),
		m_y(y)
	{
		//std::cout << "������(x, y) ȣ��" << std::endl;
	}
	// �Ҹ���, �ı���(destructor): �޼ҵ�� == ~Ŭ������; �ν��Ͻ��� �Ҹ�� �� �ڵ������� ȣ��; �Է� �ڷ��� X, ��� �ڷ��� X; �޸� ������ �� �ַ� ���
	~MyCircle()
	{
		//std::cout << "�Ҹ��� ȣ��" << std::endl;
	}
	// ������Ƽ ȹ�� �Լ�(getter)
	double getRad(void) const { return m_rad; } // �ζ��� �Լ��� ó��; �Լ� ����� ���� �� const(���) �ǹ�: �� �Լ��� ��� ������ �������� ����(���� ����)
	double getCenterX(void) const { return m_x; }
	double getCenterY(void) const { return m_y; }
	double getArea(void) const;

	// ������Ƽ ���� �Լ�(setter)
	//void setRad(double rad)
	void setRad(double rad = 1.0) // �Է��� ������ �⺻������ 1�� �Է�
	{
		//std::cout << "double �Է� " << std::endl;
		m_rad = rad;
	} // C ���� �����ϰ� ��� �Լ� ����; private ����� Ŭ���� �ȿ����� ���� ����
	void setRad(int nRad)
	{
		//std::cout << "int �Է�" << std::endl;
		m_rad = nRad;
	}
	void setCenter(double x = 0., double y = 0.);

	void print(void) const;
	void draw(char mark = '*', int nTextColor = mglib::WHITE, int nBackColor = mglib::BLACK) const; // �Լ��� ����Ʈ���� '*'�� ����

private: // private �׷�: �Ʒ� �ִ� ����� ��� private(Ŭ���� �ܺο��� ���� �Ұ�)
	// ��� ����(property: ������Ƽ, ����, �Ӽ�)�� private �׷쿡 ����
	double m_rad = 0.; // ������(radius); ���ξ� m_�� ���(member)�� ǥ��; C ���ó�� �ʱ�ȭ
	double m_x = 0., m_y = 0.; // ���� �߽� ��ǥ; C ���ó�� �ʱ�ȭ
protected: // protected �׷�
};

inline void MyCircle::print(void) const
{
	using namespace std;
	cout << "rad = " << getRad() << endl; // ���� Ŭ������ ����� ���� �����ϱ� ���� MyCircle:: ���� ����
	cout << "x = " << getCenterX() << endl; // m_x�� private ���
	cout << "y = " << getCenterY();
}

inline void MyCircle::draw(char mark, int nTextColor, int nBackColor) const
{
	// using namespace mglib
	// ���� x ��ǥ = rad*cos(theta) + x0; x0�� �߽��� x ��ǥ
	// ���� y ��ǥ = rad*sin(theta) + y0; y0�� �߽��� y ��ǥ
	mglib::settextcol(nTextColor);
	mglib::setbackcol(nBackColor);
	for (int i = 0; i < 360; i++) // i�� 360�� ���� ����
	{
		double ang = i / 180. * PI; // ���� -> ����
		double x = getRad() * cos(ang) + getCenterX();
		double y = getRad() * sin(ang) + getCenterY();
		int nX = int(x + 0.5); // �ݿø�
		int nY = int(y + 0.5); // �ݿø�
		mglib::gotoxy(nX, nY);
		std::cout << mark;
	}
	mglib::settextcol(mglib::WHITE);
	mglib::setbackcol(mglib::BLACK);
}

inline double MyCircle::getArea(void) const
{
	return PI * getRad() * getRad();
}