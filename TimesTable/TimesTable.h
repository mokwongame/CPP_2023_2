#pragma once	// #은 컴파일러 지시자; pragma(pragmatic, 개선하는); once(헤더 파일을 한 번만 추가)

#include <stdio.h> // printf() 선언

void printTimesTable(int i, int jMax)
{
	printf("[%d단 출력]\n", i);
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
