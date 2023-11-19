// TestProtected.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"

int main()
{
	using namespace std;

	//Animal animal;
	//animal.setName("사자");
	//cout << animal.getName() << endl;

	Dog dog;
	dog.setName("멍멍이");
	cout << endl << endl;
	dog.print("한국");

	//Cat cat;
	//cat.setName("야옹이");
	//cout << endl << endl;
	//cat.print();

	//Pig pig;
	//pig.setName("꿀꿀이");
	//cout << endl << endl;
	//pig.print();
}
