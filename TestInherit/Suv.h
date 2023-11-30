#pragma once

#include "Car.h"

class Suv : public Car
{
public:
	Suv(void);

	friend std::ostream& operator<<(std::ostream& stream, const Suv& sedan);
};

inline Suv::Suv(void)
{
	m_carInfos.push_back(CarInfo("Ƽ����", 2000., 140.));
	m_carInfos.push_back(CarInfo("���", 4000., 180.));
	m_carInfos.push_back(CarInfo("�Ӹ����̵�", 6000., 210.));
}

inline std::ostream& operator<<(std::ostream& stream, const Suv& sedan)
{
	using namespace std;
	stream << "[SUV ����]" << endl;
	stream << "- �귣�� ���� = " << sedan.m_carInfos.size() << endl;
	stream << "----------------" << endl;
	for (const auto& carInfo : sedan.m_carInfos)
	{
		stream << carInfo << endl;
		stream << "----------------" << endl;
	}
	return stream;
}