#pragma once

#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(void) {}
	~Cat(void) {}

	void speak(void) const { std::cout << "�߿�" << std::endl; }

private:
};