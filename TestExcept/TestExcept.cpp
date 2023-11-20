// TestExcept.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <exception>

void myFun(void)
{
	int i = 0;
	int j = 30 * i;

	throw std::string("함수에서 예외 발생");
}

int main()
{
	using namespace std;
	int i = 10;
	int j = 3;

	// try-catch 구문: throw를 이용해서 예외(exception)을 던짐
	try // 실행할 코드 블록; 여기서 예외가 발생할 수 있음
	{
		cout << "__int64 바이트 크기: " << sizeof(__int64) << endl;

		//__int64 nSize = 100000000000;
		//double* ptr = new double[nSize];
		//delete[] ptr;

		if (j == 0) throw j;
		int k = i / j;

		cout << k << endl;
		cout << "i = " << i << endl;
		cout << "j = " << j << endl;

		myFun(); // throw는 함수에서도 동작함

		double x = 10.5;
		double y = -2.;
		if (y == 0.) throw y;
		double z = x / y;
		cout << "z = " << z << endl;

		//throw "기타 예외"; // const char* e로 받아야 함
		throw string("문자열 점검");
	}
	catch (int e) // 예외를 처리하는 코드 블록; 예외를 구별할 때는 매개변수의 자료형으로 구별
	{
		cout << "정수 분모에 문제: " << e << endl;
	}
	catch (double e)
	{
		cout << "실수 분모에 문제: " << e << endl;
	}
	catch (string& e)
	{
		cout << "받은 예외 문자열: " << e << endl;
	}
	catch (exception& e)
	{
		cout << "표준 예외: " << e.what() << endl;
	}
	catch (...) // 기타 예외 처리
	{
		cout << "알 수 없는 예외 발생" << endl;
	}
}
