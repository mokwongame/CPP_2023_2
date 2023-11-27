// TestFile.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream> // file stream

int main()
{
	using namespace std;
	//std::ofstream file;
	ofstream file("test.txt"); // text.txt 이름의 파일 열기; 파일 없는 경우는 파일 생성
	file << "This is my first file test." << endl;
	int i = 30;
	file << "i = " << 30 << endl;
	file.close(); // 다 쓰면 파일 닫기
}
