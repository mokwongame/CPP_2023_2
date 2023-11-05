#include <iostream>
#include <memory>
#include "MyClass.h"

int main()
{
	using namespace std;

	MyClass myClass1; // ���� ����; Ŭ������ ��ġ �ڷ���ó��; �̶� myClass�� ���������� ���� �ν��Ͻ�
	myClass1.setVal(20);
	cout << myClass1.getVal() << endl;

	MyClass* pClass1 = new MyClass;
	pClass1->setVal(30);
	cout << pClass1->getVal() << endl;
	delete pClass1;

	unique_ptr<MyClass> pClass2(new MyClass);
	pClass2->setVal(-30);
	cout << pClass2->getVal() << endl;

	// Ŭ������ �ν��Ͻ��� ����� ������Ƽ�� �ν��Ͻ����� ����: nVal�� x�� �ν��Ͻ����� ����
	// ���� ����� Ŭ������ �ϳ��� ����: nCount�� �ϳ��� ����
	// ���� ��� ������ "Ŭ������::"�� ��
	MyClass::setCount(200);
	cout << MyClass::getCount() << endl;
	cout << MyClass::getNum() << endl;

	return 0;
}