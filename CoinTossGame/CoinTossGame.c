/*
[Coin Toss Game ��Ģ]
1. ����ڰ� �ո�(Front), �޸�(Back) ����: ����� �Է�
2. ���� �߻� -> ������ �ո�, �޸� ����
3. ����� �Է°� ������ ���ؼ� ����
*/
#include <stdio.h> // VS ��� ���� ���� �˻�
#include "LibConsole.h" // ���� ���� �˻�
#include "LibGameTool.h"

// ��� ����(enumeration): enum ��������� {��� ����};
enum CoinType
{
	CT_BACK = 0, CT_FRONT, CT_NULL
}; // CT_FRONT=1, CT_NULL=2

// �Լ� ����(��� ����) -> �Լ� ����(�ҽ� ����)
enum CoinType inputCoin(void);
enum CoinType randCoin(void);

// ����ڷ��� �Լ���(�Է� ����, ...) {...}
void main(void) // void(����)
{
	randseed(); // ���� �ʱ�ȭ; LibGameTool.h�� ����
	while (1) // ��, ���� �Ǵ�: 0���� �ƴ��� �Ǵ�
	{
		// �ڷ��� ������ = �ʱⰪ;
		enum CoinType nInput = inputCoin(); // =: �Ҵ� ������(������ �� -> ���� ������ �Ҵ�)
		if (nInput == CT_NULL) continue; // continue: �ݺ����� ó������ ���ư���
		// ���� ������: ���� �߻�
		enum CoinType nRand = randCoin();
	}
}

// �Լ� ����: ����ڷ��� �Լ���(�Է� ����, ...) {...}
enum CoinType inputCoin(void)
{
	puts("���� �ո�(F)�̳� �޸�(B)�� �����ϼ���."); // ���ڿ�(string) ���
	printf("����� ������? ");
	char cInput = _getche(); // e: echo(����)
	if (cInput == 'F' || cInput == 'f')
	{
		puts("\n�ո��� �����߽��ϴ�.");
		return CT_FRONT;
	}
	else if (cInput == 'B' || cInput == 'b')
	{
		puts("\n�޸��� �����߽��ϴ�.");
		return CT_BACK;
	}
	else
	{
		puts("\n�߸� �Է��߽��ϴ�.");
		return CT_NULL;
	}
}

enum CoinType randCoin(void)
{
	puts("�ƹ� Ű�� ������ ������ �����ϴ�.");
	_getch(); // ���� �� ��(char) �Է�; echo X
	int nRand = randrange(0, 2); // (0, 2-1) �������� ���� ���� �߻�
	enum CoinType nRandCoin = (enum CoinType)nRand;
	if (nRandCoin == CT_BACK)
		puts("���� ������ �޸��Դϴ�.");
	else puts("���� ������ �ո��Դϴ�.");
	return nRandCoin;
}
