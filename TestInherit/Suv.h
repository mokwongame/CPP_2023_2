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
	m_carInfos.push_back(CarInfo("티볼리", 2000., 140.));
	m_carInfos.push_back(CarInfo("쏘렌토", 4000., 180.));
	m_carInfos.push_back(CarInfo("팰리세이드", 6000., 210.));
}

inline std::ostream& operator<<(std::ostream& stream, const Suv& sedan)
{
	using namespace std;
	stream << "[SUV 정보]" << endl;
	stream << "- 브랜드 개수 = " << sedan.m_carInfos.size() << endl;
	stream << "----------------" << endl;
	for (const auto& carInfo : sedan.m_carInfos)
	{
		stream << carInfo << endl;
		stream << "----------------" << endl;
	}
	return stream;
}