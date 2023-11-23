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
	//m_brand.push_back("소나타");
	//m_brand.push_back("벤츠");
	m_carInfos.push_back(CarInfo("소나타", 3000., 150.));
	m_carInfos.push_back(CarInfo("벤츠", 6000., 200.));
	m_carInfos.push_back(CarInfo("K9", 5000., 190.));
}

inline std::ostream& operator<<(std::ostream& stream, const Sedan& sedan)
{
	using namespace std;
	stream << "[세단 정보]" << endl;
	stream << "- 브랜드 개수 = " << sedan.m_carInfos.size() << endl;
	stream << "----------------" << endl;
	for (const auto& carInfo : sedan.m_carInfos)
	{
		stream << carInfo << endl;
		stream << "----------------" << endl;
	}
	return stream;
}
