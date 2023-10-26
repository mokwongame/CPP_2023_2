#include "UserInfo.h"

int main()
{
	using namespace std;
	// 파일로 저장
	////UserInfo userInfo;
	//UserInfo userInfo("Cho", 1000, 200, 0.7);
	//userInfo.print();
	//ofstream file("userinfo.txt");
	//userInfo.save(file);

	// 파일에서 읽기
	UserInfo userInfo;
	ifstream file("userinfo.txt");
	userInfo.load(file);
	userInfo.print();
	return 0;
}