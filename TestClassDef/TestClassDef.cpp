// TestClassDef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// C 언어: printf() in <stdlib.h>
// C++ 헤더 파일 확장자: *.hpp
#include <iostream> // C++ 언어의 표준 입출력 헤더 파일
#include "MyCircle.h"

int main()
{
	using namespace std; // 아래부터는 std::을 쓸 필요 없음
	cout << "Hello World!\n";

	// 인스턴스(instance == example): 클래스를 사용할 수 있는 상태로 선언이나 정의된 형태
	// 변수 선언과 비슷하게 클래스 선언, 인스턴스 생성
	MyCircle myCircle; // 클래스명 == 자료형, 인스턴스명 == 변수명; 인스턴스명은 보통 소문자로 시작
	// 인스턴스의 멤버 접근: . 점 연산자 사용(구조체와 비슷)
	myCircle.setRad(1.2);
	myCircle.setCenter(-2., 4.);
	myCircle.print();
}