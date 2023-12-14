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
	setParam("�Ǵ�", LifeType::LT_ANIMAL, "Ailuropoda melanoleuca", "����", "�߱� ��õ��");
	m_food = "�볪��";
	m_bPet = false;
	m_voice = "???";
}
