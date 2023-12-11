#pragma once

#include "Point2.h"

class Point3 : public Point2 // : 의미 - Point2를 public 속성으로 상속
{
public:
	Point3(int x, int y) : Point2(x, y) {} // : 의미 - 부모 클래스의 생성자 호출
	void move(int dx, int dy);

private:
protected:
	int m_z = 0;
};

inline void Point3::move(int dx, int dy)
{
	// 상속 받은 경우: 부모 클래스 접근
	Point2::move(dx, dy);
}