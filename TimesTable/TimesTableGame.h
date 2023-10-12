#pragma once

#include <stdlib.h>
#include <iostream>
#include <string> // C++�� ǥ�� ���̺귯��: C++�� ǥ�� ���ڿ�(string)�� string; string�� namespace std�� ���ǵ�
#include "LibConsole.hpp"

#define DEF_TIMES_MAX	(9) // ������ ����� ����Ʈ ��� �ܼ�

// ��Ģ: ���ϸ��� Ŭ�������� ����(�ǹ��� �ƴϰ� �ǰ�)
class TimesTableGame // �ڵ� ����� ĸ��ȭ
{
public: // public group(�ܺο��� ���� ����: C ����� ����ü(struct)�� ����)
	// ������(constructor): Ŭ������� ���� �̸��� ���� ��� �Լ�
	TimesTableGame(void)
	{
		using namespace std;
		//cout << "Constructor is called." << endl;
	}
	// �Ҹ���, �ı���(destructor): Ŭ������ �տ� ~(not �ǹ�)�� ���� ��� �Լ�
	~TimesTableGame()
	{
		using namespace std;
		//cout << "Destructor is called." << endl;
	}

	// �޼ҵ�(method): ��� �Լ�
	void printTimesTable(int i, int jMax);
	void printAllTimesTable(int nTimesMax);
	void printLogo(void);
	void printMenu(void);

	int inputMenu(void); // ���: ������� �޴� ���� ��ȣ
	int inputInt(const std::string& sInput); // ���� �Է�: sInput�� �Է½� ����� ����
	int inputTimesNum(void); // ���: ���ϴ� �ܼ�
	int inputMaxTimesNum(void); // ���: ����� �ִ� �ܼ�
	int inputGameTimesNum(void); // ���: ���ϴ� �ܼ�

	void start(void);
	void startGame(void);
	void exeMenu(int nMenu);

private: // private group(�ܺο��� ���� �Ұ���)
};

// �޼ҵ� ����: Ŭ������ ������� ����ϱ� ���� �ݷ��� 2�� ���
// Ŭ���� ���ǿ��� ��� ������ �ݷ�(:) 2��
inline void TimesTableGame::printTimesTable(int i, int jMax)
{
	using namespace mglib;
	//int nColor = i % WHITE; // 0~14
	int nColor = i % WHITE + 1; // 1~15
	settextcol(nColor); // ����ϴ� ���ڻ��� RED�� ����
	using namespace std;
	//printf("[%d�� ���]\n", i);
	cout << '[' << i << "�� ���]" << endl;
	for (int j = 1; j <= jMax; j++)
	{
		//printf("%d x %d = %d\n", i, j, i * j);
		cout << i << " x " << j << " = " << i * j << endl;
	}
	cout << endl;
}

inline void TimesTableGame::printAllTimesTable(int nTimesMax)
{
	using namespace std;
	for (int i = 1; i <= nTimesMax; i++)
	{
		printTimesTable(i, __max(nTimesMax, DEF_TIMES_MAX));
		//printf("\n");
		cout << endl;
	}
}

inline void TimesTableGame::printLogo(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(YELLOW);
	cout << "===========" << endl;
	cout << "Times Table Display" << endl;
	cout << "===========" << endl << endl;
}

inline void TimesTableGame::printMenu(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(RED);
	cout << "1. ��� ������ ���" << endl;
	cout << "2. ���ϴ� �ܸ� ���" << endl;
	cout << "3. ������ ����" << endl;
}

inline int TimesTableGame::inputMenu(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(WHITE);
	cout << "���ϴ� ��ȣ�� �����ϼ���. ��ȣ��? ";
	int nMenu;
	cin >> nMenu; // cin: console input(���� Ű����)
	return nMenu;
}

// Reference(������): ������ ������ �� ������ ���� ��ġ�� ���; �ڷ��� �� &�� ��ȣ ���; ������ �״�� �̰� ���� ��ġ�θ� ����
// const: ��� �ǹ�; sInput�� inputInt()���� �ٲ��� ����
inline int TimesTableGame::inputInt(const std::string& sInput)
{
	using namespace mglib;
	using namespace std;
	settextcol(WHITE);
	cout << sInput;
	int nInput;
	cin >> nInput; // cin: console input(���� Ű����)
	return nInput;
}

inline int TimesTableGame::inputTimesNum(void)
{
	return inputInt("����ϱ� ���ϴ� �ܼ��� �Է��ϼ���. �ܼ���? ");
}

inline int TimesTableGame::inputMaxTimesNum(void)
{
	return inputInt("����� �ִ� �ܼ��� �Է��ϼ���. �ܼ���? ");
}

inline int TimesTableGame::inputGameTimesNum(void)
{
	return inputInt("�������� ������ �ܼ��� �Է��ϼ���. �ܼ���? ");
}

inline void TimesTableGame::start(void)
{
	while (1)
	{
		// �޴� ���
		printMenu();
		// ����� �Է�
		int nMenu = inputMenu();
		//cout << "�Է��� ��ȣ: " << nMenu;
		exeMenu(nMenu);
	}
}

inline void TimesTableGame::startGame(void)
{
	int nTimes = inputGameTimesNum();
	while (1)
	{

	}
}

inline void TimesTableGame::exeMenu(int nMenu)
{
	int nMaxTimes, nTimes;
	switch (nMenu)
	{
	case 1: // ��� ������ ���
		nMaxTimes = inputMaxTimesNum();
		printAllTimesTable(nMaxTimes);
		break;
	case 2: // ���ϴ� �ܸ� ���
		nTimes = inputTimesNum();
		printTimesTable(nTimes, __max(nTimes, DEF_TIMES_MAX));
		break;
	case 3: // ������ ����
		startGame();
		break;
	}
}
