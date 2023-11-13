#pragma once

#include <string>
#include <iostream>

class MovieData
{
public:
	MovieData(void) {}
	~MovieData() {}

	// getter(획득자), setter(설정자)
	std::string getDirector(void) const
	{
		return m_director;
	}
	void setData(std::string name, std::string gendre, double score, int year, int times, std::string actor, std::string director);
	void print(void) const; // const 의미: 이 메소드는 프로퍼티(변수)를 변경하지 않음; 상수로만 처리함

private:
	// 영화명, 개봉연도, 장르, 평점, 러닝타임, 출연진(1명), 감독(1명)
	std::string m_name; // 영화명
	std::string m_gendre; // 장르
	double m_score = 0.; // 평점
	int m_year = 0; // 개봉연도
	int m_times = 0; // 러닝타임
	std::string m_actor, m_director; // 출연진, 감독
};

// 클래스 접근 방법: 클래스명::
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
	using namespace std;
	// 영화명, 개봉연도, 장르, 평점, 러닝타임, 출연진(1명), 감독(1명)
	cout << "[" << m_name << "]" << endl;
	cout << "개봉연도: " << m_year << endl;
	cout << "장르: " << m_gendre << endl;
	cout << "평점: " << m_score << "점" << endl;
	cout << "러닝타임: " << m_times << "분" << endl;
	cout << "주인공: " << m_actor << endl;
	cout << "감독: " << m_director;
}
