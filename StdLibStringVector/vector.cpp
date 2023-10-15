#include <iostream>
#include <vector> // ũ�Ⱑ ���� ������ �迭(array)

int main(void)
{
	using namespace std; // vector�� std�� ����
	// <int> �ǹ�: <>�� ���ø�(template, Ʋ)�� �ǹ�
	vector<int> vec = { 1, 2, 3, 10, -4, 5, -6, 7 };
	// �迭 ����: int ar[10];
	cout << "size = " << vec.size() << endl;
	for (auto i : vec) cout << i << endl;

	vec.push_back(100); // back�� push: snake case
	vec.push_back(-100);
	cout << endl << "size = " << vec.size() << endl;
	for (auto i : vec) cout << i << endl;
	vec.pop_back(); // back���� pop(���� ����)
	cout << endl << "size = " << vec.size() << endl;
	for (auto i : vec) cout << i << endl;

	// ������ ���� ����
	auto j = vec.back();
	cout << endl << "back = " << j << endl;
	j = vec.front();
	cout << endl << "front = " << j << endl; \
		// Ư�� ���� ���� [], at()
		cout << endl << vec[1] << endl; // index 1���� ����: 0, 1�̴ϱ� �ι�° ����
	cout << endl << vec.at(2) << endl;
	cout << "is empty? " << vec.empty() << endl;

	// for loop: iterator(�ݺ���) -> �ݺ��ϱ� ���� ������(pointer)
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl; // �ݺ��� it�� �� ��������: *������(valueOf: �� ��)
	}
	return 0;
}