#pragma once // �� ��� ������ �� ����(once) ��(pragmatic) ���Խ�Ű��� ��
// ���ϸ�: MyCircle.h
// ��ü(object): ������ Ǯ�� ���� �ڵ� ����� �⺻ ����
// Ŭ����(class): ��ü�� ���赵
// �ǰ� ����: ���ϸ� == Ŭ������
// Ŭ�������� ���� �빮�ڷ� ����
class MyCircle // MyCircle�� Ŭ������
{
public: // public �׷�: �Ʒ� �ִ� ����� ��� public
	double m_rad = 0.; // ������(radius); ���ξ� m_�� ���(member)�� ǥ��; C ���ó�� �ʱ�ȭ

private: // private �׷�: �Ʒ� �ִ� ����� ��� private(Ŭ���� �ܺο��� ���� �Ұ�)

	double m_x = 0., m_y = 0.; // ���� �߽� ��ǥ; C ���ó�� �ʱ�ȭ
protected: // protected �׷�
};