#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"

int main()
{
	using namespace std;
	Animal* ptr = nullptr; // null pointer
	//ptr = new Animal; // �������� �Ҵ�
	//delete ptr;

	ptr = new Dog; // Dog != Animal; upcasting: �ڽĿ��� �θ� �������� ���� �� ����
	ptr->speak();
	delete ptr;

	//ptr = new Cat;
	//ptr->speak();
	//delete ptr;

	//ptr = new Pig;
	//ptr->speak();
	//delete ptr;
}