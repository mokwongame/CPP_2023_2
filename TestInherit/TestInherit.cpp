// TestInherit.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Vehicle.h"
#include "Car.h"

int main()
{
	using namespace std;
	Vehicle vehicle;
	vehicle.setName("이동체");
	vehicle.speedUp(100);
	vehicle.speedDown(50);
	cout << vehicle << endl;

	Car car;
	car.setName("자동차");
	car.setSpeed(200);
	cout << endl << car << endl;
}