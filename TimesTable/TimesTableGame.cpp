#include "TimesTableGame.h"

/* [������ ����]
0. ������ ��Ģ
 - 9�� ���� ����� 1���� 9���� ���� ����� ����: 1*a = , 2*a = , ..., 9*a =
 - 10�� �̻� ����� �ִ� �ܱ��� ���� ����� ����: 1*a = , 2*a = , ..., 9*a = , 10*a = , ... a*a =
1. �޴� ����
(1) ��� ������ ���: �ִ� �ܼ��� �Է¹޾Ƽ� 1�ܺ��� �ִ� �ܱ��� ���
(2) ����ڰ� ���ϴ� �ܸ� ���
*/

int main(void)
{
	using namespace std;
	// �ν��Ͻ� ����: Ŭ������ �ν��Ͻ���(������);
	// �̶� �����ڰ� ȣ��
	TimesTableGame timesTableGame;
	timesTableGame.printLogo(); // �ν��Ͻ��� ��� ������ ��(.) ������
	// �޴� ���
	timesTableGame.printMenu();
	// ����� �Է�
	int nMenu = timesTableGame.inputMenu();
	//cout << "�Է��� ��ȣ: " << nMenu;
	timesTableGame.exeMenu(nMenu);
	return 0;
	// �ν��Ͻ��� �ı��� ���� �Ҹ��� ȣ��
}