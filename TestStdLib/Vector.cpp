#include <iostream>
#include <vector> // 벡터 자료 구조를 정의한 헤더 파일; 벡터 = 길이가 가변되는 배열

int main()
{
	using namespace std;
	// vector 클래스는 namespace std에 정의됨
	vector<int> vec = { 1, -2, 3 }; // <int> 의미: 템플릿(template)의 자료형이 int란 의미, <int>로 쓰면 클래스 안에 있는 특정 프로퍼티의 자료형이 int로 바뀜; 클래스명 다음에 쓰는 <>는 템플릿이란 의미; 템플릿 클래스는 클래스의 기본 구조(메소드)를 제공하며 <>를 이용해 클래스의 프로퍼티(멤버 변수)의 자료형을 바꿈
	for (auto i : vec)
		cout << i << endl;
	cout << "vector 크기 = " << vec.size() << endl; // size() 함수는 벡터의 크기를 return
	// 표준 라이브러리의 함수 표기 방법: snake case(뱀 격식) -> push_back
	// C#의 함수 표기: 대문자로 함수 시작, 나머지도 대문자 -> Pascal case -> PushBack()
	// 통상적인 함수 표기: 소문자로 함수 시작, 나머지 대문자 -> camel case(낙타 격식) -> pushBack()
	vec.push_back(20); // vector의 뒤쪽(back)에 20을 push
	vec.push_back(30);
	for (auto i : vec) cout << i << endl;
	cout << "vector 크기 = " << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << "vec[" << i << "] = " << vec[i] << endl;

	vec.pop_back(); // vector의 뒤쪽을 pop; 자료의 크기가 하나 줄어듬
	cout << endl;
	for (auto i : vec) cout << i << endl;
	cout << "vector 크기 = " << vec.size() << endl;

	// iterator(반복자): 포인터 기반으로 반복하는 기능
	// begin(): 시작 포인터(반복자)
	// end(): 끝 포인터(반복자)
	// 포인터 증가시킬 때는 ++
	// 정상적인 방향으로 반복문 구동: 첨자를 0번부터 끝번호까지
	cout << endl << "반복자로 정상 방향 출력" << endl;
	//for (auto it = vec.begin(); it < vec.end(); it++)
	for (auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << endl; // it는 포인터라서 값으로 바꿀 때는 * 연산자(valueof)를 사용

	// 반대 방향으로 반복문 구동: 첨자 끝번호부터 0번까지 변화
	// rbegin(): reverse begin()
	// rend(): reverse end()
	cout << endl << "반복자로 반대 방향 출력" << endl;
	for (auto it = vec.rbegin(); it != vec.rend(); it++)
		cout << *it << endl;

	vector<double> vecDouble = { 1.2, 3.4, -5.6 };
	cout << endl << "실수 벡터 출력" << endl;
	for (auto x : vecDouble) cout << x << endl;
	return 0;
}