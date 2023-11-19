#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"

int main()
{
	using namespace std;
	Animal* ptr = nullptr; // null pointer
	//ptr = new Animal; // 정상적인 할당
	//delete ptr;

	ptr = new Dog; // Dog != Animal; upcasting: 자식에서 부모 방향으로 상향 형 선정
	ptr->speak();
	delete ptr;

	//ptr = new Cat;
	//ptr->speak();
	//delete ptr;

	//ptr = new Pig;
	//ptr->speak();
	//delete ptr;
}