#pragma once	// #은 컴파일러 지시자; pragma(pragmatic, 개선하는); once(헤더 파일을 한 번만 추가)

//#include <stdio.h> // printf() 선언
#include <iostream>

// namespace namespace명 {...}
namespace mglib
{
	// inline(인라인): 함수 정의를 #define(매크로)처럼 사용 가능; 일반 함수 정의보다 실행 파일 크기는 커지지만 실행 속도가 빨라짐(코드 블록을 교체하기 때문)
	inline void printTimesTable(int i, int jMax)
	{
		using namespace std;
		//printf("[%d단 출력]\n", i);
		cout << '[' << i << "단 출력]" << endl;
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
