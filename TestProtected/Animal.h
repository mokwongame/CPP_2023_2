#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	Animal(void) { std::cout << "Animal 생성자" << std::endl; }
	virtual ~Animal()
	{
		std::cout << "Animal 소멸자" << std::endl;
	}

	std::string getName(void) const { return m_name; }
	void setName(const std::string& name) { m_name = name; }

	void print(void) const;
	//virtual void speak(void) const { std::cout << "..." << std::endl; } // 가상 함수: 메소드 재정의가 없으면 이 함수가 호출; 자식에서 메소드가 재정의되면 이 함수가 아니고 자식 함수가 호출됨
	virtual void speak(void) const = 0; // 함수 정의(몸통)가 없고 함수 선언만 있음 -> 순수 가상 함수; 순수 가상 함수가 있는 클래스는 추상 클래스

private:
	std::string m_name;

protected:
	std::string m_food;
	std::string m_home;
};

inline void Animal::print(void) const
{
	using namespace std;
	cout << "이름 = " << getName() << endl;
}