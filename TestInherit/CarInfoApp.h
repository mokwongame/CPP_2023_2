#pragma once

#include <iostream>
#include "Sedan.h"
#include "Suv.h"

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
	Suv m_suv;

	void showMenu(void) const;
	int inputMenu(void) const;
	int inputInt(int nMin, int nMax) const;
	double inputDouble(void) const;
	void printMaxSpeedRange(void); // 내부 코드에서 프로퍼티를 바꾸기 때문에 함수 선언 마지막에 const를 쓸 수 없음
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
			break;
		case 2:
			cout << endl << m_suv << endl;
			break;
		case 3:
			printMaxSpeedRange();
			break;
		case 4:
			return;
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

inline double CarInfoApp::inputDouble(void) const
{
	using namespace std;
	double x = 0.;
	cin >> x;
	while (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "다시 입력하세요: ";
		cin >> x;
	}
	return x;
}

inline void CarInfoApp::printMaxSpeedRange(void)
{
	using namespace std;
	cout << endl << "1. Sedan, 2: SUV" << endl;
	cout << "차량 종류를 선택하세요: ";
	int nCar = inputInt(1, 2);
	cout << endl << "기어(1~4)를 선택하세요: ";
	int nGear = inputInt(1, 4);
	cout << endl << "이동 시간(단위: 시)을 선택하세요: ";
	double hour = inputDouble();

	switch (nCar)
	{
	case 1:
		m_sedan.setGear(nGear);
		cout << endl;
		m_sedan.printMaxSpeed();
		break;
	case 2:
		m_suv.setGear(nGear);
		cout << endl;
		m_suv.printMaxSpeed();
		break;
	}
}
