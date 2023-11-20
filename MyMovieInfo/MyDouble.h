#pragma once

#include <iostream>

// ++, --�� ������ ���Ǵ�� ����
class MyDouble // �ڵ� ��Ÿ��: Pascal case
{
public:
	MyDouble(double x = 0.)
	{
		setX(x);
	}
	// ���� ������
	MyDouble(const MyDouble& myDouble)
	{
		m_x = myDouble.m_x;
		m_step = myDouble.m_step;
	}

	double getX(void) const
	{
		return m_x;
	}
	void setX(double x)
	{
		m_x = x;
	}
	void setStep(double step)
	{
		m_step = step;
	}

	MyDouble& operator=(const MyDouble& myDouble)
	{
		m_x = myDouble.m_x;
		m_step = myDouble.m_step;
		// ���� Ŭ����(MyDouble)�� �ν��Ͻ� ��ȯ
		return *this; // this�� ���� �ν��Ͻ��� ������; *this: �������� �� -> ���� �ν��Ͻ�
	}
	MyDouble& operator++(void)
	{
		m_x += m_step; // m_x = m_x + m_step;
		return *this;
	}
	MyDouble operator++(int i) // i�� ����(dummy)
	{
		MyDouble tmp(*this); // ���� �ν��Ͻ��� ���纻�� tmp�� ����
		m_x += m_step; // m_x = m_x + m_step;
		return tmp;
	}
	MyDouble& operator--(void)
	{
		m_x -= m_step; // m_x = m_x + m_step;
		return *this;
	}

private:
	double m_x = 0.0; // double ���尪
	double m_step = 1.0; // ����
};

inline std::ostream& operator<<(std::ostream& stream, const MyDouble& myDouble)
{
	stream << myDouble.getX();
	return stream;
}