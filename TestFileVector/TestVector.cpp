#include <iostream>
#include <vector> // namespace std�� ���ǵ� ���� �ڷ� ����(�迭�� ���������, ���� ���Ҹ� �ְų� �� �� ���� -> �ڷ� ������ ũ�Ⱑ ������ �� ����)

int main()
{
	using namespace std;
	//std::vector<int> vec;
	vector<int> vec = { 1,2,3,4,5, -10, -20 }; // ������ �ڷ����� int�� ���͸� ����; <...> �ǹ�: ���ø�(template)
	//for (int i : vec) // vec���� ���Ҹ� �ϳ� �̾Ƽ� i�� ����
	for (auto i : vec) // auto �ڷ���: �ƶ��� �°� �ڷ����� �ڵ�����(auto) ����
	{
		cout << i << endl;
	}
	//  �ڷ� �ϳ� �ֱ�: ���� ��(back)�� �ڷ� �ϳ��� �о�ֱ�(push)
	vec.push_back(100); // �Լ��� ����: �ܾ _�� ����; �ܾ�� ��� �ҹ���; snake case(�� ����)
	cout << endl;
	for (auto i : vec) cout << i << endl;
	// ���� ũ�� ���
	cout << "vec size = " << vec.size() << endl;
	// �ڷ� �ϳ� ����
	vec.pop_back();
	cout << endl;
	for (auto i : vec) cout << i << endl;
	cout << "vec size = " << vec.size() << endl;
	return 0;
}