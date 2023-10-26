// TestFileVector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream> // file 처리
#include <string> // string(문자열) 처리

int main()
{
	using namespace std;
	// 파일에 정보 저장(save): 텍스트, 이진수(binary)
	ofstream outfile("test.txt"); // output file stream
	outfile << 10 << endl;
	outfile << 10.1234 << endl;
	outfile << 'm' << endl;
	outfile << "C++" << endl;

	// 파일에서 정보 읽기, 불러오기(load): 텍스트, 이진수
	ifstream infile("test.txt"); // input file stream
	int n; infile >> n;
	cout << n << endl;
	double x; infile >> x;
	cout << x << endl;
	char c; infile >> c;
	cout << c << endl;
	//std::string str;
	string str; infile >> str; // 단어 단위로 파일에서 문자열 입력
	cout << str << endl;
}