#pragma once

#include <string>
#include <iostream>

// 매크로(macro) 정의
#define DEF_SPEED_STEP	(10.)

// public: 항상 접근 가능(외부, 상속)
// private: 항상 접근 불가(외부, 상속)
// protected: 접근 불가(외부), 접근 가능(상속)
class Vehicle
{
public: // public 그룹
	Vehicle(void)
	{}
	~Vehicle()
	{}

	void speedUp(double step = DEF_SPEED_STEP)
	{
		m_speed += step;
	}
	void speedDown(double step = DEF_SPEED_STEP)
	{
		m_speed -= step;
	}
	double getSpeed(void) const // const 의미: 현재 메소드는 프로퍼티를 변경하지 않음(상수처럼 처리)
	{
		return m_speed;
	}
	void setSpeed(double speed)
	{
		m_speed = speed;
	}
	double getPosX(void) const
	{
		return m_x;
	}
	double getPosY(void) const
	{
		return m_y;
	}
	void setPos(double x, double y)
	{
		m_x = x, m_y = y;
		//m_x = x; m_y = y;
	}

	std::string getName(void) const
	{
		return m_name;
	}
	void setName(const std::string& name) // & 의미: 참조자(reference), 복사본 만들지 않고 원본 접근, 변수명으로 정보 처리; const 의미: 아래 코드 블록에서 name을 변경하지 않음(상수로 취급)
	{
		m_name = name;
	}

private: // private 그룹
	double m_speed = 0.; // m_ 의미: member
	std::string m_name;

protected: // protected 그룹
	// protected: 상속하기 전까지는 private과 동일; 상속하면 자식 클래스에서 protected 멤버는 접근 가능, private 멤버는 여전히 접근 불가능
	double m_x = 0.;
	double m_y = 0.;
};

inline std::ostream& operator<<(std::ostream& stream, const Vehicle& vehicle)
{
	using namespace std;
	stream << "[Vehicle: " << vehicle.getName() << "]" << endl;
	stream << "속도 = " << vehicle.getSpeed() << " km/h" << endl;
	stream << "현재 위치 = (" << vehicle.getPosX() << ", " << vehicle.getPosY() << ")";
	return stream;
}

// #define을 해제(undefine)
#undef DEF_SPEED_STEP