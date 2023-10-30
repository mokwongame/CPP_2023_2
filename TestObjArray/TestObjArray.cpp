// TestObjArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

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
}

