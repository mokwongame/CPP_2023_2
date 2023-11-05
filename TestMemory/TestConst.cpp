#include <iostream>

int main()
{
	using namespace std;

	const int i = 10;
	const int i2 = -10;
	//i = 20;
	// const int* 의미: int*이지만 값을 변경 X; const int의 pointer란 뜻; const는 상수라는 뜻이라서; 주소 변경 가능
	const int* j = &i; // & 의미: 변수의 주소를 가져오기; addressof로 생각
	j = &i2;
	cout << *j << endl;

	int l = 30;
	int l2 = -30;
	int* const k = &l; // int*이지만 pointer k를 변경 X(주소 변경 X); 값을 변경 가능
	cout << *k << endl;
	*k = 50;
	//k = &l2;
	cout << *k << endl;

	return 0;
}