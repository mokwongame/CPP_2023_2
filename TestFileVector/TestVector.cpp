#include <iostream>
#include <vector> // namespace std에 정의된 벡터 자료 구조(배열과 비슷하지만, 끝에 원소를 넣거나 뺄 수 있음 -> 자료 구조의 크기가 증감할 수 있음)

int main()
{
	using namespace std;
	//std::vector<int> vec;
	vector<int> vec = { 1,2,3,4,5, -10, -20 }; // 원소의 자료형이 int인 벡터를 선언; <...> 의미: 템플릿(template)
	//for (int i : vec) // vec에서 원소를 하나 뽑아서 i에 저장
	for (auto i : vec) // auto 자료형: 맥락에 맞게 자료형을 자동으로(auto) 선언
	{
		cout << i << endl;
	}
	//  자료 하나 넣기: 벡터 끝(back)에 자료 하나를 밀어넣기(push)
	vec.push_back(100); // 함수명 쓰기: 단어가 _로 연결; 단어는 모두 소문자; snake case(뱀 형태)
	cout << endl;
	for (auto i : vec) cout << i << endl;
	// 벡터 크기 얻기
	cout << "vec size = " << vec.size() << endl;
	// 자료 하나 제거
	vec.pop_back();
	cout << endl;
	for (auto i : vec) cout << i << endl;
	cout << "vec size = " << vec.size() << endl;
}