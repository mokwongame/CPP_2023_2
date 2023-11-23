#pragma once

#include "Car.h"

class Sedan : public Car
{
public:
	Sedan(void);
	~Sedan() {}
private:
protected:
};

inline Sedan::Sedan(void)
{
	//m_brand.push_back("家唱鸥");
	//m_brand.push_back("亥明");
	m_carInfos.push_back(CarInfo("家唱鸥", 3000., 150.));
	m_carInfos.push_back(CarInfo("亥明", 6000., 200.));
	m_carInfos.push_back(CarInfo("K9", 5000., 190.));
}
