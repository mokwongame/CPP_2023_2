#include "UserInfo.h"
#include <vector>

int main()
{
	using namespace std;
	// 여러 사용자를 vector에 추가
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

	// 파일 저장
	ofstream outfile("vecUserInfo.txt");
	outfile << vecUser.size() << endl; // vector 크기를 기록
	for (auto& user : vecUser)
		user.save(outfile);

	// 파일 열기
	vector<UserInfo> vecFileUser;
	ifstream infile("vecUserInfo.txt");
	int nVecSize; infile >> nVecSize;
	cout << "파일 원소 크기 = " << nVecSize << endl;
	for (int i = 0; i < nVecSize; i++)
	{
		UserInfo user;
		user.load(infile);
		user.print();
		vecFileUser.push_back(user);
		cout << endl;
	}

	// vecFileUser 정보 출력
	cout << endl << "==================" << endl;
	for (auto& user : vecFileUser)
	{
		user.print();
		cout << endl;
	}
	return 0;
}