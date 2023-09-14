#include <stdio.h> // printf() 선언

// 구구단(times table, multiplication table) 출력
void main(void)
{
	// 1x1, 1x2, ...
	// 반복문: for, while
	// for (초기값; 판별식; 증감) {...}
	for (int i = 1; i <= 9; i++)
	{
		printf("[%d단 출력]\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}

}