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
	m_brand.push_back("�ҳ�Ÿ");
	m_brand.push_back("����");
}
