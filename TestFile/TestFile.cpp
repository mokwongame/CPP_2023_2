// TestFile.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream> // file stream
#include <string>

int main()
{
	using namespace std;
	//std::ofstream file;
	//ofstream file("test.txt"); // text.txt 이름의 파일 열기; 파일 없는 경우는 파일 생성; 덮어쓰기
	ofstream file("test.txt", ios::app); // 덧붙여쓰기; append(app) 의미
	file << "This is my first file test." << endl;
	int i = -500;
	file << "i = " << i << endl;
	file.close(); // 다 쓰면 파일 닫기

	ifstream fileIn("test.txt");
	string str;
	fileIn >> str; // 문장이 아니고 단어가 넘어옴
	cout << str << endl;
	getline(fileIn, str); // 엔터로 끝나는 문장 하나를 얻음
	cout << str << endl;
	fileIn >> str; // i 가져오기
	cout << str << endl;
	fileIn >> str; // = 가져오기
	int j; fileIn >> j; // -500 가져오기
	cout << "j = " << j << endl;
}
