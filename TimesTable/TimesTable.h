#pragma once	// #�� �����Ϸ� ������; pragma(pragmatic, �����ϴ�); once(��� ������ �� ���� �߰�)

//#include <stdio.h> // printf() ����
#include <iostream>
#include "LibConsole.hpp" // GitHub���� LibConsole.h(C ����)�� LibConsole.hpp(h++: C++ ����)�� �̸� �ٿ�ε�

// namespace namespace�� {...}
namespace timesTableDisplay
{
	// inline(�ζ���): �Լ� ���Ǹ� #define(��ũ��)ó�� ��� ����; �Ϲ� �Լ� ���Ǻ��� ���� ���� ũ��� Ŀ������ ���� �ӵ��� ������(�ڵ� ����� ��ü�ϱ� ����)
	inline void printTimesTable(int i, int jMax)
	{
		using namespace mglib;
		settextcol(RED); // ����ϴ� ���ڻ��� RED�� ����
		using namespace std;
		//printf("[%d�� ���]\n", i);
		cout << '[' << i << "�� ���]" << endl;
		for (int j = 1; j <= jMax; j++)
		{
			//printf("%d x %d = %d\n", i, j, i * j);
			cout << i << " x " << j << " = " << i * j << endl;
		}
	}

	inline void printAllTimesTable(void)
	{
		using namespace std;
		for (int i = 1; i <= 9; i++)
		{
			printTimesTable(i, 20);
			//printf("\n");
			cout << endl;
		}
	}
}
