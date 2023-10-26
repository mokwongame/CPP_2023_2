#include "UserInfo.h"
#include <vector>

int main()
{
	using namespace std;
	// ���� ����ڸ� vector�� �߰�
	vector<UserInfo> vecUser;
	vecUser.push_back(UserInfo("Kim", 200));
	vecUser.push_back(UserInfo("Lee", 300));
	vecUser.push_back(UserInfo("Park", 400));
	vecUser.push_back(UserInfo("Oh", 500));
	for (auto& user : vecUser)
	{
		user.print();
		cout << endl;
	}

	// ���� ����
	ofstream outfile("vecUserInfo.txt");
	outfile << vecUser.size() << endl; // vector ũ�⸦ ���
	for (auto& user : vecUser)
		user.save(outfile);

	// ���� ����
	vector<UserInfo> vecFileUser;
	ifstream infile("vecUserInfo.txt");
	int nVecSize; infile >> nVecSize;
	cout << "���� ���� ũ�� = " << nVecSize << endl;
	for (int i = 0; i < nVecSize; i++)
	{
		UserInfo user;
		user.load(infile);
		user.print();
		vecFileUser.push_back(user);
		cout << endl;
	}

	// vecFileUser ���� ���
	cout << endl << "==================" << endl;
	for (auto& user : vecFileUser)
	{
		user.print();
		cout << endl;
	}
	return 0;
}