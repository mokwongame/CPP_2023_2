#include <iostream>
#include <fstream> // file stream
#include <string>

int main()
{
	using namespace std;

	// cout, cin�� �ν��Ͻ�; ofstream�� Ŭ����
	ofstream file("test.txt"); // "test.txt"�� ������ ���; ������ ������ ���� ����; ������ ������ �����
	//ofstream file("test.txt", ofstream::app); // ���� ���Ͽ� �����̱�; app�� append�� �ǹ�
	file << "This is my first try." << endl;
	int i = -30;
	file << i << endl;
	double x = -4.56;
	file << x << endl;
	file << "�ѱ� ���" << endl << endl;
	file.close(); // �ν��Ͻ��� file�� �Ҹ�� �� �ڵ������� close()�� ȣ��

	// ���� ����� ����: �ؽ�Ʈ ����(ASCII �ڵ�� ����), ���̳ʸ� ����(binary file, ���� ����; ���ڵ� �״�� ����)
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
	getline(fileIn, str); // �ѱ� �Է�: ������ ���ڵ��� ANSI
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