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

	double getX(void) const
	{
		return m_x;
	}
	void setX(double x)
	{
		m_x = x;
	}

	MyDouble& operator=(const MyDouble& myDouble)
	{
		m_x = myDouble.m_x;
		m_step = myDouble.m_step;
		// ���� Ŭ����(MyDouble)�� �ν��Ͻ� ��ȯ
		return *this; // this�� ���� �ν��Ͻ��� ������; *this: �������� �� -> ���� �ν��Ͻ�
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