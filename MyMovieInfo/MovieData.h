#pragma once

#include <string>

class MovieData
{
public:
	MovieData(void) {}
	~MovieData() {}

	// getter(ȹ����), setter(������)

private:
	std::string m_name; // ��ȭ��
	double m_score = 0.; // ����
	int m_year = 0; // ��������
};