#include <iostream>
#include <memory>

// ����Ʈ ������: �޸𸮸� �Ҵ��ϸ� ����� ���� �� �ڵ������� �޸� ����

int main()
{
	using namespace std;

	// �޸� �Ҵ�
	unique_ptr<int> ptr1(new int{ 20 }); // <int> �ǹ�: ���ø�(template)�� �ڷ���
	//*ptr1 = 20;
	cout << *ptr1 << endl;

	unique_ptr<double> ptr2(new double{ 1.2 });
	//ptr2 = new double;
	//*ptr2 = 1.2;
	cout << *ptr2 << endl;

	// �迭 �Ҵ�
	int nSize = 20;
	unique_ptr<int[]> ar(new int[nSize] {1, 2, 3, 4});
	for (int i = 0; i < nSize; i++)
		cout << ar[i] << endl;

	// unique_ptr�� �޸� ������ ������ ��: �ν��Ͻ� ptr�� ������ �� �Ҵ�� �޸𸮵� ������ ����

	return 0;
}