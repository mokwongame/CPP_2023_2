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

// ���� ���� ����: {...} �ٱ��� �ִ� ���� ����
int nTotalScore = 0;

// �Լ� ����(��� ����) -> �Լ� ����(�ҽ� ����)
enum CoinType inputCoin(void);
enum CoinType randCoin(void);
void checkCoin(enum CoinType nInput, enum CoinType nRand);

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
		checkCoin(nInput, nRand);
	}
}

// �Լ� ����: ����ڷ��� �Լ���(�Է� ����, ...) {...}
enum CoinType inputCoin(void)
{
	settextcol(GREEN);
	puts("���� �ո�(F)�̳� �޸�(B)�� �����ϼ���."); // ���ڿ�(string) ���
	settextcol(WHITE);
	printf("����� ������? ");
	char cInput = _getche(); // e: echo(����)
	settextcol(GREEN);
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
		settextcol(RED);
		puts("\n�߸� �Է��߽��ϴ�.");
		return CT_NULL;
	}
}

enum CoinType randCoin(void)
{
	settextcol(BLUE);
	puts("�ƹ� Ű�� ������ ������ �����ϴ�.");
	_getch(); // ���� �� ��(char) �Է�; echo X
	int nRand = randrange(0, 2); // (0, 2-1) �������� ���� ���� �߻�
	enum CoinType nRandCoin = (enum CoinType)nRand;
	settextcol(GREEN);
	if (nRandCoin == CT_BACK)
		puts("���� ������ �޸��Դϴ�.");
	else puts("���� ������ �ո��Դϴ�.");
	return nRandCoin;
}

void checkCoin(enum CoinType nInput, enum CoinType nRand)
{
	if (nInput == nRand)
	{
		settextcol(RED);
		puts("�� �߽��ϴ�. ������ ���߾����ϴ�.");
		nTotalScore++;
	}
	else // CoinType�� �ٸ�
	{
		settextcol(BLUE);
		puts("�ƽ��׿�. ���� ������ Ʋ�Ƚ��ϴ�.");
		nTotalScore--;
	}
	settextcol(YELLOW);
	printf("���� ���ھ�� %d�Դϴ�.\n\n", nTotalScore);
}
