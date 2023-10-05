#pragma once

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
		cout << "Constructor is called." << endl;
	}
	// �Ҹ���, �ı���(destructor): Ŭ������ �տ� ~(not �ǹ�)�� ���� ��� �Լ�
	~TimesTableGame()
	{
		using namespace std;
		cout << "Destructor is called." << endl;
	}

	// �޼ҵ�(method): ��� �Լ�
	void printTimesTable(int i, int jMax);
	void printAllTimesTable(int nTimesMax);
	void printLogo(void);

private: // private group(�ܺο��� ���� �Ұ���)
};

// �޼ҵ� ����: Ŭ������ ������� ����ϱ� ���� �ݷ��� 2�� ���
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
	cout << "===========" << endl;
}
