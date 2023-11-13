#pragma once

#include <string>

class MovieData
{
public:
	MovieData(void) {}
	~MovieData() {}

	// getter(획득자), setter(설정자)

private:
	std::string m_name; // 영화명
	double m_score = 0.; // 평점
	int m_year = 0; // 개봉연도
};