#pragma once

#include <string>
#include <iostream>

// ��ũ��(macro) ����
#define DEF_SPEED_STEP	(10.)

// public: �׻� ���� ����(�ܺ�, ���)
// private: �׻� ���� �Ұ�(�ܺ�, ���)
// protected: ���� �Ұ�(�ܺ�), ���� ����(���)
class Vehicle
{
public: // public �׷�
	Vehicle(void)
	{}
	~Vehicle()
	{}

	void speedUp(double step = DEF_SPEED_STEP)
	{
		m_speed += step;
	}
	void speedDown(double step = DEF_SPEED_STEP)
	{
		m_speed -= step;
	}
	double getSpeed(void) const // const �ǹ�: ���� �޼ҵ�� ������Ƽ�� �������� ����(���ó�� ó��)
	{
		return m_speed;
	}
	void setSpeed(double speed)
	{
		m_speed = speed;
	}
	double getPosX(void) const
	{
		return m_x;
	}
	double getPosY(void) const
	{
		return m_y;
	}
	void setPos(double x, double y)
	{
		m_x = x, m_y = y;
		//m_x = x; m_y = y;
	}

	std::string getName(void) const
	{
		return m_name;
	}
	void setName(const std::string& name) // & �ǹ�: ������(reference), ���纻 ������ �ʰ� ���� ����, ���������� ���� ó��; const �ǹ�: �Ʒ� �ڵ� ��Ͽ��� name�� �������� ����(����� ���)
	{
		m_name = name;
	}

private: // private �׷�
	double m_speed = 0.; // m_ �ǹ�: member
	std::string m_name;

protected: // protected �׷�
	// protected: ����ϱ� �������� private�� ����; ����ϸ� �ڽ� Ŭ�������� protected ����� ���� ����, private ����� ������ ���� �Ұ���
	double m_x = 0.;
	double m_y = 0.;
};

inline std::ostream& operator<<(std::ostream& stream, const Vehicle& vehicle)
{
	using namespace std;
	stream << "[Vehicle: " << vehicle.getName() << "]" << endl;
	stream << "�ӵ� = " << vehicle.getSpeed() << " km/h" << endl;
	stream << "���� ��ġ = (" << vehicle.getPosX() << ", " << vehicle.getPosY() << ")";
	return stream;
}

// #define�� ����(undefine)
#undef DEF_SPEED_STEP