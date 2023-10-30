#include <iostream>

int main()
{
	using namespace std;
	int i = 10; // 정수 숫자 10을 정수 자료형 변수명 i에 할당(초기화)
	int j = i; // 변수 i의 복사본을 변수 j에 할당(원본, 복사본 모두 존재)
	// 참조자 선언: 자료형& 변수명
	int& k = i; // 변수 i의 참조 위치(변수명)를 k에 할당(원본만 존재, 복사본 X)
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "k = " << k << endl;

	k = 20; // k의 참조자 원본 값(i)을 20으로 설정; 원본만 있기 때문에 i, k가 모두 변경
	cout << endl << "참조자 사용" << endl;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "k = " << k << endl;

	// 포인터(pointer, 지시자)와 비교
	// 포인터 생성: 자료형* 변수명 -> 이 변수명이 포인터
	int* l = &j; // l은 포인터(물리 주소를 저장하는 변수); &j 의미: 변수 j의 물리 주소를 가져옴(& == address of)
	*l = 50; // 주소 l의 값을 50으로 할당; *l 의미: 포인터 l의 값을 가져옴(* == value of)

	cout << endl << "포인터 사용" << endl;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "k = " << k << endl;
	cout << "*l = " << *l << endl;
	cout << "l = " << l << endl; // 포인터

	// 포인터 vs. 레퍼런스
	// 같은점: 복사본 없이 원본 접근
	// 다른점: 포인터(주소 == 물리 주소), 레퍼런스(참조 위치 == 변수명)
	return 0;
}