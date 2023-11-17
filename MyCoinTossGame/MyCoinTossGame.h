#pragma once

#include <iostream>
#include <string>
#include "LibConsole.hpp"
#include "LibGameTool.hpp"

#define MAX_STREAM_SIZE (10000)
#define DEF_SCORE	(100)

enum class CoinType
{
	CT_BACK = 0, CT_FRONT, CT_NULL, CT_EXIT
}; // CT_FRONT=1, CT_NULL=2

class MyCoinTossGame
{
public:
	MyCoinTossGame(void) { mglib::randseed(); }
	~MyCoinTossGame() {}

	void play(void);

private:
	// private ������Ƽ
	int nTotalScore = 0;
	int nTotalTry = 0;
	int nTotalWin = 0;
	std::string userName;

	void showLogo(void) const;
	void showMenu(void) const;
	CoinType inputCoin(void) const;
	std::string inputName(void) const;
	int inputMenu(void) const;
	CoinType randCoin(void);
	void randScore(void);
	double getWinRatio(void) const;
	void checkCoin(CoinType nInput, CoinType nRand);
	void startGame(void);
	void gameStat(void) const;
};

inline void MyCoinTossGame::play(void)
{
	using namespace std;
	using namespace mglib;

	showLogo();
	userName = inputName();
	settextcol(YELLOW);
	cout << userName << "�� �湮�� ȯ���մϴ�." << endl << endl;
	randScore();

	while (1)
	{
		showMenu();
		int nMenu = inputMenu();
		while (nMenu < 1 || nMenu > 3) // �߸��� �Է��� �ִ� ���
		{
			settextcol(RED);
			cout << "�߸��� �޴� ��ȣ�Դϴ�. �ٽ� �Է��ؾ� �մϴ�." << endl;
			nMenu = inputMenu();
		}

		switch (nMenu)
		{
		case 1: // ���� ����
			startGame();
			break;
		case 2: // ���� ���
			gameStat();
			break;
		case 3: // ���� ����
			return;
		}
	}
}

inline void MyCoinTossGame::showLogo(void) const
{
	using namespace std;
	using namespace mglib;
	//mglib::settextcol(mglib::RED);
	settextcol(RED);
	cout << "============" << endl;
	cout << " ���� ������ ����" << endl;
	cout << " CHO, YH" << endl;
	cout << "============" << endl << endl;
}

inline void MyCoinTossGame::showMenu(void) const
{
	using namespace std;
	using namespace mglib;
	//mglib::settextcol(mglib::RED);
	settextcol(RED);
	cout << "============" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���" << endl;
	cout << "3. ���� ����" << endl;
	cout << "============" << endl << endl;
}

inline CoinType MyCoinTossGame::inputCoin(void) const
{
	using namespace std; // ǥ�� namespace�� ���
	using namespace mglib;
	settextcol(GREEN);
	cout << "���� �ո�(F)�̳� �޸�(B)�� �����ϼ���. �������� X�� ��������." << endl; // ���ڿ�(string) ���; <<: ��Ʈ�� cout�� ����ϴ� ��ȣ; cout(console output); endl: end of line(���� Ű)
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
	else if (cInput == 'X' || cInput == 'x')
	{
		cout << endl << "���� �����⸦ �����մϴ�." << endl << endl;
		return CoinType::CT_EXIT;
	}
	else
	{
		settextcol(RED);
		cout << endl << "�߸� �Է��߽��ϴ�." << endl;
		return CoinType::CT_NULL;
	}
}

inline std::string MyCoinTossGame::inputName(void) const
{
	using namespace std;
	using namespace mglib;
	settextcol(WHITE);
	cout << "����� �̸��� �Է��ϼ���: ";
	string name;
	cin >> name;
	return name;
}

inline int MyCoinTossGame::inputMenu(void) const
{
	using namespace std;
	using namespace mglib;
	settextcol(WHITE);
	cout << "���ϴ� �޴��� �Է��ϼ���: ";
	int nMenu;
	cin >> nMenu;
	if (!cin) // cin�� ���� ó��: ���� �Է��̾�� �ϳ� ���� ���� �Էµ� ���
	{
		cin.clear();
		cin.ignore(MAX_STREAM_SIZE, '\n'); // cin�� �Է°��� ����: 10000 ����Ʈ�� ���͸� ���� ������
	}
	return nMenu;
}

inline CoinType MyCoinTossGame::randCoin(void)
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

inline void MyCoinTossGame::randScore(void)
{
	using namespace std;
	using namespace mglib;

	settextcol(VIOLET);
	cout << "�⺻ ���� " << DEF_SCORE << "���� �ްڽ��ϱ� ? �ƴϸ� �귿�� ���� 10~200���� �ްڽ��ϱ� ? " << endl;
	cout << "1. �⺻ ����" << endl;
	cout << "2. �귿 ������" << endl;
	settextcol(WHITE);
	cout << "���ϴ� �޴��� �Է��ϼ���: ";
	int nMenu = inputMenu();
	while (nMenu < 1 || nMenu > 2)
	{
		settextcol(RED);
		cout << "�߸��� �޴� ��ȣ�Դϴ�. �ٽ� �Է��ؾ� �մϴ�." << endl;
		nMenu = inputMenu();
	}

	switch (nMenu)
	{
	case 1:
		nTotalScore = DEF_SCORE;
		break;
	case 2:
		nTotalScore = randrange(10, 200 + 1);
	}
	settextcol(YELLOW);
	cout << endl << "���� ȹ���� ������ " << nTotalScore << "���Դϴ�." << endl << endl;
}

inline double MyCoinTossGame::getWinRatio(void) const
{
	// �·� ���
	return nTotalWin / (double)nTotalTry * 100.;
}

inline void MyCoinTossGame::checkCoin(CoinType nInput, CoinType nRand)
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

inline void MyCoinTossGame::startGame(void)
{
	while (1) // ��, ���� �Ǵ�: 0���� �ƴ��� �Ǵ�
	{
		// namespace ��� ����: namespace��::�����
		// �ڷ��� ������ = �ʱⰪ;
		CoinType nInput = inputCoin(); // =: �Ҵ� ������(������ �� -> ���� ������ �Ҵ�)
		if (nInput == CoinType::CT_NULL) continue; // continue: �ݺ����� ó������ ���ư���
		else if (nInput == CoinType::CT_EXIT) return;
		// ���� ������: ���� �߻�
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
}

inline void MyCoinTossGame::gameStat(void) const
{
	using namespace std;
	using namespace mglib;

	double winRatio = (nTotalTry == 0) ? 0 : getWinRatio();

	settextcol(YELLOW);
	cout << endl << "���� ���ھ�� " << nTotalScore << "�Դϴ�." << endl;
	settextcol(DARK_BLUE);
	cout << "���� �·��� " << winRatio << "% (" << nTotalWin << "/" << nTotalTry << ")�Դϴ�." << endl << endl;
}

#undef MAX_STREAM_SIZE
#undef DEF_SCORE