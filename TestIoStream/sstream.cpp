#include <iostream>
#include <sstream> // string stream

int main()
{
	using namespace std;
	stringstream ss("This is my first ss test. Hello, world!  ");
	// ss���� �Է� ����
	string str;
	ss >> str;
	cout << "[" << str << "]" << endl;
	ss >> str;
	cout << "[" << str << "]" << endl;
	ss >> str;
	cout << "[" << str << "]" << endl;
	cout << ss.str() << endl;

	// ss�ʿ� ���
	ss << "Mokwon" << endl;
	cout << endl << ss.str() << endl; // �պκк��� ������ ���ڿ��� ss�� ���
}