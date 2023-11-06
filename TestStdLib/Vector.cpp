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
	vec.push_back(20); // vector의 뒤쪽(back)에 20을 push
	vec.push_back(30);
	for (auto i : vec) cout << i << endl;
	cout << "vector 크기 = " << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << "vec[" << i << "] = " << vec[i] << endl;
	return 0;
}