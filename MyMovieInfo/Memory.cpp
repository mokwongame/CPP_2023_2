#include <iostream>

int main()
{
	using namespace std;
	// ���� �޸� �Ҵ�: ��(heap) ������ �޸� �Ҵ�; ������ ����� �Ŀ� �Ҵ�Ǵ� �޸�
	int i = 0; // ���� �޸�: �������� int�� �ڷ����� �޸𸮰� ������
	int* ptr = nullptr; // nullptr: null pointer�� �ǹ�, ���ڷ� ǥ���Ǹ� 0
	// int*: int ������(int �ڷ����� �ּҸ� ���� ����)
	ptr = new int; // int �ڷ��� ���� ����(���� �޸�, ���� ����)�� ���Ӱ�(new) ������ ptr�� �Ҵ�
	*ptr = 20; // * �ǹ�: valueof(...�� ��)
	cout << "int = " << *ptr << endl;
	int* ptr2 = ptr; // ������ ptr�� ptr2�� �Ҵ�: ptr2�� ���� �ּҸ� ����
	*ptr2 = 40;
	cout << "int = " << *ptr << endl;
	// �� ���� ���� ���� �޸𸮴� �ݵ�� ����
	delete ptr; // ���� ������ delete ptr�� ����; �迭�̸� delte [] ptr�� ����
}


