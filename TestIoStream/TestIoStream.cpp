// TestIoStream.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
	using namespace std;
	// 콘솔로 출력: console output; char로 출력 -> cout(char output)
	// cout은 예전 C의 printf()에 해당: <stdio.h>
	cout.sync_with_stdio(); // Standard I/O와 동기 맞춤
	cout << "Hello World!" << endl << "This is my first ostream test." << flush << endl; // endl: end of line(줄의 끝; 엔터); flush: 현재 출력 요청을 완료
	int i = 10;
	cout << "i = " << i << endl;
	double x = 1.234567890123456;
	cout.precision(50); // double의 출력 정밀도 조정
	cout << "x = " << x << endl;

	// cin: 콘솔 입력 -> cin(char input)
	// cin은 예전 scanf()에 해당: <stdio.h>
	//cin >> i;
	//if (!cin)
	//{
	//	cout << "정수를 입력하세요." << endl;
	//	cin.clear(); // cin에 생긴 오류를 지움(clear)
	//	cin.ignore(10000, '\n'); // cin 입력을 무시(ignore): 10000개를 무시하거나 엔터를 만날 때까지
	//}
	//else cout << endl << "i = " << i << endl;
	//cin >> x;
	//cout.precision(4);
	//cout << endl << "x = " << x << endl;
	string str;
	//cin >> str;
	getline(cin, str);
	cout << endl << "str = [" << str << "]" << endl;
}