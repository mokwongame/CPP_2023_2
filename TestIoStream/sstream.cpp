#include <iostream>
#include <sstream> // string stream

int main()
{
	using namespace std;
	stringstream ss("This is my first ss test. Hello, world!  ");
	// ss에서 입력 받음
	string str;
	ss >> str;
	cout << "[" << str << "]" << endl;
	ss >> str;
	cout << "[" << str << "]" << endl;
	ss >> str;
	cout << "[" << str << "]" << endl;
	cout << ss.str() << endl;

	// ss쪽에 출력
	ss << "Mokwon" << endl;
	cout << endl << ss.str() << endl; // 앞부분부터 덮어쓰기로 문자열을 ss에 출력
}