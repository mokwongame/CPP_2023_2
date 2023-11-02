#pragma once

// 매크로(macro) 정의
#define DEF_SPEED_STEP	(10.)

class Vehicle
{
public: // public 그룹
	Vehicle(void)
	{}
	~Vehicle()
	{}

	void speedUp(double step = DEF_SPEED_STEP)
	{
		speed += step;
	}

private: // private 그룹
	double speed = 0.;

protected: // protected 그룹
	// protected: 상속하기 전까지는 private과 동일; 상속하면 자식 클래스에서 protected 멤버는 접근 가능, private 멤버는 여전히 접근 불가능
	double x = 0.;
	double y = 0.;
};

// #define을 해제(undefine)
#undef DEF_SPEED_STEP