#include "ZooQuizGame.h"

int main()
{
	ZooQuizGame quiz;
	quiz.setAnimalQuizFile("�Ǵ� ����.txt");
	quiz.loadQuizFile();
	quiz.play();
}