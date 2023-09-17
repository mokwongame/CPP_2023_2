#pragma once // #: �����Ϸ� �������� ����; #pragma �ǿ�����(pragmatic); once: ���� ��� ������ �� ���� include(���Խ�Ŵ), ��� ���ϰ��� include�� �� �� ���� �߰�, �ҽ� ���Ͽ��� ���� �� include�� �� ����

#include <stdio.h>
#include <conio.h>
#include "LibConsole.h"
#include "LibGameTool.h"

// C++: ���� ����, �Լ��� ������� ���� -> ��¿ �� ���� ��� ��: namespace�� ĸ��ȭ

// namespace namespace�� {...}
// ���: namespace �ڵ� ��� �ȿ� �ִ� ���(���, ����, �Լ�)
namespace mglib // Mokwon Game Library(�Լ��� ����ü)
{
	enum CoinType
	{
		CT_BACK = 0, CT_FRONT, CT_NULL
	};

	// ���� ����: �ܺ�(external) ���� - �ٸ� ���� ����� ������ ���� ��ġ ����ϱ� ���� �ܺ� ������ ����
	extern int g_totalScore;

	// �Լ� ����: �Լ� ���� ���� �Լ� ���� ��� ���Ͽ� ���ƾ� ��

	// �Լ� ���� -> cpp �ҽ� ���Ϸ� �Űܾ� ��
	// �ζ���(inline) �Լ�: �Լ� ���������� ��� ���Ͽ� ���Ƶ� ������ �ȵ�; �Լ��� ȣ�� �ӵ��� ������; ���� ���� ũ�Ⱑ Ŀ��(�Լ� ȣ���� �ڵ� ������� ��ü)
	// inline �ǹ�: �Լ� ���������� ���� �ڵ� ����� �Լ� ȣ���� ���� �� ��ü
	// #define: �ڵ� ����� �״�� ��ü
	inline void showLogo(void)
	{
		settextcol(GREEN);
		puts("=======================");
		puts("   My Coin Toss Game   ");
		puts("   Version 1.0");
		puts("=======================\n");
		settextcol(GRAY);
	}

	//inline enum CoinType inputCoinType(void) // C ��Ÿ��
	inline CoinType inputCoinType(void) // C++ ��Ÿ��: ���������� enum�� ���� ����; CoinType�� ��ġ �ڷ���ó�� ���� ���
	{
		puts("\n���� �ո��� F, ���� �޸��� B�� �Է�");
		printf("����� ������?");
		char ch = _getche(); // echo�ϸ鼭 Enter���� �� ���� �Է�
		if (ch == 'F' || ch == 'f') return CT_FRONT;
		else if (ch == 'B' || ch == 'b') return CT_BACK;
		else
		{
			puts("�߸� �Է��ϼ̽��ϴ�.");
			return CT_NULL;
		}
	}

	inline CoinType randomCoinType(void)
	{
		puts("\n\n���� ������ �����ϴ�.");
		int nRand = randrange(0, 2); // 0, 1
		if (nRand == 0) puts("������ �޸��Դϴ�.\n");
		else puts("������ �ո��Դϴ�.\n");
		return (CoinType)nRand;
	}

	inline void printResult(int score, double winRatio)
	{
		printf("\n���� ������ %d�Դϴ�.", score);
		printf("\n���� �·��� %g�Դϴ�.\n", winRatio);
	}
}