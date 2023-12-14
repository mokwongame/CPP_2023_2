#pragma once

#include "Animal.h"

// Life -> Animal -> Panda
class Panda : public Animal
{
public:
	Panda(void);
private:
};

inline Panda::Panda(void)
{
	setParam("판다", LifeType::LT_ANIMAL, "Ailuropoda melanoleuca", "곰과", "중국 사천성");
	m_food = "대나무";
	m_bPet = false;
	m_voice = "???";
}
