#pragma once

#include <iostream>
#include "LibConsole.hpp"

// 원칙: 파일명은 클래스명은 같이(의무는 아니고 권고)
class TimesTableGame // 코드 블록의 캡슐화
{
public: // public group(외부에서 접근 가능: C 언어의 구조체(struct)와 동일)
	// 생성자(constructor): 클래스명과 같은 이름을 가진 멤버 함수
	TimesTableGame(void)
	{
		using namespace std;
		cout << "Constructor is called." << endl;
	}
	// 소멸자, 파괴자(destructor): 클래스명 앞에 ~(not 의미)를 붙인 멤버 함수
	~TimesTableGame()
	{
		using namespace std;
		cout << "Destructor is called." << endl;
	}

	// 메소드(method): 멤버 함수
	void printTimesTable(int i, int jMax);
	void printAllTimesTable(int nTimesMax);
	void printLogo(void);

private: // private group(외부에서 접근 불가능)
};

// 메소드 정의: 클래스의 멤버임을 명시하기 위해 콜론을 2개 사용
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
}

inline void TimesTableGame::printAllTimesTable(int nTimesMax)
{
	using namespace std;
	for (int i = 1; i <= nTimesMax; i++)
	{
		printTimesTable(i, nTimesMax);
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
	cout << "===========" << endl;
}
