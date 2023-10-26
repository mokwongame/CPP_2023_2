#pragma once

#include <iostream>
#include <fstream>
#include <string>

//using namespace std; // ĸ��ȭ�� ���ʶ߷��� ����� �ǰ����� ����

class UserInfo
{
public:
	UserInfo(void) {}
	// reference(������): �ڷ���+&; �ȶ��� ������; ������ ����������(���� ����X) ����ó�� ����(������ ����)
	UserInfo(const std::string& name, int score = 0, int playTime = 0, double correctRatio = 0.) // ��� ����: const+�ڷ���; �� ������ ���� �Ұ���
	{
		m_name = name; // ���� ����
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

	void print(void) const // const �ǹ�: �� �޼ҵ�� ���� ������ �������� ����(���� X)
	{
		using namespace std;
		cout << "name = " << m_name << endl;
		cout << "score = " << m_score << endl;
		cout << "�÷��� �ð� = " << m_playTime << endl;
		cout << "���� Ȯ�� = " << m_correctRatio * 100. << "%" << endl;
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