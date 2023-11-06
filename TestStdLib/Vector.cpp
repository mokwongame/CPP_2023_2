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
	// ǥ�� ���̺귯���� �Լ� ǥ�� ���: snake case(�� �ݽ�) -> push_back
	// C#�� �Լ� ǥ��: �빮�ڷ� �Լ� ����, �������� �빮�� -> Pascal case -> PushBack()
	// ������� �Լ� ǥ��: �ҹ��ڷ� �Լ� ����, ������ �빮�� -> camel case(��Ÿ �ݽ�) -> pushBack()
	vec.push_back(20); // vector�� ����(back)�� 20�� push
	vec.push_back(30);
	for (auto i : vec) cout << i << endl;
	cout << "vector ũ�� = " << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << "vec[" << i << "] = " << vec[i] << endl;

	vec.pop_back(); // vector�� ������ pop; �ڷ��� ũ�Ⱑ �ϳ� �پ��
	cout << endl;
	for (auto i : vec) cout << i << endl;
	cout << "vector ũ�� = " << vec.size() << endl;

	// iterator(�ݺ���): ������ ������� �ݺ��ϴ� ���
	// begin(): ���� ������(�ݺ���)
	// end(): �� ������(�ݺ���)
	// ������ ������ų ���� ++
	// �������� �������� �ݺ��� ����: ÷�ڸ� 0������ ����ȣ����
	cout << endl << "�ݺ��ڷ� ���� ���� ���" << endl;
	//for (auto it = vec.begin(); it < vec.end(); it++)
	for (auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << endl; // it�� �����Ͷ� ������ �ٲ� ���� * ������(valueof)�� ���

	// �ݴ� �������� �ݺ��� ����: ÷�� ����ȣ���� 0������ ��ȭ
	// rbegin(): reverse begin()
	// rend(): reverse end()
	cout << endl << "�ݺ��ڷ� �ݴ� ���� ���" << endl;
	for (auto it = vec.rbegin(); it != vec.rend(); it++)
		cout << *it << endl;

	vector<double> vecDouble = { 1.2, 3.4, -5.6 };
	cout << endl << "�Ǽ� ���� ���" << endl;
	for (auto x : vecDouble) cout << x << endl;
	return 0;
}