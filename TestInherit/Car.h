#pragma once

#include "Vehicle.h"

// public ���: ���� ������ �������
// protected ���: public  ��� -> protected ����� ����; �������� �״��
// private ���: public, protected ��� -> private ���; �������� �״��
// : �ǹ�: ��� �޴´ٴ� ��
class Car : public Vehicle
{
public:
	Car(void) {}
	~Car() {}

	// friend: ��� X, ���� ������Ƽ�� ���� ������ �޼ҵ�; � �޼ҵ���� friend ���� ���������� operator �ߺ����� �ַ� ���
	friend std::ostream& operator<<(std::ostream& stream, const Car& vehicle);

private:
	int m_nGear = 0;
	bool m_bBrake = true;
protected:
};

inline std::ostream& operator<<(std::ostream& stream, const Car& car)
{
	using namespace std;
	stream << "[Car: " << car.getName() << "]" << endl;
	stream << "�ӵ� = " << car.getSpeed() << " km/h" << endl;
	stream << "���� ��ġ = (" << car.getPosX() << ", " << car.getPosY() << ")" << endl;
	stream << "��� = " << car.m_nGear << "��" << endl;
	stream << "�극��ũ = " << ((car.m_bBrake) ? "�ɸ�" : "�Ȱɸ�");
	return stream;
}