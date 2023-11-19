#pragma once

#include "Animal.h"

// Animal을 상속받아 Dog 클래스 만들기: Animal은 부모(super), Dog은 자식(sub)
class Dog : public Animal // : 의미는 상속받음
{
public:
	Dog(void)
	{
		m_food = "잡식성";
	}
	~Dog() {}

	// Animal에도 똑같은 메소드 선언(정의)이 있음: 메소드 재정의, 오버라이드(override)
	void print(void) const;
	// 메소드 중복, 오버로드(overload): 같은 이름 함수를 여러 개 정의(입력 변수는 달라야 함)
	void print(const std::string& home);

private:

protected:
};

inline void Dog::print(void) const
{
	using namespace std;
	// 부모 클래스의 print() 호출
	//Animal::print();
	__super::print();
	cout << m_food << endl;
}

inline void Dog::print(const std::string& home)
{
	using namespace std;
	m_home = home;
	print();
	cout << m_home << endl;
}
