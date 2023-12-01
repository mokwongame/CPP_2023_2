#pragma once

#include "Point_template.h"

typedef Point<double> PointD; // Point<double> 대신 별명으로 PointD를 사용

class Shape
{
public:
	Shape(void) {}
	Shape(double x, double y)
	{
		m_pt.setPt(x, y);
	}
	Shape(const PointD& pt)
	{
		m_pt = pt;
	}

	PointD getPt(void) const { return m_pt; }
	// 메소드 정의 앞에 virtual을 쓰면 가상 함수가 됨
	virtual void move(double dx, double dy)
	{
		PointD pt(m_pt.getX() + dx, m_pt.getY() + dy);
		m_pt = pt;
	}
	// 메소드 정의 앞에 virtual을 붙이면 가상 함수가 됨
	virtual double getLen(void) const
	{
		return 0.;
	}
	virtual double getArea(void) const
	{
		return 0.;
	}

protected:
	PointD m_pt;
	// x가 아래 값을 벗어나면 예외 처리
	double m_xmin = 0.;
	double m_xmax = 10.;
	// y가 아래 값을 벗어나면 예외 처리
	double m_ymin = 0.;
	double m_ymax = 10.;
};

inline std::ostream& operator<<(std::ostream& stream, const Shape& shape)
{
	stream << shape.getPt();
	return stream;
}