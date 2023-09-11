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
{CT_BACK=0, CT_FRONT, CT_NULL}; // CT_FRONT=1, CT_NULL=2

// �Լ� ����(��� ����) -> �Լ� ����(�ҽ� ����)
enum CoinType inputCoin(void);

// ����ڷ��� �Լ���(�Է� ����, ...) {...}
void main(void) // void(����)
{
	randseed(); // ���� �ʱ�ȭ; LibGameTool.h�� ����
	// �ڷ��� ������ = �ʱⰪ;
	enum CoinType nInput = inputCoin(); // =: �Ҵ� ������(������ �� -> ���� ������ �Ҵ�)
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
