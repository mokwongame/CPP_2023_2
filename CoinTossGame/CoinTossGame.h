#pragma once // pragmatic(실용적인, 개선하는); 헤더 파일을 한 번만 include; 헤더 파일이 다른 헤더 파일에 중복 include 되지 않음

//#include <stdio.h> // VS 헤더 파일 폴더 검색: C 방식의 표준 입출력(standard input/out)
#include <iostream> // C++ 방식의 표준 입출력: 표준 헤더 파일에 .h, .hpp(확장자)가 없음
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

	// 전역 변수 선언: {...} 바깥에 있는 변수 선언 -> 헤더 파일에 넣을 수 없음(소스 파일에 여러 번 include 되면 링커 에러 발생
	// 외부(external) 변수로 선언
	extern int nTotalScore; // int nTotalScore는 여기 선언되지 않고 다른 파일에 있음; 외부 변수는 선언할 때 초기화 불가능
	extern int nTotalTry;
	extern int nTotalWin;

	// 함수 선언(헤더 파일) -> 함수 정의(소스 파일)
	CoinType inputCoin(void); // enum CoinType -> CoinType (C++: 새로운 자료형처럼 사용)
	CoinType randCoin(void);
	void checkCoin(enum CoinType nInput, enum CoinType nRand);

	inline void showLogo(void)
	{
		using namespace std;
		settextcol(RED);
		cout << "============" << endl;
		cout << " 동전 던지기 게임" << endl;
		cout << " CHO, YH" << endl;
		cout << "============" << endl << endl;
	}
	// 함수 정의: 출력자료형 함수명(입력 선언, ...) {...} -> 헤더 파일에는 함수 정의하면 안됨
	// 인라인(inline) 함수: 헤더 파일에 함수 정의 가능
	inline CoinType inputCoin(void)
	{
		using namespace std; // 표준 namespace를 사용
		settextcol(GREEN);
		cout << "동전 앞면(F)이나 뒷면(B)을 선택하세요." << endl; // 문자열(string) 출력; <<: 스트림 cout에 출력하는 기호; cout(console output); endl: end of line(엔터 키)
		settextcol(WHITE);
		cout << "당신의 선택은? ";
		char cInput = _getche(); // e: echo(반향)
		settextcol(GREEN);
		if (cInput == 'F' || cInput == 'f')
		{
			cout << endl << "앞면을 선택했습니다." << endl;
			return CT_FRONT;
		}
		else if (cInput == 'B' || cInput == 'b')
		{
			cout << endl << "뒷면을 선택했습니다." << endl;
			return CT_BACK;
		}
		else
		{
			settextcol(RED);
			cout << endl << "잘못 입력했습니다." << endl;
			return CT_NULL;
		}
	}

	inline CoinType randCoin(void)
	{
		settextcol(BLUE);
		std::cout << "아무 키나 누르면 동전을 던집니다." << std::endl;
		_getch(); // 글자 한 자(char) 입력; echo X
		int nRand = randrange(0, 2); // (0, 2-1) 범위에서 정수 난수 발생
		nTotalTry++; // 시도 회수를 하나 증가
		CoinType nRandCoin = (CoinType)nRand; // type casting(형 선정)
		settextcol(GREEN);
		if (nRandCoin == CT_BACK)
			std::cout << "나온 동전은 뒷면입니다." << std::endl;
		else std::cout << "나온 동전은 앞면입니다." << std::endl;
		return nRandCoin;
	}

	inline double getWinRatio(void)
	{
		// 승률 계산
		return 0.;
	}
	inline void checkCoin(CoinType nInput, CoinType nRand)
	{
		using namespace std;
		if (nInput == nRand)
		{
			settextcol(RED);
			cout << "잘 했습니다. 동전을 맞추었습니다." << endl;
			nTotalScore++;
			nTotalWin++; // 이긴 회수를 하나 증가
		}
		else // CoinType이 다름
		{
			settextcol(BLUE);
			cout << "아쉽네요. 동전 선택이 틀렸습니다." << endl;
			nTotalScore--;
		}
		settextcol(YELLOW);
		cout << "현재 스코어는 " << nTotalScore << "입니다." << endl << endl;
		settextcol(DARK_BLUE);
		cout << "현재 승률은 " << getWinRatio() << "%입니다." << endl << endl;
	}
}