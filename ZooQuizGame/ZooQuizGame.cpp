// ZooQuizGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Life.h"
#include "Animal.h"
#include "Plant.h"

int main()
{
	using namespace std;
	Life panda("판다", LifeType::LT_ANIMAL, "Ailuropoda melanoleuca", "곰과", "중국 사천성");
	cout << panda << endl;
}