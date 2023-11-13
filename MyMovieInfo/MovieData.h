#pragma once

#include <string>
#include <iostream>

class MovieData
{
public:
	MovieData(void) {}
	~MovieData() {}

	// getter(ȹ����), setter(������)
	void setData(std::string name, std::string gendre, double score, int year, int times, std::string actor, std::string director);
	void print(void) const; // const �ǹ�: �� �޼ҵ�� ������Ƽ(����)�� �������� ����; ����θ� ó����

private:
	// ��ȭ��, ��������, �帣, ����, ����Ÿ��, �⿬��(1��), ����(1��)
	std::string m_name; // ��ȭ��
	std::string m_gendre; // �帣
	double m_score = 0.; // ����
	int m_year = 0; // ��������
	int m_times = 0; // ����Ÿ��
	std::string m_actor, m_director; // �⿬��, ����
};

// Ŭ���� ���� ���: Ŭ������::
inline void MovieData::setData(std::string name, std::string gendre, double score, int year, int times, std::string actor, std::string director)
{
	m_name = name;
	m_gendre = gendre;
	m_score = score;
	m_year = year;
	m_times = times;
	m_actor = actor;
	m_director = director;
}

inline void MovieData::print(void) const
{
}
