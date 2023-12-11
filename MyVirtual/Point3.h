#pragma once

#include "Point2.h"

class Point3 : public Point2 // : �ǹ� - Point2�� public �Ӽ����� ���
{
public:
	Point3(int x, int y) : Point2(x, y) {} // : �ǹ� - �θ� Ŭ������ ������ ȣ��
	void move(int dx, int dy);

private:
protected:
	int m_z = 0;
};

inline void Point3::move(int dx, int dy)
{
	// ��� ���� ���: �θ� Ŭ���� ����
	Point2::move(dx, dy);
}