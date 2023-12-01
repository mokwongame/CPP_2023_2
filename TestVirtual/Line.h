#pragma once

//#include <math.h> // C ����� ���� �Լ�
#include <cmath> // C++ ����� ���� �Լ�
#include "Shape.h"

class Line : public Shape
{
public:
	Line(void) {}
	Line(const PointD& pt1, const PointD& pt2)
	{
		m_pt = pt1;
		m_pt2 = pt2;
	}

	// �θ�� �ڽ� Ŭ������ �Լ� ������ ����: �޼ҵ� ������(override)
	double getLen(void) const
	{
		double dx = m_pt2.getX() - m_pt.getX();
		double dy = m_pt2.getY() - m_pt.getY();
		return sqrt(dx * dx + dy * dy); // ������ �Լ�(square root)
	}

private:
	PointD m_pt2;
};