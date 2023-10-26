#pragma once

#include <iostream>
#include <string>

//using namespace std; // 캡슐화를 무너뜨려서 사용을 권고하지 않음

class UserInfo
{
public:
	UserInfo(void) {}
	UserInfo(std::string name, int score = 0, int playTime = 0, double correctRatio = 0.)
	{
		m_name = name;
		m_score = score;
		m_playTime = playTime;
		m_correctRatio = correctRatio;
	}
	~UserInfo() {}

	// getter, setter
	std::string getName(void) const { return m_name; }
	void setName(std::string name)
	{
		m_name = name;
	}

	void print(void) const // const 의미: 이 메소드는 내부 변수를 변경하지 않음(쓰기 X)
	{
		using namespace std;
		cout << "name = " << m_name << endl;
		cout << "score = " << m_score << endl;
		cout << "플레이 시간 = " << m_playTime << endl;
		cout << "정답 확률 = " << m_correctRatio * 100. << "%" << endl;
	}

private:
	std::string m_name;
	int m_score = 0;
	int m_playTime = 0;
	double m_correctRatio = 0.;
};