// TestStdLib.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string> // 문자열 지원하는 헤더 파일
// 문자열 클래스 string은 namespace std에 정의됨

int main()
{
	// namespace 접근을 편하게 하기 위해
	using namespace std;
	// string이 없으면 char str[100]; strcpy(str, "This is my first string."); // strcpy: string copy
	string str = "This is my first string.";
	cout << str << endl;

	// 정수 처리
	str = "10"; // 문자열임; str[0] == '1', str[1] == '0'
	for (auto c : str) // 범위 기반 반복문; 여기서 auto 변수의 자료형은 char(왜냐하면 str이 문자 배열)
		cout << "문자 = " << c << ", ASCII = " << int(c) << endl;
	int i = stoi(str); // string to integer(정수)
	cout << "정수 i = " << i << endl << endl;

	// 실수 처리
	str = "1.234e10"; // 문자열임
	for (auto c : str)
		cout << "문자 = " << c << ", ASCII = " << int(c) << endl;
	double x = stod(str); // string to double
	cout << "실수 x = " << x << endl << endl;
	// 원래 실수는 float임; float의 정밀도를 2배(double)로 한 자료형 double
	float y = float(x);
	cout << "실수 y = " << y << endl << endl;
	int nLen = int(str.length()); // 문자열 길이
	cout << "str의 길이 = " << nLen << endl;
	bool bEmpty = str.empty(); // str이 비었는지 여부; 비었으면 return true, 차있으면 return false;
	cout << "str이 비었나요? " << bEmpty << endl;
	cout << "str이 채워졌나요? " << !bEmpty << endl; // ! 의미: NOT(부정) 연산자

	str = ""; // str을 널 문자열(null string)로 초기화
	nLen = int(str.size()); // size() 함수는 length() 함수와 동일
	cout << "str의 길이 = " << nLen << endl;
	bEmpty = str.empty();
	cout << "str이 비었나요? " << bEmpty << endl;
	cout << "str이 채워졌나요? " << !bEmpty << endl;
}