#pragma once // pragmatic(�ǿ�����, �����ϴ�); ��� ������ �� ���� include

#include <stdio.h> // VS ��� ���� ���� �˻�
#include "LibConsole.h" // ���� ���� �˻�
#include "LibGameTool.h"

// namespace namespace�� {...}
// namespace(�̸� ����): Ư���� �̸����� ������� �Լ����� ��� ����ȭ; ���� ������ ���� �Լ��� �־ �������(namespace�� ������ �����ϱ� ����)
namespace mglib
{
	// ��� ����(enumeration): enum ��������� {��� ����};
	enum CoinType
	{
		CT_BACK = 0, CT_FRONT, CT_NULL
	}; // CT_FRONT=1, CT_NULL=2

	// ���� ���� ����: {...} �ٱ��� �ִ� ���� ����
	int nTotalScore = 0;

	// �Լ� ����(��� ����) -> �Լ� ����(�ҽ� ����)
	CoinType inputCoin(void); // enum CoinType -> CoinType (C++: ���ο� �ڷ���ó�� ���)
	CoinType randCoin(void);
	void checkCoin(enum CoinType nInput, enum CoinType nRand);

	// �Լ� ����: ����ڷ��� �Լ���(�Է� ����, ...) {...} -> ��� ���Ͽ��� �Լ� �����ϸ� �ȵ�
	// �ζ���(inline) �Լ�: ��� ���Ͽ� �Լ� ���� ����
	inline CoinType inputCoin(void)
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

	inline CoinType randCoin(void)
	{
		settextcol(BLUE);
		puts("�ƹ� Ű�� ������ ������ �����ϴ�.");
		_getch(); // ���� �� ��(char) �Է�; echo X
		int nRand = randrange(0, 2); // (0, 2-1) �������� ���� ���� �߻�
		CoinType nRandCoin = (CoinType)nRand; // type casting(�� ����)
		settextcol(GREEN);
		if (nRandCoin == CT_BACK)
			puts("���� ������ �޸��Դϴ�.");
		else puts("���� ������ �ո��Դϴ�.");
		return nRandCoin;
	}

	inline void checkCoin(CoinType nInput, CoinType nRand)
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
}