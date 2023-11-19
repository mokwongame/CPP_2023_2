// TestTemplate.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

//int sum(int a, int b)
//{
//	return a + b;
//}
//
//double sum(double a, double b)
//{
//	return a + b;
//}
template<typename T = int> // T는 자료형 이름을 담은 매개변수
T sum(const T& a, const T& b)
{
	return a + b;
}

#define TEMP template<typename T>

//template<typename T>
TEMP class MyPoint
{
public:
	MyPoint(const T& a, const T& b)
	{
		x = a, y = b;
	}

	void print(void) const;

	T getX(void) const { return x; }
	T getY(void) const { return y; }

private:
	T x;
	T y;
};

//template<typename T> inline void MyPoint<T>::print(void) const
TEMP inline void MyPoint<T>::print(void) const
{
	using namespace std;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

TEMP MyPoint<T> operator+(const MyPoint<T>& pt1, const MyPoint<T>& pt2)
{
	MyPoint<T> pt3(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
	return pt3;
}

int main()
{
	using namespace std;
	//cout << sum(1, 2) << endl;
	//cout << sum(1.2, 3.4) << endl;
	cout << sum(-1, -2) << endl;
	cout << sum<int>(1, 2) << endl;
	cout << sum<double>(1.2, 3.4) << endl;
	cout << sum<string>("This is a", " test of the template.");

	vector<int> vec = { 1, 2, 3 };
	for (auto& i : vec)
		cout << i << endl;
	cout << endl;

	MyPoint<int> myPoint1(1, 2);
	MyPoint<int> myPoint3(-5, -7);
	MyPoint<double> myPoint2(1.5, 2.5);
	myPoint1.print();
	cout << endl;
	myPoint2.print();
	MyPoint<int> myPoint4 = myPoint1 + myPoint3;
	cout << endl;
	myPoint4.print();
	MyPoint<double> myPoint5 = myPoint2 + myPoint2;
	cout << endl;
	myPoint5.print();
	//myPoint1 + myPoint2; // 정의된 연산자가 아님
}
