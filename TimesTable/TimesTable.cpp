// TimesTable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*[구구단 출력(namespace 기능)]
1. 로고를 색깔 써서 출력
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
	printAllTimesTable();

	// cout: console output, wcout: wide char(Unicode) cout
	// std: namespace(이름 공간) standard(표준)
	std::cout << "Hello World!" << std::endl; // endl: end of line(엔터 키)

	//std:: 대신 함수명/변수명을 그대로 쓰는 방법
	using namespace std;
	cout << "This is my first test." << endl;
}