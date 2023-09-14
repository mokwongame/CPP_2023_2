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

// 구구단(times table, multiplication table) 출력
void main(void)
{
	printAllTimesTable();
}