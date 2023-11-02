#pragma once

// ��ũ��(macro) ����
#define DEF_SPEED_STEP	(10.)

class Vehicle
{
public: // public �׷�
	Vehicle(void)
	{}
	~Vehicle()
	{}

	void speedUp(double step = DEF_SPEED_STEP)
	{
		speed += step;
	}

private: // private �׷�
	double speed = 0.;

protected: // protected �׷�
	// protected: ����ϱ� �������� private�� ����; ����ϸ� �ڽ� Ŭ�������� protected ����� ���� ����, private ����� ������ ���� �Ұ���
	double x = 0.;
	double y = 0.;
};

// #define�� ����(undefine)
#undef DEF_SPEED_STEP