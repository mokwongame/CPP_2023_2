#pragma once

#include <iostream>

class MyPoint
{
public:
	MyPoint(void) {}
	MyPoint(double x, double y = 0.) { setXy(x, y); }
	MyPoint(const MyPoint& pt); // ���� ������: �ڱ� �ڽ� Ŭ�������� ���� �ν��Ͻ��� �ʱ�ȭ; ���� �����ڰ� ������ �⺻ ���� �����ڰ� ȣ���(������Ƽ�� ���� ����)
	~MyPoint() {}

	double getX(void) const { return m_x; }
	double getY(void) const { return m_y; }
	void setXy(double x, double y) { m_x = x, m_y = y; }
	void print(void) const;
	MyPoint add(const MyPoint& pt); // const �ǹ�: pt�� �������� ����; & �ǹ�: ���纻 ���� pt ������ �����ؼ� ó��

	// ������ �ߺ�, �����ε�(overloading): ��ȯ�� operator�����ȣ(�Է� ����) {...}
	// ���� ������: �Է��� 1��
	MyPoint operator+(const MyPoint& pt);
	MyPoint& operator+=(const MyPoint& pt);
	MyPoint& operator=(const MyPoint& pt); // �� ������ �ߺ��� ������ �⺻ �Ҵ� �����ڰ� ������(������Ƽ�� ���� ����)
	double& operator[](int nPos); // nPos == 0, x��ǥ; nPos == 1, y��ǥ

	// ���� ������: �Է��� 2��
	// ������ �ǹ�: ����� �ƴ����� private ������Ƽ�� ������ ������ �޼ҵ�
	// friend�� �������� ���� ����; Ư���� ���(���� ������ ����ó��)�� ���
	friend MyPoint operator-(const MyPoint& pt1, const MyPoint& pt2);
	friend std::ostream& operator<<(std::ostream& stream, const MyPoint& pt);
	friend std::istream& operator>>(std::istream& stream, MyPoint& pt);

private:
	// 2���� ��ǥ: (x, y)
	double m_x = 0.;
	double m_y = 0.;
};

inline MyPoint::MyPoint(const MyPoint& pt)
{
	m_x = pt.m_x;
	m_y = pt.m_y;
	std::cout << "����: " << *this << std::endl;
}

inline void MyPoint::print(void) const
{
	using namespace std;
	cout << "(" << getX() << ", " << getY() << ")";
}

inline MyPoint MyPoint::add(const MyPoint& pt)
{
	MyPoint result(m_x + pt.m_x, m_y + pt.m_y);
	return result;
}

inline MyPoint MyPoint::operator+(const MyPoint& pt)
{
	MyPoint result(m_x + pt.m_x, m_y + pt.m_y);
	return result;
}

// MyPoint& �ǹ�: ��ȯ�� �� ���纻�� �ƴ� ���� ���� ��ġ(reference, ������)�� ��ȯ
inline MyPoint& MyPoint::operator+=(const MyPoint& pt)
{
	m_x += pt.m_x; // m_x = m_x + pt.m_x
	m_y += pt.m_y; // m_y = m_y + pt.m_y
	return (*this); // this: ���� �ν��Ͻ��� ������; *this: this�� ����Ű�� �� == ���� �ν��Ͻ�
}

inline MyPoint& MyPoint::operator=(const MyPoint& pt)
{
	m_x = pt.m_x;
	m_y = pt.m_y;
	std::cout << "�Ҵ�: " << *this << std::endl;
	return *this;
}

// double& �ǹ�: ��ȯ�� �� ���纻�� �ƴ� ���� ���� ��ġ(reference, ������)�� ��ȯ
inline double& MyPoint::operator[](int nPos)
{
	if (nPos == 0) return m_x;
	else if (nPos == 1) return m_y;
	else
	{
		std::cout << "�߸��� index: " << nPos << std::endl;
		return m_x;
	}
}

// MyPoint�� friend�� private ������Ƽ�� ���� ����
inline MyPoint operator-(const MyPoint& pt1, const MyPoint& pt2)
{
	return MyPoint(pt1.m_x - pt2.m_x, pt1.m_y - pt2.m_y);
}

inline std::istream& operator>>(std::istream& stream, MyPoint& pt)
{
	stream >> pt.m_x >> pt.m_y;
	if (!stream) // �Է� ���� �Ŀ� stream�� 0�� �ƴϸ� ���� �߻�
	{
		pt = MyPoint(0., 0.);
	}
	return stream;
}

// ostream: cout, file���� ��� ������ ��� ��Ʈ��
inline std::ostream& operator<<(std::ostream& stream, const MyPoint& pt)
{
	using namespace std;
	//cout << "(" << pt.m_x << ", " << pt.m_y << ")"; // friend�̾�߸� private ����� ���� ����
	cout << "(" << pt.getX() << ", " << pt.getY() << ")";
	return stream;
}
