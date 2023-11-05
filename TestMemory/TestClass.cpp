#include <iostream>
#include <memory>
#include "MyClass.h"

int main()
{
	using namespace std;

	MyClass myClass1; // 변수 선언; 클래스를 마치 자료형처럼; 이때 myClass는 변수이지만 보통 인스턴스
	myClass1.setVal(20);
	cout << myClass1.getVal() << endl;

	MyClass* pClass1 = new MyClass;
	pClass1->setVal(30);
	cout << pClass1->getVal() << endl;
	delete pClass1;

	unique_ptr<MyClass> pClass2(new MyClass);
	pClass2->setVal(-30);
	cout << pClass2->getVal() << endl;

	// 클래스의 인스턴스를 만들면 프로퍼티는 인스턴스마다 생김: nVal와 x는 인스턴스마다 생김
	// 정적 멤버는 클래스당 하나만 생김: nCount는 하나만 생김
	// 정적 멤버 접근은 "클래스명::"로 함
	MyClass::setCount(200);
	cout << MyClass::getCount() << endl;
	cout << MyClass::getNum() << endl;

	return 0;
}