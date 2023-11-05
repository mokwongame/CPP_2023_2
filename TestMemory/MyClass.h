#pragma once

#include <iostream>

class MyClass
{
public:
	MyClass(void) {}
	~MyClass() {}

	// getter & setter
	int getVal(void) const { return nVal; } // const �ǹ�: �� �޼ҵ�� ������Ƽ�� ���� X; ���ʿ��� ������ ���� �ʱ� ���ؼ�
	//void setVal(int val) { nVal = val; }
	void setVal(int nVal) { this->nVal = nVal; } // �Լ� �Է� �̸��� ������Ƽ �̸��� ���� ���: this ������(���� �ν��Ͻ��� ������)
	// -> �ǹ�: ����ü�� Ŭ���� �������� ��� ����; �ν��Ͻ��� ��� ����: ��(.) ������; ��: -> �� .�� ��

	// ���� ���: ��� ���� �տ� static�� ���� ���
	static int getCount(void) { return nCount; }
	//static void setCount(int count) { nCount = count; }
	static void setCount(int nCount) { MyClass::nCount = nCount; }
	static int getNum(void) { return 300; }

private:
	int nVal = 10; // private ������Ƽ
	static int nCount; // ���� ������Ƽ; ������ Ŭ�����ȿ��� ��; ���ǿ� �ʱ�ȭ�� Ŭ���� �ٱ����� ����
	double x = 20;
	static const int nMyNumber; // �����̸� ����� ������Ƽ
	//const static int nMyNumber; // �����̸� ����� ������Ƽ
};
