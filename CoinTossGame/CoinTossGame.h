#pragma once // pragmatic(실용적인, 개선하는); 헤더 파일을 한 번만 include

#include <stdio.h> // VS 헤더 파일 폴더 검색
#include "LibConsole.h" // 현재 폴더 검색
#include "LibGameTool.h"

// namespace namespace명 {...}
// namespace(이름 공간): 특정한 이름으로 변수명과 함수명을 묶어서 계층화; 같은 변수와 같은 함수가 있어도 상관없음(namespace로 구별이 가능하기 때문)
namespace mglib
{
	// 상수 나열(enumeration): enum 상수나열명 {상수 선언};
	enum CoinType
	{
		CT_BACK = 0, CT_FRONT, CT_NULL
	}; // CT_FRONT=1, CT_NULL=2

	// 전역 변수 선언: {...} 바깥에 있는 변수 선언
	int nTotalScore = 0;

	// 함수 선언(헤더 파일) -> 함수 정의(소스 파일)
	CoinType inputCoin(void); // enum CoinType -> CoinType (C++: 새로운 자료형처럼 사용)
	CoinType randCoin(void);
	void checkCoin(enum CoinType nInput, enum CoinType nRand);

	// 함수 정의: 출력자료형 함수명(입력 선언, ...) {...} -> 헤더 파일에는 함수 정의하면 안됨
	// 인라인(inline) 함수: 헤더 파일에 함수 정의 가능
	inline CoinType inputCoin(void)
	{
		settextcol(GREEN);
		puts("동전 앞면(F)이나 뒷면(B)을 선택하세요."); // 문자열(string) 출력
		settextcol(WHITE);
		printf("당신의 선택은? ");
		char cInput = _getche(); // e: echo(반향)
		settextcol(GREEN);
		if (cInput == 'F' || cInput == 'f')
		{
			puts("\n앞면을 선택했습니다.");
			return CT_FRONT;
		}
		else if (cInput == 'B' || cInput == 'b')
		{
			puts("\n뒷면을 선택했습니다.");
			return CT_BACK;
		}
		else
		{
			settextcol(RED);
			puts("\n잘못 입력했습니다.");
			return CT_NULL;
		}
	}

	inline CoinType randCoin(void)
	{
		settextcol(BLUE);
		puts("아무 키나 누르면 동전을 던집니다.");
		_getch(); // 글자 한 자(char) 입력; echo X
		int nRand = randrange(0, 2); // (0, 2-1) 범위에서 정수 난수 발생
		CoinType nRandCoin = (CoinType)nRand; // type casting(형 선정)
		settextcol(GREEN);
		if (nRandCoin == CT_BACK)
			puts("나온 동전은 뒷면입니다.");
		else puts("나온 동전은 앞면입니다.");
		return nRandCoin;
	}

	inline void checkCoin(CoinType nInput, CoinType nRand)
	{
		if (nInput == nRand)
		{
			settextcol(RED);
			puts("잘 했습니다. 동전을 맞추었습니다.");
			nTotalScore++;
		}
		else // CoinType이 다름
		{
			settextcol(BLUE);
			puts("아쉽네요. 동전 선택이 틀렸습니다.");
			nTotalScore--;
		}
		settextcol(YELLOW);
		printf("현재 스코어는 %d입니다.\n\n", nTotalScore);
	}
}