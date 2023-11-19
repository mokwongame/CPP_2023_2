#pragma once

#include "Animal.h"

// Animal�� ��ӹ޾� Dog Ŭ���� �����: Animal�� �θ�(super), Dog�� �ڽ�(sub)
class Dog : public Animal // : �ǹ̴� ��ӹ���
{
public:
	Dog(void)
	{
		m_food = "��ļ�";
	}
	~Dog() {}

	// Animal���� �Ȱ��� �޼ҵ� ����(����)�� ����: �޼ҵ� ������, �������̵�(override)
	void print(void) const;
	// �޼ҵ� �ߺ�, �����ε�(overload): ���� �̸� �Լ��� ���� �� ����(�Է� ������ �޶�� ��)
	void print(const std::string& home);

private:

protected:
};

inline void Dog::print(void) const
{
	using namespace std;
	// �θ� Ŭ������ print() ȣ��
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
