/* Car에서 상속 받아 Sedan, Suv, Truck, Bus 클래스 생성
-  Sedan, Suv, Truck, Bus별로 정보를 출력: 브랜드, 가격, 최대속도
- Car 클래스: 기어 단수에 따라 최대 속도 결정: 최대 속도를 Vm으로 설정 -> 1단 = Vm*0.25, 2단 = Vm*0.5, 3단 = Vm*0.75, 4단 = Vm
- Sedan, Suv, Truck, Bus도 기어 단수에 따라 최대 속도를 변경
- 각 이동체별로 이동한 거리를 계산: 시간 입력(time)을 받아 speed로 계산 = speed*time
*/

#include "Car.h"
#include "Sedan.h"

int main()
{
	using namespace std;
	Sedan sedan;
	cout << sedan << endl;

	cout << "기어(1~4)를 선택하세요: ";
	int nGear = 0;
	cin >> nGear;
	while (!cin || nGear < 1 || nGear > 4)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "기어를 다시 선택하세요: ";
		cin >> nGear;
	}

	sedan.setGear(nGear);
	sedan.printMaxSpeed();
}