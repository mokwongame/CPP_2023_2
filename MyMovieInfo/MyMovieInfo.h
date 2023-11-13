#pragma once

#include <vector>
#include "MovieData.h"

class MyMovieInfo
{
public:
	MyMovieInfo(void) {}
	~MyMovieInfo() {}

	void addData(const MovieData& movieData); // & 의미: moveData를 참조로 받음(복사본 없이 원본에 접근); const 의미: 현재 함수에서 movieData를 변경하지 않음
	void print(void) const;
	MovieData findDirector(const std::string director);

private:
	std::vector<MovieData> m_data;
};

inline void MyMovieInfo::addData(const MovieData& movieData)
{
	m_data.push_back(movieData);
}

inline void MyMovieInfo::print(void) const
{
	//using namespace std; // 현재 코드 블록에서만 std:: 생략 가능
	for (const auto& movieData : m_data)
	{
		movieData.print();
		std::cout << std::endl << std::endl;
		//cout << endl << endl;
	}
}

inline MovieData MyMovieInfo::findDirector(const std::string director)
{
	for (const auto& movieData : m_data)
	{
		if (movieData.getDirector() == director) // 검색 성공
			return movieData;
	}
	return MovieData();
}
