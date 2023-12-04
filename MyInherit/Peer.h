#pragma once

#include "Person.h"

class Peer : public Person
{
public:
	Peer(void) {}
	~Peer() {}

	std::string getCompany(void) const
	{
		return m_company;
	}
	void setCompany(const std::string& company)
	{
		m_company = company;
	}

private:
	std::string m_company;
	std::string m_job; // ����
};

std::ostream& operator<<(std::ostream& stream, const Peer& peer)
{
	using namespace std;
	stream << Person(peer) << endl;
	stream << "ȸ�� = " << peer.getCompany();
	return stream;
}