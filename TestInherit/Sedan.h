#pragma once

#include "Car.h"

class Sedan : public Car
{
public:
	Sedan(void);
	~Sedan() {}

	friend std::ostream& operator<<(std::ostream& stream, const Sedan& sedan);
private:
protected:
};

inline Sedan::Sedan(void)
{
	//m_brand.push_back("�ҳ�Ÿ");
	//m_brand.push_back("����");
	m_carInfos.push_back(CarInfo("�ҳ�Ÿ", 3000., 150.));
	m_carInfos.push_back(CarInfo("����", 6000., 200.));
	m_carInfos.push_back(CarInfo("K9", 5000., 190.));
}

inline std::ostream& operator<<(std::ostream& stream, const Sedan& sedan)
{
	using namespace std;
	stream << "[���� ����]" << endl;
	stream << "- �귣�� ���� = " << sedan.m_carInfos.size() << endl;
	stream << "----------------" << endl;
	for (const auto& carInfo : sedan.m_carInfos)
	{
		stream << carInfo << endl;
		stream << "----------------" << endl;
	}
	return stream;
}
