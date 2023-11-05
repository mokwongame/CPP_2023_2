// TestMemory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	using namespace std;
	// 포인터 선언
	int* ptr1;
	// 포인터 정의(초기화)
	int* ptr2 = nullptr; // nullptr(null pointer): 아무것도 가리키지 않는 포인터
	// 포인터와 참조자 비교: 변수를 할당(=)할 때 원본을 직접 접근하는 기능; 보통 변수 할당은 원본과 복사본을 만듦
	// 포인터(pointer): 메모리의 물리적 주소를 이용해서 원본에 직접 접근
	// 참조자(reference): 메모리를 접근할 때 변수명(참조자, 참조 위치)을 이용해 원본에 접근
	int i = 10;
	int j = i; // i의 복사본을 만들어서 j에 할당(메모리를 많이 쓰고 할당 시간도 많이 걸림)

	// 동적 메모리 할당에는 포인터를 사용
	// 메모리 할당에는 new 사용
	ptr1 = new int;
	*ptr1 = 10; // *변수명: 변수명은 포인터가 되며, *포인터는 포인터가 가르키는 값이 됨; * 연산자 값을 가져오는 연산자(valueof)
	cout << *ptr1 << endl;
	cout << ptr1 << endl;

	// 동적 메모리를 할당한 후에, 사용이 끝나면 반드시 동적 메모리를 해제: 전적으로 프로그래머가 관리
	// 메모리 해제애는 delete 사용
	delete ptr1;
	//*ptr1 = 20; // 실행 시간 오류(runtime error)
	//cout << *ptr1 << endl;

	// C++과 다르게 Java와 C#은 메모리 해제를 할 필요 없음(메모리 해제 방법 X) -> 가비지 컬렉터(쓰레기 수집기)가 메모리 해제 담당

	// 메모리 할당하며 초기화
	ptr2 = new int{ 30 }; // 클래스 초기화 혹은 배열 초기화처럼 동적 메모리를 {}로 초기화: 30으로 ptr2의 값을 초기화
	//ptr2 = new int(30); // type casting처럼 초기화
	cout << *ptr2 << endl;
	delete ptr2; // 자료형을 해제

	// 동적 메모리를 배열로 할당
	int nSize = 50;
	double* ptr3 = new double[nSize] {10.1, 20.1};
	//ptr3[0] = 10.1;
	//ptr3[1] = 20.1;
	for (int i = 0; i < nSize; i++)
		//for (auto x : ptr3)
		cout << ptr3[i] << endl;

	// 배열로 된 동적 메모리 해제는 반드시 delete []
	delete[] ptr3;
}