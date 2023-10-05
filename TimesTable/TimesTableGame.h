#pragma once

#include <stdlib.h>
#include <iostream>
#include "LibConsole.hpp"

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
	int inputTimesNum(void); // ���: ���ϴ� �ܼ�
	int inputMaxTimesNum(void); // ���: ����� �ִ� �ܼ�

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
}

inline void TimesTableGame::printAllTimesTable(int nTimesMax)
{
	using namespace std;
	for (int i = 1; i <= nTimesMax; i++)
	{
		printTimesTable(i, nTimesMax);
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

inline int TimesTableGame::inputTimesNum(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(WHITE);
	cout << "����ϱ� ���ϴ� �ܼ��� �Է��ϼ���. �ܼ���? ";
	int nTimes;
	cin >> nTimes; // cin: console input(���� Ű����)
	return nTimes;
}

inline int TimesTableGame::inputMaxTimesNum(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(WHITE);
	cout << "����� �ִ� �ܼ��� �Է��ϼ���. �ܼ���? ";
	int nMaxTimes;
	cin >> nMaxTimes; // cin: console input(���� Ű����)
	return nMaxTimes;
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
		printTimesTable(nTimes, __max(nTimes, 9));
		break;
	}
}
