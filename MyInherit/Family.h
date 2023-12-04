#pragma once

#include "Person.h"

// Person 클래스를 부모 삼아서 Family 클래스를 정의
class Family : public Person // : 의미는 상속; Person을 public 접근(부모 클래스의 접근 권한을 그대로 유지)으로 상속
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
	std::string m_relation; // 가족 관계

protected:
	std::string m_home;	// 집 위치
};

std::ostream& operator<<(std::ostream& stream, const Family& family)
{
	using namespace std;
	stream << Person(family) << endl;
	stream << "관계 = " << family.getRelation();
	return stream;
}