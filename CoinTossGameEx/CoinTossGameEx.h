#pragma once

#include <iostream>
#include "LibConsole.hpp"
#include "LibGameTool.hpp"

enum class CoinType // enum class: ������ Ŭ����; ������ �� CoinType::CT_BACK ���� ���
{
	CT_BACK = 0, CT_FRONT, CT_NULL
}; // CT_FRONT=1, CT_NULL=2

class CoinTossGameEx
{
public:
	CoinTossGameEx(void)
	{}

	void play(void);

private:
	int nTotalScore = 0; // int nTotalScore�� ���� ������� �ʰ� �ٸ� ���Ͽ� ����; �ܺ� ������ ������ �� �ʱ�ȭ �Ұ���
	int nTotalTry = 0;
	int nTotalWin = 0;

	void showLogo(void);
	CoinType inputCoin(void);
	CoinType randCoin(void);
	double getWinRatio(void);
	void checkCoin(CoinType nInput, CoinType nRand);
};

inline void CoinTossGameEx::play(void)
{
	using namespace std; // std namespace ��ü ���
	using namespace mglib; // mglib namespace ��ü ���; mglib:: ���� ����� ���� ����
	showLogo();
	randseed(); // ���� �ʱ�ȭ; LibGameTool.h�� ����
	while (1) // ��, ���� �Ǵ�: 0���� �ƴ��� �Ǵ�
	{
		// namespace ��� ����: namespace��::�����
		// �ڷ��� ������ = �ʱⰪ;
		CoinType nInput = inputCoin(); // =: �Ҵ� ������(������ �� -> ���� ������ �Ҵ�)
		if (nInput == CoinType::CT_NULL) continue; // continue: �ݺ����� ó������ ���ư���
		// ���� ������: ���� �߻�
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
}

inline void CoinTossGameEx::showLogo(void)
{
	using namespace std;
	using namespace mglib;
	settextcol(RED);
	cout << "============" << endl;
	cout << " ���� ������ ����" << endl;
	cout << " CHO, YH" << endl;
	cout << "============" << endl << endl;
}

inline CoinType CoinTossGameEx::inputCoin(void)
{
	using namespace std; // ǥ�� namespace�� ���
	using namespace mglib;
	settextcol(GREEN);
	cout << "���� �ո�(F)�̳� �޸�(B)�� �����ϼ���." << endl; // ���ڿ�(string) ���; <<: ��Ʈ�� cout�� ����ϴ� ��ȣ; cout(console output); endl: end of line(���� Ű)
	settextcol(WHITE);
	cout << "����� ������? ";
	char cInput = _getche(); // e: echo(����)
	settextcol(GREEN);
	if (cInput == 'F' || cInput == 'f')
	{
		cout << endl << "�ո��� �����߽��ϴ�." << endl;
		return CoinType::CT_FRONT;
	}
	else if (cInput == 'B' || cInput == 'b')
	{
		cout << endl << "�޸��� �����߽��ϴ�." << endl;
		return CoinType::CT_BACK;
	}
	else
	{
		settextcol(RED);
		cout << endl << "�߸� �Է��߽��ϴ�." << endl;
		return CoinType::CT_NULL;
	}
}

inline CoinType CoinTossGameEx::randCoin(void)
{
	using namespace mglib;
	settextcol(BLUE);
	std::cout << "�ƹ� Ű�� ������ ������ �����ϴ�." << std::endl;
	_getch(); // ���� �� ��(char) �Է�; echo X
	int nRand = randrange(0, 2); // (0, 2-1) �������� ���� ���� �߻�
	nTotalTry++; // �õ� ȸ���� �ϳ� ����
	CoinType nRandCoin = (CoinType)nRand; // type casting(�� ����)
	settextcol(GREEN);
	if (nRandCoin == CoinType::CT_BACK)
		std::cout << "���� ������ �޸��Դϴ�." << std::endl;
	else std::cout << "���� ������ �ո��Դϴ�." << std::endl;
	return nRandCoin;
}

inline double CoinTossGameEx::getWinRatio(void)
{
	return nTotalWin / (double)nTotalTry * 100.;
}

inline void CoinTossGameEx::checkCoin(CoinType nInput, CoinType nRand)
{
	using namespace std;
	using namespace mglib;
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
