#pragma once

#include <stdlib.h>
#include <iostream>
#include <string> // C++의 표준 라이브러리: C++의 표준 문자열(string)은 string; string은 namespace std에 정의됨
#include "LibConsole.hpp"

#define DEF_TIMES_MAX	(9) // 구구단 출력의 디폴트 출력 단수

// 원칙: 파일명은 클래스명은 같이(의무는 아니고 권고)
class TimesTableGame // 코드 블록의 캡슐화
{
public: // public group(외부에서 접근 가능: C 언어의 구조체(struct)와 동일)
	// 생성자(constructor): 클래스명과 같은 이름을 가진 멤버 함수
	TimesTableGame(void)
	{
		using namespace std;
		//cout << "Constructor is called." << endl;
	}
	// 소멸자, 파괴자(destructor): 클래스명 앞에 ~(not 의미)를 붙인 멤버 함수
	~TimesTableGame()
	{
		using namespace std;
		//cout << "Destructor is called." << endl;
	}

	// 메소드(method): 멤버 함수
	void printTimesTable(int i, int jMax);
	void printAllTimesTable(int nTimesMax);
	void printLogo(void);
	void printMenu(void);

	int inputMenu(void); // 출력: 사용자의 메뉴 선택 번호
	int inputInt(const std::string& sInput); // 정수 입력: sInput은 입력시 출력할 문장
	int inputTimesNum(void); // 출력: 원하는 단수
	int inputMaxTimesNum(void); // 출력: 출력할 최대 단수
	int inputGameTimesNum(void); // 출력: 원하는 단수

	void start(void);
	void startGame(void);
	void exeMenu(int nMenu);

private: // private group(외부에서 접근 불가능)
};

// 메소드 정의: 클래스의 멤버임을 명시하기 위해 콜론을 2개 사용
// 클래스 정의에서 멤버 접근은 콜론(:) 2개
inline void TimesTableGame::printTimesTable(int i, int jMax)
{
	using namespace mglib;
	//int nColor = i % WHITE; // 0~14
	int nColor = i % WHITE + 1; // 1~15
	settextcol(nColor); // 출력하는 글자색을 RED로 변경
	using namespace std;
	//printf("[%d단 출력]\n", i);
	cout << '[' << i << "단 출력]" << endl;
	for (int j = 1; j <= jMax; j++)
	{
		//printf("%d x %d = %d\n", i, j, i * j);
		cout << i << " x " << j << " = " << i * j << endl;
	}
	cout << endl;
}

inline void TimesTableGame::printAllTimesTable(int nTimesMax)
{
	using namespace std;
	for (int i = 1; i <= nTimesMax; i++)
	{
		printTimesTable(i, __max(nTimesMax, DEF_TIMES_MAX));
		//printf("\n");
		cout << endl;
	}
}

inline void TimesTableGame::printLogo(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(YELLOW);
	cout << "===========" << endl;
	cout << "Times Table Display" << endl;
	cout << "===========" << endl << endl;
}

inline void TimesTableGame::printMenu(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(RED);
	cout << "1. 모든 구구단 출력" << endl;
	cout << "2. 원하는 단만 출력" << endl;
	cout << "3. 구구단 게임" << endl;
}

inline int TimesTableGame::inputMenu(void)
{
	using namespace mglib;
	using namespace std;
	settextcol(WHITE);
	cout << "원하는 번호를 선택하세요. 번호는? ";
	int nMenu;
	cin >> nMenu; // cin: console input(보통 키보드)
	return nMenu;
}

// Reference(참조자): 변수를 접근할 때 원본의 참조 위치를 사용; 자료형 뒤 &를 기호 사용; 원본은 그대로 이고 참조 위치로만 접근
// const: 상수 의미; sInput을 inputInt()에서 바꾸지 않음
inline int TimesTableGame::inputInt(const std::string& sInput)
{
	using namespace mglib;
	using namespace std;
	settextcol(WHITE);
	cout << sInput;
	int nInput;
	cin >> nInput; // cin: console input(보통 키보드)
	return nInput;
}

inline int TimesTableGame::inputTimesNum(void)
{
	return inputInt("출력하기 원하는 단수를 입력하세요. 단수는? ");
}

inline int TimesTableGame::inputMaxTimesNum(void)
{
	return inputInt("출력할 최대 단수를 입력하세요. 단수는? ");
}

inline int TimesTableGame::inputGameTimesNum(void)
{
	return inputInt("구구단을 연습할 단수를 입력하세요. 단수는? ");
}

inline void TimesTableGame::start(void)
{
	while (1)
	{
		// 메뉴 출력
		printMenu();
		// 사용자 입력
		int nMenu = inputMenu();
		//cout << "입력한 번호: " << nMenu;
		exeMenu(nMenu);
	}
}

inline void TimesTableGame::startGame(void)
{
	int nTimes = inputGameTimesNum();
	while (1)
	{

	}
}

inline void TimesTableGame::exeMenu(int nMenu)
{
	int nMaxTimes, nTimes;
	switch (nMenu)
	{
	case 1: // 모든 구구단 출력
		nMaxTimes = inputMaxTimesNum();
		printAllTimesTable(nMaxTimes);
		break;
	case 2: // 원하는 단만 출력
		nTimes = inputTimesNum();
		printTimesTable(nTimes, __max(nTimes, DEF_TIMES_MAX));
		break;
	case 3: // 구구단 게임
		startGame();
		break;
	}
}
