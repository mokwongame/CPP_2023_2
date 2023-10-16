#pragma once // �� ��� ������ �� ����(once) ��(pragmatic) ���Խ�Ű��� ��

#include <iostream>

// ���ϸ�: MyCircle.h
// ��ü(object): ������ Ǯ�� ���� �ڵ� ����� �⺻ ����
// Ŭ����(class): ��ü�� ���赵
// �ǰ� ����: ���ϸ� == Ŭ������
// Ŭ�������� ���� �빮�ڷ� ����
class MyCircle // MyCircle�� Ŭ������
{
public: // public �׷�: �Ʒ� �ִ� ����� ��� public
	// ��� �Լ�(method: �޼ҵ�, ���)�� ���� public �׷쿡 ����
	// ������Ƽ ȹ�� �Լ�(getter)
	double getRad(void) { return m_rad; } // �ζ��� �Լ��� ó��
	double getCenterX(void) { return m_x; }
	double getCenterY(void) { return m_y; }
	// ������Ƽ ���� �Լ�(setter)
	void setRad(double rad) { m_rad = rad; } // C ���� �����ϰ� ��� �Լ� ����; private ����� Ŭ���� �ȿ����� ���� ����
	void setCenter(double x, double y);

	void print(void);

private: // private �׷�: �Ʒ� �ִ� ����� ��� private(Ŭ���� �ܺο��� ���� �Ұ�)
	// ��� ����(property: ������Ƽ, ����, �Ӽ�)�� private �׷쿡 ����
	double m_rad = 0.; // ������(radius); ���ξ� m_�� ���(member)�� ǥ��; C ���ó�� �ʱ�ȭ
	double m_x = 0., m_y = 0.; // ���� �߽� ��ǥ; C ���ó�� �ʱ�ȭ
protected: // protected �׷�
};

inline void MyCircle::print(void)
{
	using namespace std;
	cout << "rad = " << getRad() << endl; // ���� Ŭ������ ����� ���� �����ϱ� ���� MyCircle:: ���� ����
	cout << "x = " << getCenterX() << endl; // m_x�� private ���
	cout << "y = " << getCenterY();
}