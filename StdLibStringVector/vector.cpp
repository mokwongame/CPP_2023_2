#include <iostream>
#include <vector> // 크기가 변경 가능한 배열(array)

int main(void)
{
	using namespace std; // vector는 std에 정의
	// <int> 의미: <>는 템플릿(template, 틀)을 의미
	vector<int> vec = { 1, 2, 3, 10, -4, 5, -6, 7 };
	// 배열 선언: int ar[10];
	cout << "size = " << vec.size() << endl;
	for (auto i : vec) cout << i << endl;

	vec.push_back(100); // back에 push: snake case
	vec.push_back(-100);
	cout << endl << "size = " << vec.size() << endl;
	for (auto i : vec) cout << i << endl;
	vec.pop_back(); // back에서 pop(원소 제거)
	cout << endl << "size = " << vec.size() << endl;
	for (auto i : vec) cout << i << endl;

	// 마지막 원소 접근
	auto j = vec.back();
	cout << endl << "back = " << j << endl;
	j = vec.front();
	cout << endl << "front = " << j << endl; \
		// 특정 원소 접근 [], at()
		cout << endl << vec[1] << endl; // index 1번에 접근: 0, 1이니까 두번째 원소
	cout << endl << vec.at(2) << endl;
	cout << "is empty? " << vec.empty() << endl;

	// for loop: iterator(반복자) -> 반복하기 위한 포인터(pointer)
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl; // 반복자 it의 값 가져오기: *연산자(valueOf: 의 값)
	}
	return 0;
}