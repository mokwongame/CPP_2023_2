#pragma once

#include <iostream>
#include "Sedan.h"

#define MENU_MIN	(1)
#define MENU_MAX	(4)

class CarInfoApp
{
public:
	CarInfoApp(void) {}
	~CarInfoApp() {}

	void run(void);

private:
	Sedan m_sedan;

	void showMenu(void) const;
	int inputMenu(void) const;
	int inputInt(int nMin, int nMax) const;
};

inline void CarInfoApp::run(void)
{
	using namespace std;
	while (1)
	{
		showMenu();
		int nInput = inputMenu();
		switch (nInput)
		{
		case 1:
			cout << endl << m_sedan << endl;
		}
	}
}

inline void CarInfoApp::showMenu(void) const
{
	using namespace std;
	cout << "=========" << endl;
	cout << "1. Sedan 정보 보기" << endl;
	cout << "2. SUV 정보 보기" << endl;
	cout << "3. 기어별 속도/이동 거리 계산" << endl;
	cout << "4. 종료" << endl;
	cout << "=========" << endl;
}

inline int CarInfoApp::inputMenu(void) const
{
	using namespace std;
	cout << "메뉴를 입력하세요: ";
	int nMenu = inputInt(MENU_MIN, MENU_MAX);
	return nMenu;
}

inline int CarInfoApp::inputInt(int nMin, int nMax) const
{
	using namespace std;
	int nInput = 0;
	cin >> nInput;
	while (!cin || nInput < nMin || nInput > nMax)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "다시 입력하세요: ";
		cin >> nInput;
	}
	return nInput;
}
