#pragma once

#include "Panda.h"

#define NUM_QUEST	(2) // ���������� 5�� �ؾ� ��
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

	void play(void);

private:
	Panda m_panda;
	QuizQna m_animalQuiz[NUM_QUEST];
};

inline void ZooQuizGame::play(void)
{

}