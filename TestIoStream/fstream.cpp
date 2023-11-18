#include <iostream>
#include <fstream> // file stream
#include <string>

int main()
{
	using namespace std;

	// cout, cin은 인스턴스; ofstream은 클래스
	ofstream file("test.txt"); // "test.txt"에 파일을 출력; 파일이 없으면 새로 만듦; 파일이 있으면 덮어쓰기
	//ofstream file("test.txt", ofstream::app); // 기존 파일에 덧붙이기; app은 append를 의미
	file << "This is my first try." << endl;
	int i = -30;
	file << i << endl;
	double x = -4.56;
	file << x << endl;
	file << "한글 사랑" << endl << endl;
	file.close(); // 인스턴스인 file이 소멸될 때 자동적으로 close()가 호출

	// 파일 입출력 종류: 텍스트 파일(ASCII 코드로 저장), 바이너리 파일(binary file, 이진 파일; 인코딩 그대로 저장)
	ofstream fileBin("testBin.txt", ofstream::binary);
	fileBin.write((char*)&i, sizeof(i));
	fileBin.write((char*)&x, sizeof(x));
	fileBin.close();

	ifstream fileIn("test.txt");
	string str;
	//fileIn >> str;
	getline(fileIn, str);
	cout << str;
	int j;
	fileIn >> j;
	cout << endl << "j = " << j << endl;
	double y;
	fileIn >> y;
	cout << "y = " << y << endl;
	fileIn >> ws; // ws: white space
	getline(fileIn, str); // 한글 입력: 파일의 인코딩이 ANSI
	cout << str << endl;
	while (1)
	{
		char c;
		c = fileIn.get();
		if (fileIn.eof()) break;
		cout << c;
	}
	fileIn.close();

	ifstream fileBinIn("testBin.txt", ofstream::binary);
	int k;
	double z;
	fileBinIn.read((char*)&k, sizeof(k));
	cout << endl << "k = " << k << endl;
	fileBinIn.read((char*)&z, sizeof(z));
	cout << "z = " << z << endl;
}