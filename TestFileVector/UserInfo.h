#pragma once

#include <iostream>
#include <fstream>
#include <string>

//using namespace std; // 캡슐화를 무너뜨려서 사용을 권고하지 않음

class UserInfo
{
public:
	UserInfo(void) {}
	// reference(참조자): 자료형+&; 똑똑한 포인터; 포인터 역할하지만(값을 복사X) 변수처럼 접근(원본에 접근)
	UserInfo(const std::string& name, int score = 0, int playTime = 0, double correctRatio = 0.) // 상수 선언: const+자료형; 이 변수는 변경 불가능
	{
		m_name = name; // 값을 복사
		m_score = score;
		m_playTime = playTime;
		m_correctRatio = correctRatio;
	}
	~UserInfo() {}

	// getter, setter
	std::string getName(void) const { return m_name; }
	void setName(const std::string& name)
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
	void save(std::ofstream& file)
	{
		using namespace std;
		file << m_name << endl;
		file << m_score << endl;
		file << m_playTime << endl;
		file << m_correctRatio << endl;
	}
	void load(std::ifstream& file)
	{
		using namespace std;
		file >> m_name;
		file >> m_score;
		file >> m_playTime;
		file >> m_correctRatio;
	}

private:
	std::string m_name;
	int m_score = 0;
	int m_playTime = 0;
	double m_correctRatio = 0.;
};