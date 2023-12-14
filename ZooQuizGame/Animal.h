#pragma once

#include "Life.h"

class Animal : public Life
{
public:
	Animal(void) {}
	Animal(const std::string& name, LifeType nType, const std::string& sciName, const std::string& family, const std::string& home) : Life(name, nType, sciName, family, home) {}

	std::string getFood(void) const { return m_food; }
	bool isPet(void) const { return m_bPet; }
	std::string getVoice(void) const { return m_voice; }

protected:
	std::string m_food;
	bool m_bPet = false;
	std::string m_voice;
};

inline std::ostream& operator<<(std::ostream& stream, const Animal& animal)
{
	using namespace std;
	stream << Life(animal) << endl;
	stream << " - ����: " << animal.getFood() << endl;
	stream << " - �ֿ� ����: " << ((animal.isPet()) ? "����" : "�ƴ�") << endl;
	stream << " - �����Ҹ�: " << animal.getVoice();
	return stream;
}