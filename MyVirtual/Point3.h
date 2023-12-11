#pragma once

#include "Point2.h"

class Point3 : public Point2 // : �ǹ� - Point2�� public �Ӽ����� ���
{
public:
	Point3(void) : Point2() { m_z = 0; }
	Point3(int x, int y) : Point2(x, y) { m_z = 0; } // : �ǹ� - �θ� Ŭ������ ������ ȣ��
	virtual void move(int dx, int dy);

private:
protected:
	int m_z = 0;
};

inline void Point3::move(int dx, int dy)
{
	std::cout << "Point3�� move" << std::endl;

	// ��� ���� ���: �θ� Ŭ���� ����
	Point2::move(dx, dy);
}