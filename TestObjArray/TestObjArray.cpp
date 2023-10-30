// TestObjArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "MyCircle.h"

int main()
{
	// namespace 접근: namespace명::멤버명
	// 대안: using -> 멤버명으로도 접근 가능
	using namespace std;

	// 배열(array) 정의: 자료형(클래스명) 배열명[배열 크기]
	// 초기화: {...}
	int array[10] = { 2,3,5,-2,-6,-7 };
	// 반복문: 레인지(range, 범위) 기반 for 구문
	//for (int i : array) // 배열 array 원소를 하나씩 순서대로 뽑아서 i를 초기화
	// auto 자료형: 모든 자료형이 될 수 있는 만능 자료형
	for (auto i : array) // 배열 array 원소를 뽑아서 i를 초기화; i의 자료형은 명시할 필요없이 auto로 설정
	{
		cout << i << endl;
	}
	cout << endl;
	// 기존 for 구문
	for (int i = 0; i < 10; i++)
	{
		int j = array[i];
		cout << j << endl;
	}
	cout << endl;
	// 객체 배열: 원소 접근은 레퍼런스(reference, 참조자) -> 포인터 역할인데 변수처럼 사용; 복사본 만들지 않고 원본에 참조 위치(참조자 이름)로 접근
	// 참조자 사용법: 자료형 다음에 & 추가(구별: 변수명 앞에 붙은 &는 주소 가져오기 연산자(address of)
	MyCircle circles[10]; // 클래스명 MyCircle을 자료형처럼 사용
	//for (auto cir : circles) // 할당: circles 원소의 복사본을 cir에 할당(=)
	for (auto& cir : circles) // 할당: circles 원소 원본의 참조자를  cir에 할당(=); 복사본을 만들지 않음
	{
		cir.setRad(5.); // 반지름을 5로 설정
	}
	// 객체 배열의 모든 원소 출력(print)
	for (auto& cir : circles)
	{
		cir.print();
		cout << endl << endl;
	}
}

