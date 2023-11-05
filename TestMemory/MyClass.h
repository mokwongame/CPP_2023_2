#pragma once

#include <iostream>

class MyClass
{
public:
	MyClass(void) {}
	~MyClass() {}

	// getter & setter
	int getVal(void) const { return nVal; } // const 의미: 이 메소드는 프로퍼티를 변경 X; 불필요한 권한을 주지 않기 위해서
	//void setVal(int val) { nVal = val; }
	void setVal(int nVal) { this->nVal = nVal; } // 함수 입력 이름과 프로퍼티 이름이 같은 경우: this 포인터(현재 인스턴스의 포인터)
	// -> 의미: 구조체나 클래스 포인터의 멤버 접근; 인스턴스의 멤버 접근: 점(.) 연산자; 비교: -> 과 .을 비교

	// 정적 멤버: 멤버 선언 앞에 static이 붙은 멤버
	static int getCount(void) { return nCount; }
	//static void setCount(int count) { nCount = count; }
	static void setCount(int nCount) { MyClass::nCount = nCount; }
	static int getNum(void) { return 300; }

private:
	int nVal = 10; // private 프로퍼티
	static int nCount; // 정적 프로퍼티; 선언은 클래스안에서 함; 정의와 초기화는 클래스 바깥에서 해줌
	double x = 20;
	static const int nMyNumber; // 정적이며 상수인 프로퍼티
	//const static int nMyNumber; // 정적이며 상수인 프로퍼티
};
