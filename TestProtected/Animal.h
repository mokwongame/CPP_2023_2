#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	Animal(void) { std::cout << "Animal ������" << std::endl; }
	virtual ~Animal()
	{
		std::cout << "Animal �Ҹ���" << std::endl;
	}

	std::string getName(void) const { return m_name; }
	void setName(const std::string& name) { m_name = name; }

	void print(void) const;
	//virtual void speak(void) const { std::cout << "..." << std::endl; } // ���� �Լ�: �޼ҵ� �����ǰ� ������ �� �Լ��� ȣ��; �ڽĿ��� �޼ҵ尡 �����ǵǸ� �� �Լ��� �ƴϰ� �ڽ� �Լ��� ȣ���
	virtual void speak(void) const = 0; // �Լ� ����(����)�� ���� �Լ� ���� ���� -> ���� ���� �Լ�; ���� ���� �Լ��� �ִ� Ŭ������ �߻� Ŭ����

private:
	std::string m_name;

protected:
	std::string m_food;
	std::string m_home;
};

inline void Animal::print(void) const
{
	using namespace std;
	cout << "�̸� = " << getName() << endl;
}