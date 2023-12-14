#pragma once

#include <fstream>
#include "Panda.h"

#define NUM_QUEST	(2) // 과제에서는 5개 해야 함
#define NUM_ANS	(3)

struct QuizQna 
{
	std::string question;
	std::string arAns[NUM_ANS];
};

class ZooQuizGame
{
public:
	ZooQuizGame(void) {}

	void setAnimalQuizFile(const std::string& name)
	{
		m_animalQuizFile = name;
	}
	void loadQuizFile(void);
	void play(void);

private:
	std::string m_animalQuizFile;
	Panda m_panda;
	QuizQna m_animalQuiz[NUM_QUEST];

	void loadOneQuiz(std::ifstream& file, int nPos); // file을 읽어서 m_animalQuiz[nPos] 위치에 문제와 보기를 채워넣음
};

inline void ZooQuizGame::loadQuizFile(void)
{
	using namespace std;
	// 동물 퀴즈
	ifstream file(m_animalQuizFile);
	//cout << file.is_open() << endl; // 파일 열기 성공?
	for (int i = 0; i < NUM_QUEST; i++)
		loadOneQuiz(file, i);
}

inline void ZooQuizGame::play(void)
{

}

inline void ZooQuizGame::loadOneQuiz(std::ifstream& file, int nPos)
{
	using namespace std;
	// 문제 읽기
	string str;
	while (1)
	{
		getline(file, str);
		if (str == "===") break;
		else if (file.eof()) break; // eof: end of file(파일의 끝); eof() 함수는 EOF를 만나면 true 반환
		m_animalQuiz[nPos].question += str + "\n";
	}
	cout << m_animalQuiz[nPos].question << endl;

	// 보기 읽기
	for (int i = 0; i < NUM_ANS; i++)
	{
		getline(file, str);
		m_animalQuiz[nPos].arAns[i] = str;
	}
	for (string& s : m_animalQuiz[nPos].arAns)
	{
		cout << s << endl;
	}
	getline(file, str); // "===" 읽기
}
