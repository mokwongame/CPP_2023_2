#include <iostream>
#include <vector> // ���� �ڷ� ������ ������ ��� ����; ���� = ���̰� �����Ǵ� �迭

int main()
{
	using namespace std;
	// vector Ŭ������ namespace std�� ���ǵ�
	vector<int> vec = { 1, -2, 3 }; // <int> �ǹ�: ���ø�(template)�� �ڷ����� int�� �ǹ�, <int>�� ���� Ŭ���� �ȿ� �ִ� Ư�� ������Ƽ�� �ڷ����� int�� �ٲ�; Ŭ������ ������ ���� <>�� ���ø��̶� �ǹ�; ���ø� Ŭ������ Ŭ������ �⺻ ����(�޼ҵ�)�� �����ϸ� <>�� �̿��� Ŭ������ ������Ƽ(��� ����)�� �ڷ����� �ٲ�
	for (auto i : vec)
		cout << i << endl;
	cout << "vector ũ�� = " << vec.size() << endl; // size() �Լ��� ������ ũ�⸦ return
	vec.push_back(20); // vector�� ����(back)�� 20�� push
	vec.push_back(30);
	for (auto i : vec) cout << i << endl;
	cout << "vector ũ�� = " << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << "vec[" << i << "] = " << vec[i] << endl;
	return 0;
}