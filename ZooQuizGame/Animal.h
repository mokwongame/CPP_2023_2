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

private:
	std::string m_food;
	bool m_bPet = false;
	std::string m_voice;
};

inline std::ostream& operator<<(std::ostream& stream, const Animal& animal)
{
	using namespace std;
	stream << Life(animal) << endl;
	stream << " - 먹이: " << animal.getFood() << endl;
	stream << " - 애완 동물: " << ((animal.isPet()) ? "맞음" : "아님") << endl;
	stream << " - 울음소리: " << animal.getVoice();
	return stream;
}