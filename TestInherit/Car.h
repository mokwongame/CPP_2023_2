#pragma once

#include <vector>
#include "Vehicle.h"
#include "CarInfo.h"

// public 상속: 접근 권한은 원래대로
// protected 상속: public  멤버 -> protected 멤버로 변경; 나머지는 그대로
// private 상속: public, protected 멤버 -> private 멤버; 나머지는 그대로
// : 의미: 상속 받는다는 뜻
class Car : public Vehicle
{
public:
	Car(void) {}
	~Car() {}

	int getGear(void) const { return m_nGear; }
	void setGear(int nGear) { m_nGear = nGear; }

	void printMaxSpeed(void) const;
	void printMaxRange(double hour) const;

	// friend: 멤버 X, 내부 프로퍼티에 접근 가능한 메소드; 어떤 메소드든지 friend 선택 가능하지만 operator 중복에만 주로 사용
	friend std::ostream& operator<<(std::ostream& stream, const Car& vehicle);

private:
	int m_nGear = 0;
	bool m_bBrake = true;

protected:
	// 브랜드, 가격, 최대속도
	//std::vector<std::string> m_brand; // 여러 브랜드를 저장하는 벡터 자료 구조; 원소는 문자열로 선택
	//std::vector<double> m_price;
	//std::vector<double> m_maxSpeed;
	std::vector<CarInfo> m_carInfos;
};

inline void Car::printMaxSpeed(void) const
{
	using namespace std;
	cout << "[현재 최고 속도]" << endl;
	cout << "현재 기어 = " << m_nGear << "단" << endl;
	cout << "---------------" << endl;
	for (const auto& carInfo : m_carInfos)
	{
		cout << carInfo.getBrand() << "의 최고 속도 = " << carInfo.getSpeed(m_nGear) << " km/h" << endl;
	}
	cout << "---------------" << endl;
}

inline void Car::printMaxRange(double hour) const
{
	using namespace std;
	cout << "[현재 이동 거리]" << endl;
	cout << "현재 기어 = " << m_nGear << "단" << endl;
	cout << "---------------" << endl;
	for (const auto& carInfo : m_carInfos)
	{
		// 이동 거리 = 속도*이동 시간
		cout << carInfo.getBrand() << "의 이동 거리 = " << carInfo.getSpeed(m_nGear) * hour << " km" << endl;
	}
	cout << "---------------" << endl;
}

inline std::ostream& operator<<(std::ostream& stream, const Car& car)
{
	using namespace std;
	stream << "[Car: " << car.getName() << "]" << endl;
	stream << "속도 = " << car.getSpeed() << " km/h" << endl;
	stream << "현재 위치 = (" << car.getPosX() << ", " << car.getPosY() << ")" << endl;
	stream << "기어 = " << car.m_nGear << "단" << endl;
	stream << "브레이크 = " << ((car.m_bBrake) ? "걸림" : "안걸림");
	return stream;
}