#include <stdio.h> // printf() ����

// ������(times table, multiplication table) ���
void main(void)
{
	// 1x1, 1x2, ...
	// �ݺ���: for, while
	// for (�ʱⰪ; �Ǻ���; ����) {...}
	for (int i = 1; i <= 9; i++)
	{
		printf("[%d�� ���]\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}

}