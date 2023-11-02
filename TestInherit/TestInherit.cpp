// TestInherit.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Vehicle.h"

int main()
{
	using namespace std;
	std::cout << "Hello World!\n";

	Vehicle vehicle;
	vehicle.speedUp(100);
	cout << vehicle.x << endl;
}