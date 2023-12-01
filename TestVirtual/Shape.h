#pragma once

#include "Point_template.h"

typedef Point<double> PointD; // Point<double> ��� �������� PointD�� ���

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
	// �޼ҵ� ���� �տ� virtual�� ���� ���� �Լ��� ��
	virtual void move(double dx, double dy)
	{
		PointD pt(m_pt.getX() + dx, m_pt.getY() + dy);
		m_pt = pt;
	}
	// �޼ҵ� ���� �տ� virtual�� ���̸� ���� �Լ��� ��
	virtual double getLen(void) const
	{
		return 0.;
	}
	virtual double getArea(void) const
	{
		return 0.;
	}
	void checkPt(const PointD& pt) const;

protected:
	PointD m_pt;
	// x�� �Ʒ� ���� ����� ���� ó��
	double m_xmin = 0.;
	double m_xmax = 10.;
	// y�� �Ʒ� ���� ����� ���� ó��
	double m_ymin = 0.;
	double m_ymax = 10.;
};

inline void Shape::checkPt(const PointD& pt) const
{
	using namespace std;
	// try-catch ����
	try // �ڵ� ����; ���� ���� �߻��ϸ� throw ȣ��
	{
		double x = pt.getX();
		double y = pt.getY();
		if (x < m_xmin || x > m_xmax) throw pt; // ���� ó��: ������ ����� pt�� ����
		if (y < m_ymin || y > m_ymax) throw pt; // ���� ó��
		cout << "���� ����" << endl;
	}
	catch (PointD& e) // ���� ó��; e: ����(exception)
	{
		cout << "���� �߻�: " << e << endl;
	}
}

inline std::ostream& operator<<(std::ostream& stream, const Shape& shape)
{
	stream << shape.getPt();
	return stream;
}