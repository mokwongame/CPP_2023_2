#pragma once

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
	void draw(char c);

private: // private ���(�ܺο��� ���� �Ұ���) ����: Ŭ���� ���� {...} ���� ���� ����
	double m_rad = 0.; // ������ ����; m_(Ŭ������ ������ ��); = 0.: �������� 0���� �ʱ�ȭ
	double m_x = 0., m_y = 0.; // �߽� ��ǥ
}; // ĸ��ȭ: ����� ���� ������ ���� Ȥ�� �Ұ����ϰ� ���� ����; ���� ����

// Ŭ���� ����� ���: Ŭ������::�����
inline void MyCircle::setRad(double rad) // �޼ҵ带 ��� ���Ͽ� ������ ���� �ݵ�� �ζ��� �Լ� ����
{
	m_rad = rad;
}
