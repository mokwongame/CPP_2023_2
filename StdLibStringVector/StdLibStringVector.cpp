// StdLibStringVector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// printf의 헤더 파일 <stdlib.h>
#include <iostream>
#include <string> // 표준 라이브러리 string의 헤더 파일

int main()
{
	using namespace std;
	// Microsoft Learn 활용
	// string은 basic_string의 상속
	// C++ 표준 라이브러리의 함수명 기술 방법: snake case(뱀): snake case란 이름을 표현 -> snake_case(소문자 사용, 단어 연결에는 _), camel_case, pascal_case
	// camel case(낙타): 자바 스타일, camelCase, pascalCase, snakeCase, Pascal case(파스칼): Microsoft 스타일, PascalCase, CamelCase, SnakeCase
	// C 언어에서 _ 사용: 표준 함수, OS 지원 함수(낮은 수준) -> __max(), __min()
	string str = "test of string"; // namespace std에 정의
	cout << str << endl;
	str = "10"; // 문자열
	int i = stoi(str); // 숫자인 정수: string to integer
	cout << "i = " << i << endl;
	str = "10.1234";
	double x = stod(str); // string to double
	cout << "x = " << x << endl;
	str = to_string(-20);
	cout << str << endl;
	str = to_string(-1e30);
	cout << str << endl;
	//cout << "정수 입력 하세요. 입력: ";
	//cin >> i;
	//cout << endl << "i = " << i << endl;
	//cout << "문자열을 입력하세요. 입력: ";
	//cin >> str; // 문자열을 단어 단위로 입력: 공백이 있으면 그 앞에 글자까지만 입력
	//cout << endl << "str = " << str << endl;
	// 한 줄 전체를 입력: getline()
	//cout << "문자열을 입력하세요. 입력: ";
	//getline(cin, str);
	//cout << endl << "str = " << str << endl;
	//cout << "문자열의 문자 개수(strlen) = " << str.length() << endl;

	str = "";
	cout << str.empty() << endl; // 문자열이 비었으면(empty) true 반환
	str = "String for for loop";
	cout << str.empty() << endl; // 문자열이 차있으면(not empty) false 반환
	const char* ptr = str.c_str(); // C-style string을 반환: snake case(뱀 모양, 뱀 격식)
	cout << ptr << endl;
	for (int i = 0; i < str.length(); i++)
		cout << str[i] << endl;
	cout << endl << endl;
	for (char c : str)
		cout << c << endl;
}