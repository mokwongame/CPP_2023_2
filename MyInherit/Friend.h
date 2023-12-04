#pragma once

#include "Person.h"

class Friend : public Person
{
public:
	Friend(void) {}
	~Friend() {}

	std::string getSchool(void) const { return m_school; }
	void setSchool(const std::string& school)
	{
		m_school = school;
	}

private:
	std::string m_school;
	std::string m_hobby;
};

std::ostream& operator<<(std::ostream& stream, const Friend& buddy)
{
	using namespace std;
	stream << Person(buddy) << endl;
	stream << "ÇÐ±³ = " << buddy.getSchool();
	return stream;
}