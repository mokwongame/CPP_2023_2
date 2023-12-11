#pragma once

#include <iostream>

#define TEMP template<typename T>

// 2���� ��ǥ �� (x, y)
//template<typename T> // T ��� A ������
TEMP class Point2
{
public:
	Point2(void) {}
	Point2(T x, T y)
	{
		setPt(x, y);
	}
	Point2(const Point2& pt) // ���� ������
	{
		setPt(pt);
	}
	~Point2() {}

	T getX(void) const { return m_x; }
	T getY(void) const { return m_y; }
	Point2 getPt(void) const { return Point2(m_x, m_y); }
	void setPt(T x, T y)
	{
		m_x = x, m_y = y;
	}
	void setPt(const Point2& pt)
	{
		m_x = pt.m_x, m_y = pt.m_y;
	}

	virtual void move(T dx, T dy); // �޼ҵ� ���� �տ� virtual�� ���� ���� �Լ��� ��

private:
	//int m_x = 0, m_y = 0;
	T m_x, m_y;
};

//template<typename T>
TEMP inline void Point2<T>::move(T dx, T dy)
{
	std::cout << "Point2�� move" << std::endl;
	m_x += dx;
	m_y += dy;
}

TEMP inline std::ostream& operator<<(std::ostream& stream, const Point2<T>& pt)
{
	stream << "(" << pt.getX() << ", " << pt.getY() << ")";
	return stream;
}

#undef TEMP // define�� TEMP�� undefine