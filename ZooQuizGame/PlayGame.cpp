#include "ZooQuizGame.h"

int main()
{
	ZooQuizGame quiz;
	quiz.setAnimalQuizFile("판다 문제.txt");
	quiz.loadQuizFile();
	quiz.play();
}