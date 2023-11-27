#pragma once

#include <string>

// 캡슐화: 외부 접근, 상속 접근(부모 멤버에 접근?)
// public: 외부 접근 가능, 상속 접근 가능
// private: 외부 접근 불가, 상속 접근 불가
// protected: 외부 접근 불가, 상속 접근 가능

class Person
{
public:
	Person(void) {}
	~Person() {}

	std::string getName(void) const
	{
		return m_name;
	}
	void setName(std::string name)
	{
		m_name = name;
	}

private: // 프라이빗 그룹
	std::string m_name;

protected: // 프로텍티드 그룹
	std::string m_phoneNum;
};

std::ostream& operator<<(std::ostream& stream, const Person& person)
{
	stream << "이름 = " << person.getName();
	return stream;
}