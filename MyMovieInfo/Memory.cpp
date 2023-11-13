#include <iostream>

int main()
{
	using namespace std;
	// 동적 메모리 할당: 힙(heap) 영역에 메모리 할당; 파일이 실행된 후에 할당되는 메모리
	int i = 0; // 정적 메모리: 실행전에 int란 자료형과 메모리가 결정됨
	int* ptr = nullptr; // nullptr: null pointer란 의미, 숫자로 표현되면 0
	// int*: int 포인터(int 자료형의 주소를 가진 변수)
	ptr = new int; // int 자료형 저장 공간(동적 메모리, 힙에 저장)을 새롭게(new) 포인터 ptr에 할당
	*ptr = 20; // * 의미: valueof(...의 값)
	cout << "int = " << *ptr << endl;
	int* ptr2 = ptr; // 포인터 ptr을 ptr2에 할당: ptr2도 같은 주소를 가짐
	*ptr2 = 40;
	cout << "int = " << *ptr << endl;
	// 다 쓰고 나면 동적 메모리는 반드시 해제
	delete ptr; // 단일 변수는 delete ptr로 해제; 배열이면 delte [] ptr로 해제
}


