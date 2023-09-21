// TimesTable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*[구구단 출력(namespace 기능)]
1. 로고(타이틀)를 색깔 써서 출력
2. 구구단의 최대 단수를 입력 받음(cin >> i)
3. 최대 단수까지 구구단을 단별로 색깔을 바꾸어서 출력
4. 개발할 때는 namespace 사용해서 객체 지향적용
*/

//#include <stdio.h> // standard I/O
#include <iostream> // I/O stream
#include "TimesTable.h"

int main()
{
	// namespace에서 함수/변수 호출: namespace명::함수명, namespace명::변수명
	using namespace timesTableDisplay;
	using namespace std;

	printLogo();
	//mglib::settextcol(mglib::GREEN);
	using namespace mglib;
	settextcol(GREEN);
	cout << endl << "원하는 구구단의 최대 단수는? ";
	int nTimesMax;
	cin >> nTimesMax;
	// 구구단 출력
	// 고민: 단별로 색깔을 바꿀 때 WHITE(15)를 넘어가는 경우는?
	// 해결책: WHITE로 나누는 나머지 연산(%)을 쓰면 결과 = 0 ~ 14; 최종 출력 색깔 범위는 1~15가 되게 함
	cout << endl;
	printAllTimesTable(nTimesMax);
}