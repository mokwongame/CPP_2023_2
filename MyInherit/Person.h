#pragma once

#include <string>

// ĸ��ȭ: �ܺ� ����, ��� ����(�θ� ����� ����?)
// public: �ܺ� ���� ����, ��� ���� ����
// private: �ܺ� ���� �Ұ�, ��� ���� �Ұ�
// protected: �ܺ� ���� �Ұ�, ��� ���� ����

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

private: // �����̺� �׷�
	std::string m_name;

protected: // ������Ƽ�� �׷�
	std::string m_phoneNum;
};

std::ostream& operator<<(std::ostream& stream, const Person& person)
{
	stream << "�̸� = " << person.getName();
	return stream;
}