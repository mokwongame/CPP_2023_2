#include <iostream>

int main()
{
	using namespace std;

	const int i = 10;
	const int i2 = -10;
	//i = 20;
	// const int* �ǹ�: int*������ ���� ���� X; const int�� pointer�� ��; const�� ������ ���̶�; �ּ� ���� ����
	const int* j = &i; // & �ǹ�: ������ �ּҸ� ��������; addressof�� ����
	j = &i2;
	cout << *j << endl;

	int l = 30;
	int l2 = -30;
	int* const k = &l; // int*������ pointer k�� ���� X(�ּ� ���� X); ���� ���� ����
	cout << *k << endl;
	*k = 50;
	//k = &l2;
	cout << *k << endl;

	return 0;
}