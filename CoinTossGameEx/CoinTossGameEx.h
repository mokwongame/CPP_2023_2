#pragma once

#include <iostream>
#include "LibConsole.hpp"
#include "LibGameTool.hpp"

enum class CoinType // enum class: 열거형 클래스; 접근할 때 CoinType::CT_BACK 등을 사용
{
	CT_BACK = 0, CT_FRONT, CT_NULL
}; // CT_FRONT=1, CT_NULL=2

class CoinTossGameEx
{
public:
	CoinTossGameEx(void)
	{}

	void play(void);

private:
	int nTotalScore = 0; // int nTotalScore는 여기 선언되지 않고 다른 파일에 있음; 외부 변수는 선언할 때 초기화 불가능
	int nTotalTry = 0;
	int nTotalWin = 0;

	void showLogo(void);
	CoinType inputCoin(void);
	CoinType randCoin(void);
	double getWinRatio(void);
	void checkCoin(CoinType nInput, CoinType nRand);
};

inline void CoinTossGameEx::play(void)
{
	using namespace std; // std namespace 전체 사용
	using namespace mglib; // mglib namespace 전체 사용; mglib:: 없이 멤버에 접근 가능
	showLogo();
	randseed(); // 난수 초기화; LibGameTool.h에 정의
	while (1) // 참, 거짓 판단: 0인지 아닌지 판단
	{
		// namespace 멤버 접근: namespace명::멤버명
		// 자료형 변수명 = 초기값;
		CoinType nInput = inputCoin(); // =: 할당 연산자(오른쪽 값 -> 왼쪽 변수에 할당)
		if (nInput == CoinType::CT_NULL) continue; // continue: 반복문의 처음으로 돌아가기
		// 동전 던지기: 난수 발생
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
}

inline void CoinTossGameEx::showLogo(void)
{
	using namespace std;
	using namespace mglib;
	settextcol(RED);
	cout << "============" << endl;
	cout << " 동전 던지기 게임" << endl;
	cout << " CHO, YH" << endl;
	cout << "============" << endl << endl;
}

inline CoinType CoinTossGameEx::inputCoin(void)
{
	using namespace std; // 표준 namespace를 사용
	using namespace mglib;
	settextcol(GREEN);
	cout << "동전 앞면(F)이나 뒷면(B)을 선택하세요." << endl; // 문자열(string) 출력; <<: 스트림 cout에 출력하는 기호; cout(console output); endl: end of line(엔터 키)
	settextcol(WHITE);
	cout << "당신의 선택은? ";
	char cInput = _getche(); // e: echo(반향)
	settextcol(GREEN);
	if (cInput == 'F' || cInput == 'f')
	{
		cout << endl << "앞면을 선택했습니다." << endl;
		return CoinType::CT_FRONT;
	}
	else if (cInput == 'B' || cInput == 'b')
	{
		cout << endl << "뒷면을 선택했습니다." << endl;
		return CoinType::CT_BACK;
	}
	else
	{
		settextcol(RED);
		cout << endl << "잘못 입력했습니다." << endl;
		return CoinType::CT_NULL;
	}
}

inline CoinType CoinTossGameEx::randCoin(void)
{
	using namespace mglib;
	settextcol(BLUE);
	std::cout << "아무 키나 누르면 동전을 던집니다." << std::endl;
	_getch(); // 글자 한 자(char) 입력; echo X
	int nRand = randrange(0, 2); // (0, 2-1) 범위에서 정수 난수 발생
	nTotalTry++; // 시도 회수를 하나 증가
	CoinType nRandCoin = (CoinType)nRand; // type casting(형 선정)
	settextcol(GREEN);
	if (nRandCoin == CoinType::CT_BACK)
		std::cout << "나온 동전은 뒷면입니다." << std::endl;
	else std::cout << "나온 동전은 앞면입니다." << std::endl;
	return nRandCoin;
}

inline double CoinTossGameEx::getWinRatio(void)
{
	return nTotalWin / (double)nTotalTry * 100.;
}

inline void CoinTossGameEx::checkCoin(CoinType nInput, CoinType nRand)
{
	using namespace std;
	using namespace mglib;
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
