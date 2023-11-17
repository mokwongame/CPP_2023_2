#pragma once

#include <iostream>
#include <string>
#include "LibConsole.hpp"
#include "LibGameTool.hpp"

#define MAX_STREAM_SIZE (10000)
#define DEF_SCORE	(100)

enum class CoinType
{
	CT_BACK = 0, CT_FRONT, CT_NULL, CT_EXIT
}; // CT_FRONT=1, CT_NULL=2

class MyCoinTossGame
{
public:
	MyCoinTossGame(void) { mglib::randseed(); }
	~MyCoinTossGame() {}

	void play(void);

private:
	// private 프로퍼티
	int nTotalScore = 0;
	int nTotalTry = 0;
	int nTotalWin = 0;
	std::string userName;

	void showLogo(void) const;
	void showMenu(void) const;
	CoinType inputCoin(void) const;
	std::string inputName(void) const;
	int inputMenu(void) const;
	CoinType randCoin(void);
	void randScore(void);
	double getWinRatio(void) const;
	void checkCoin(CoinType nInput, CoinType nRand);
	void startGame(void);
	void gameStat(void) const;
};

inline void MyCoinTossGame::play(void)
{
	using namespace std;
	using namespace mglib;

	showLogo();
	userName = inputName();
	settextcol(YELLOW);
	cout << userName << "님 방문을 환영합니다." << endl << endl;
	randScore();

	while (1)
	{
		showMenu();
		int nMenu = inputMenu();
		while (nMenu < 1 || nMenu > 3) // 잘못된 입력이 있는 경우
		{
			settextcol(RED);
			cout << "잘못된 메뉴 번호입니다. 다시 입력해야 합니다." << endl;
			nMenu = inputMenu();
		}

		switch (nMenu)
		{
		case 1: // 게임 시작
			startGame();
			break;
		case 2: // 게임 통계
			gameStat();
			break;
		case 3: // 게임 종료
			return;
		}
	}
}

inline void MyCoinTossGame::showLogo(void) const
{
	using namespace std;
	using namespace mglib;
	//mglib::settextcol(mglib::RED);
	settextcol(RED);
	cout << "============" << endl;
	cout << " 동전 던지기 게임" << endl;
	cout << " CHO, YH" << endl;
	cout << "============" << endl << endl;
}

inline void MyCoinTossGame::showMenu(void) const
{
	using namespace std;
	using namespace mglib;
	//mglib::settextcol(mglib::RED);
	settextcol(RED);
	cout << "============" << endl;
	cout << "1. 게임 시작" << endl;
	cout << "2. 게임 통계" << endl;
	cout << "3. 게임 종료" << endl;
	cout << "============" << endl << endl;
}

inline CoinType MyCoinTossGame::inputCoin(void) const
{
	using namespace std; // 표준 namespace를 사용
	using namespace mglib;
	settextcol(GREEN);
	cout << "동전 앞면(F)이나 뒷면(B)을 선택하세요. 끝내려면 X를 누르세요." << endl; // 문자열(string) 출력; <<: 스트림 cout에 출력하는 기호; cout(console output); endl: end of line(엔터 키)
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
	else if (cInput == 'X' || cInput == 'x')
	{
		cout << endl << "동전 던지기를 종료합니다." << endl << endl;
		return CoinType::CT_EXIT;
	}
	else
	{
		settextcol(RED);
		cout << endl << "잘못 입력했습니다." << endl;
		return CoinType::CT_NULL;
	}
}

inline std::string MyCoinTossGame::inputName(void) const
{
	using namespace std;
	using namespace mglib;
	settextcol(WHITE);
	cout << "사용자 이름을 입력하세요: ";
	string name;
	cin >> name;
	return name;
}

inline int MyCoinTossGame::inputMenu(void) const
{
	using namespace std;
	using namespace mglib;
	settextcol(WHITE);
	cout << "원하는 메뉴를 입력하세요: ";
	int nMenu;
	cin >> nMenu;
	if (!cin) // cin의 에러 처리: 정수 입력이어야 하나 문자 등이 입력된 경우
	{
		cin.clear();
		cin.ignore(MAX_STREAM_SIZE, '\n'); // cin의 입력값을 무시: 10000 바이트나 엔터를 만날 때까지
	}
	return nMenu;
}

inline CoinType MyCoinTossGame::randCoin(void)
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

inline void MyCoinTossGame::randScore(void)
{
	using namespace std;
	using namespace mglib;

	settextcol(VIOLET);
	cout << "기본 득점 " << DEF_SCORE << "점을 받겠습니까 ? 아니면 룰렛을 돌려 10~200점을 받겠습니까 ? " << endl;
	cout << "1. 기본 득점" << endl;
	cout << "2. 룰렛 돌리기" << endl;
	settextcol(WHITE);
	cout << "원하는 메뉴를 입력하세요: ";
	int nMenu = inputMenu();
	while (nMenu < 1 || nMenu > 2)
	{
		settextcol(RED);
		cout << "잘못된 메뉴 번호입니다. 다시 입력해야 합니다." << endl;
		nMenu = inputMenu();
	}

	switch (nMenu)
	{
	case 1:
		nTotalScore = DEF_SCORE;
		break;
	case 2:
		nTotalScore = randrange(10, 200 + 1);
	}
	settextcol(YELLOW);
	cout << endl << "현재 획득한 득점은 " << nTotalScore << "점입니다." << endl << endl;
}

inline double MyCoinTossGame::getWinRatio(void) const
{
	// 승률 계산
	return nTotalWin / (double)nTotalTry * 100.;
}

inline void MyCoinTossGame::checkCoin(CoinType nInput, CoinType nRand)
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

inline void MyCoinTossGame::startGame(void)
{
	while (1) // 참, 거짓 판단: 0인지 아닌지 판단
	{
		// namespace 멤버 접근: namespace명::멤버명
		// 자료형 변수명 = 초기값;
		CoinType nInput = inputCoin(); // =: 할당 연산자(오른쪽 값 -> 왼쪽 변수에 할당)
		if (nInput == CoinType::CT_NULL) continue; // continue: 반복문의 처음으로 돌아가기
		else if (nInput == CoinType::CT_EXIT) return;
		// 동전 던지기: 난수 발생
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
}

inline void MyCoinTossGame::gameStat(void) const
{
	using namespace std;
	using namespace mglib;

	double winRatio = (nTotalTry == 0) ? 0 : getWinRatio();

	settextcol(YELLOW);
	cout << endl << "현재 스코어는 " << nTotalScore << "입니다." << endl;
	settextcol(DARK_BLUE);
	cout << "현재 승률은 " << winRatio << "% (" << nTotalWin << "/" << nTotalTry << ")입니다." << endl << endl;
}

#undef MAX_STREAM_SIZE
#undef DEF_SCORE