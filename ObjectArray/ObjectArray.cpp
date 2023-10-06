// ObjectArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "MyCircle.h"

int main()
{
	using namespace std;
	// for (초기값; 판단식; 증감) {...}
	int ar[10] = { 1,2,3,4,5,6 }; // 배열명은 ar인 int 자료형 10개가 선언; 초기화하지 않은 나머지 원소는 0이 됨
	//for (int i = 0; i < 10; i++)
	for (int i : ar) // i는 정수 변수; ar의 원소를 복사해서 i에 저장 -> 원본, 복사본 2개가 존재
		// ar => i; 배열 ar에서 원소를 가져와서 i에 저장; range(범위) 기반의 for loop
	{
		//cout << "[" << i << "] = " << ar[i] << endl; // i는 색인(index); 배열 ar의 i번 원소를 접근; 색인는 0번부터 시작
		cout << i << endl; // i에 ar의 원소가 있기 때문에 i를 출력해서 원소 정보를 확인
	}
	cout << endl;
	for (int& i : ar) // i는 정수의 참조자(reference): 원본의 위치에 접근해서 값을 변경; ar의 원소 위치 정보를 i에 저장 -> 원본만 존재
	{
		cout << i << endl;
	}
	cout << endl;
	// auto 키워드: 변수의 초기화에 맞는 자료형을 자동으로 선언; i는 auto 변수
	for (auto& i : ar)
	{
		cout << i << endl;
	}

	MyCircle myCircle[3]; // 객체 배열
	myCircle[0].setRad(2.);
	myCircle[0].setCenter(10., 10.);
	myCircle[1].setRad(3.);
	myCircle[1].setCenter(10., 13.);
	myCircle[2].setRad(4.);
	myCircle[2].setCenter(15., 15.);
	for (auto& cir : myCircle)
	{
		cir.print();
		cir.draw('*');
	}
}