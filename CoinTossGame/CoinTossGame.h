#pragma once // pragmatic(�ǿ�����, �����ϴ�); ��� ������ �� ���� include; ��� ������ �ٸ� ��� ���Ͽ� �ߺ� include ���� ����

//#include <stdio.h> // VS ��� ���� ���� �˻�: C ����� ǥ�� �����(standard input/out)
#include <iostream> // C++ ����� ǥ�� �����: ǥ�� ��� ���Ͽ� .h, .hpp(Ȯ����)�� ����
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

	// ���� ���� ����: {...} �ٱ��� �ִ� ���� ���� -> ��� ���Ͽ� ���� �� ����(�ҽ� ���Ͽ� ���� �� include �Ǹ� ��Ŀ ���� �߻�
	// �ܺ�(external) ������ ����
	extern int nTotalScore; // int nTotalScore�� ���� ������� �ʰ� �ٸ� ���Ͽ� ����; �ܺ� ������ ������ �� �ʱ�ȭ �Ұ���
	extern int nTotalTry;
	extern int nTotalWin;

	// �Լ� ����(��� ����) -> �Լ� ����(�ҽ� ����)
	CoinType inputCoin(void); // enum CoinType -> CoinType (C++: ���ο� �ڷ���ó�� ���)
	CoinType randCoin(void);
	void checkCoin(enum CoinType nInput, enum CoinType nRand);

	inline void showLogo(void)
	{
		using namespace std;
		settextcol(RED);
		cout << "============" << endl;
		cout << " ���� ������ ����" << endl;
		cout << " CHO, YH" << endl;
		cout << "============" << endl << endl;
	}
	// �Լ� ����: ����ڷ��� �Լ���(�Է� ����, ...) {...} -> ��� ���Ͽ��� �Լ� �����ϸ� �ȵ�
	// �ζ���(inline) �Լ�: ��� ���Ͽ� �Լ� ���� ����
	inline CoinType inputCoin(void)
	{
		using namespace std; // ǥ�� namespace�� ���
		settextcol(GREEN);
		cout << "���� �ո�(F)�̳� �޸�(B)�� �����ϼ���." << endl; // ���ڿ�(string) ���; <<: ��Ʈ�� cout�� ����ϴ� ��ȣ; cout(console output); endl: end of line(���� Ű)
		settextcol(WHITE);
		cout << "����� ������? ";
		char cInput = _getche(); // e: echo(����)
		settextcol(GREEN);
		if (cInput == 'F' || cInput == 'f')
		{
			cout << endl << "�ո��� �����߽��ϴ�." << endl;
			return CT_FRONT;
		}
		else if (cInput == 'B' || cInput == 'b')
		{
			cout << endl << "�޸��� �����߽��ϴ�." << endl;
			return CT_BACK;
		}
		else
		{
			settextcol(RED);
			cout << endl << "�߸� �Է��߽��ϴ�." << endl;
			return CT_NULL;
		}
	}

	inline CoinType randCoin(void)
	{
		settextcol(BLUE);
		std::cout << "�ƹ� Ű�� ������ ������ �����ϴ�." << std::endl;
		_getch(); // ���� �� ��(char) �Է�; echo X
		int nRand = randrange(0, 2); // (0, 2-1) �������� ���� ���� �߻�
		nTotalTry++; // �õ� ȸ���� �ϳ� ����
		CoinType nRandCoin = (CoinType)nRand; // type casting(�� ����)
		settextcol(GREEN);
		if (nRandCoin == CT_BACK)
			std::cout << "���� ������ �޸��Դϴ�." << std::endl;
		else std::cout << "���� ������ �ո��Դϴ�." << std::endl;
		return nRandCoin;
	}

	inline double getWinRatio(void)
	{
		// �·� ���
		return nTotalWin / (double)nTotalTry * 100.;
	}
	inline void checkCoin(CoinType nInput, CoinType nRand)
	{
		using namespace std;
		if (nInput == nRand)
		{
			settextcol(RED);
			cout << "�� �߽��ϴ�. ������ ���߾����ϴ�." << endl;
			nTotalScore++;
			nTotalWin++; // �̱� ȸ���� �ϳ� ����
		}
		else // CoinType�� �ٸ�
		{
			settextcol(BLUE);
			cout << "�ƽ��׿�. ���� ������ Ʋ�Ƚ��ϴ�." << endl;
			nTotalScore--;
		}
		settextcol(YELLOW);
		cout << "���� ���ھ�� " << nTotalScore << "�Դϴ�." << endl << endl;
		settextcol(DARK_BLUE);
		cout << "���� �·��� " << getWinRatio() << "%�Դϴ�." << endl << endl;
	}
}