#include "UserInfo.h"

int main()
{
	using namespace std;
	// ���Ϸ� ����
	////UserInfo userInfo;
	//UserInfo userInfo("Cho", 1000, 200, 0.7);
	//userInfo.print();
	//ofstream file("userinfo.txt");
	//userInfo.save(file);

	// ���Ͽ��� �б�
	UserInfo userInfo;
	ifstream file("userinfo.txt");
	userInfo.load(file);
	userInfo.print();
	return 0;
}