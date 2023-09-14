#pragma once	// #�� �����Ϸ� ������; pragma(pragmatic, �����ϴ�); once(��� ������ �� ���� �߰�)

#include <stdio.h> // printf() ����

void printTimesTable(int i, int jMax)
{
	printf("[%d�� ���]\n", i);
	for (int j = 1; j <= jMax; j++)
	{
		printf("%d x %d = %d\n", i, j, i * j);
	}
}

void printAllTimesTable(void)
{
	for (int i = 1; i <= 9; i++)
	{
		printTimesTable(i, 20);
		printf("\n");
	}
}
