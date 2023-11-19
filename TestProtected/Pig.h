#pragma once

#include "Animal.h"

class Pig : public Animal
{
public:
	Pig(void) {}
	~Pig(void) {}

	void speak(void) const { std::cout << "²Ü²Ü" << std::endl; }

private:
};