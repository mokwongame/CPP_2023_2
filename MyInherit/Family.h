#pragma once

#include "Person.h"

// Person Ŭ������ �θ� ��Ƽ� Family Ŭ������ ����
class Family : public Person // : �ǹ̴� ���; Person�� public ����(�θ� Ŭ������ ���� ������ �״�� ����)���� ���
{
public:
	Family(void) {}
	~Family() {}

	std::string getRelation(void) const
	{
		return m_relation;
	}

	void setRelation(std::string relation)
	{
		m_relation = relation;
		//m_phoneNum = "test 010";
	}

private:
	std::string m_relation; // ���� ����

protected:
	std::string m_home;	// �� ��ġ
};