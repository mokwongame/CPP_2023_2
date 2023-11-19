#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	Animal(void) {}
	~Animal() {}

	std::string getName(void) const { return m_name; }
	void setName(const std::string& name) { m_name = name; }

	void print(void) const;

private:
	std::string m_name;

protected:
	std::string m_food;
	std::string m_home;
};

inline void Animal::print(void) const
{
	using namespace std;
	cout << getName() << endl;
}