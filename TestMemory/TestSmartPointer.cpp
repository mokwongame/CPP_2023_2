#include <iostream>
#include <memory>

// 스마트 포인터: 메모리를 할당하면 사용이 끝난 후 자동적으로 메모리 해제

int main()
{
	using namespace std;

	// 메모리 할당
	unique_ptr<int> ptr1(new int{ 20 }); // <int> 의미: 템플릿(template)의 자료형
	//*ptr1 = 20;
	cout << *ptr1 << endl;

	unique_ptr<double> ptr2(new double{ 1.2 });
	//ptr2 = new double;
	//*ptr2 = 1.2;
	cout << *ptr2 << endl;

	// 배열 할당
	int nSize = 20;
	unique_ptr<int[]> ar(new int[nSize] {1, 2, 3, 4});
	for (int i = 0; i < nSize; i++)
		cout << ar[i] << endl;

	// unique_ptr의 메모리 해제는 저절로 됨: 인스턴스 ptr이 해제될 때 할당된 메모리도 저절로 해제

	return 0;
}