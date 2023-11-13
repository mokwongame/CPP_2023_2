#pragma once

#include <vector>
#include "MovieData.h"

class MyMovieInfo
{
public:
	MyMovieInfo(void) {}
	~MyMovieInfo() {}

	void addData(const MovieData& movieData); // & �ǹ�: moveData�� ������ ����(���纻 ���� ������ ����); const �ǹ�: ���� �Լ����� movieData�� �������� ����
	void print(void) const;

private:
	std::vector<MovieData> m_data;
};

inline void MyMovieInfo::addData(const MovieData& movieData)
{
	m_data.push_back(movieData);
}

inline void MyMovieInfo::print(void) const
{
	//using namespace std; // ���� �ڵ� ��Ͽ����� std:: ���� ����
	for (const auto& movieData : m_data)
	{
		movieData.print();
		std::cout << std::endl << std::endl;
		//cout << endl << endl;
	}
}
