// MyVirtual.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Point3.h"

// 가상 함수: virtual function; 상속에서 부모 클래스의 인스턴스로 자식 클래스의 메소드 접근하는 방법(자식이 부모 클래스 멤버 접근은 원래부터 가능)
int main()
{
	using namespace std;
	Point3 pt1(1, 3);
	cout << pt1 << endl;
}
