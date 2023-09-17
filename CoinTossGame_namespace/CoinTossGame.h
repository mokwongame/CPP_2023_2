#pragma once // #: 컴파일러 지시자의 시작; #pragma 실용적인(pragmatic); once: 현재 헤더 파일을 한 번만 include(포함시킴), 헤더 파일간에 include할 때 한 번만 추가, 소스 파일에는 여러 번 include될 수 있음

#include <stdio.h>
#include <conio.h>
#include "LibConsole.h"
#include "LibGameTool.h"

// C++: 전역 변수, 함수를 사용하지 않음 -> 어쩔 수 없이 써야 함: namespace로 캡슐화

// namespace namespace명 {...}
// 멤버: namespace 코드 블록 안에 있는 요소(상수, 변수, 함수)
namespace mglib // Mokwon Game Library(함수의 집합체)
{
	enum CoinType
	{
		CT_BACK = 0, CT_FRONT, CT_NULL
	};

	// 변수 선언: 외부(external) 변수 - 다른 곳에 선언된 변수를 현재 위치 사용하기 위해 외부 선언한 변수
	extern int g_totalScore;

	// 함수 선언: 함수 정의 없이 함수 선언만 헤더 파일에 남아야 함

	// 함수 정의 -> cpp 소스 파일로 옮겨야 됨
	// 인라인(inline) 함수: 함수 정의이지만 헤더 파일에 남아도 문제가 안됨; 함수의 호출 속도가 빨라짐; 실행 파일 크기가 커짐(함수 호출을 코드 블록으로 교체)
	// inline 의미: 함수 정의이지만 현재 코드 블록을 함수 호출이 있을 때 교체
	// #define: 코드 블록을 그대로 교체
	inline void showLogo(void)
	{
		settextcol(GREEN);
		puts("=======================");
		puts("   My Coin Toss Game   ");
		puts("   Version 1.0");
		puts("=======================\n");
		settextcol(GRAY);
	}

	//inline enum CoinType inputCoinType(void) // C 스타일
	inline CoinType inputCoinType(void) // C++ 스타일: 군더더기인 enum를 생략 가능; CoinType를 마치 자료형처럼 쉽게 사용
	{
		puts("\n동전 앞면은 F, 동전 뒷면은 B를 입력");
		printf("당신의 선택은?");
		char ch = _getche(); // echo하면서 Enter없이 한 글자 입력
		if (ch == 'F' || ch == 'f') return CT_FRONT;
		else if (ch == 'B' || ch == 'b') return CT_BACK;
		else
		{
			puts("잘못 입력하셨습니다.");
			return CT_NULL;
		}
	}

	inline CoinType randomCoinType(void)
	{
		puts("\n\n이제 동전을 던집니다.");
		int nRand = randrange(0, 2); // 0, 1
		if (nRand == 0) puts("동전은 뒷면입니다.\n");
		else puts("동전은 앞면입니다.\n");
		return (CoinType)nRand;
	}

	inline void printResult(int score, double winRatio)
	{
		printf("\n현재 득점은 %d입니다.", score);
		printf("\n현재 승률은 %g입니다.\n", winRatio);
	}
}