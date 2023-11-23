#pragma once

#include <iostream>
#include <string>

class CarInfo
{
public:
	CarInfo(void) {}
	CarInfo(const std::string& brand, double price, double maxSpeed)
	{
		setParam(brand, price, maxSpeed);
	}
	~CarInfo() {}

	std::string getBrand(void) const { return m_brand; }
	double getPrice(void) const { return m_price; }
	double getMaxSpeed(void) const {
		return m_maxSpeed;
	}
	void setParam(const std::string& brand, double price = 3000., double maxSpeed = 100.)
	{
		m_brand = brand;
		m_price = price;
		m_maxSpeed = maxSpeed;
	}

private:
	std::string m_brand;
	double m_price = 0.;
	double m_maxSpeed = 0.;
};