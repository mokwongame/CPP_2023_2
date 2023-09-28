// Constructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class MyClass
{
public: // public member grouping
	// public member(변수, 함수)
	// 생성자와 소멸자는 항상 public에 정의
	// 생성자명 == 클래스명; 출력 자료형은 아무것도 쓰지 않음
	//MyClass(void) { cout << "void constructor" << endl; } // 생성자: void라서 입력은 없음
	//MyClass(int i = 1000) { m_i = i; cout << "int constructor" << endl; } // 디폴트 인자(C++의 모든 함수 사용 가능): 입력이 없으면 m_i에 0을 입력함
	MyClass(char c) { m_c = c; cout << "char constructor" << endl; }
	MyClass(int i = 1000, char c = 'z') : m_i(i), m_c(c) { cout << "int & char constructor" << endl; }
	// 소멸자, 파괴자 == ~클래스명: 입력 변수는 아무석도 안씀, 출력 자료형도 아무것도 안씀
	~MyClass() { cout << endl << "destructor called." << endl; }

	void print(void)
	{
		cout << "i = " << m_i << endl;
		cout << "c = " << m_c << endl;
	}

	// private member 접근하는 메소드를 public 그룹에 정의
	// 획득자(getter): 프로퍼티 읽기
	int getInt(void) const { return m_i; }
	char getChar(void) const { return m_c; }
	// 설정자(setter): 프로퍼티 쓰기
	void setInt(int i) { m_i = i; }
	void setChar(char c) { m_c = c; }

private: // private member grouping
	// private member(변수, 함수)
	int m_i = 0;
	char m_c = ' ';
};

void printClass(MyClass myClass) // 함수를 호출할 때 myClass가 할당 연산자 사용하는 것처럼 초기화됨 
{
	myClass.print();
}

// C++의 새로운 인수 전달 방식: 참조(reference) -> 기호 & 사용
void printClassRef(MyClass& myClass) // 입력 변수가 있는 위치를 참조해서 초기화: 입력 변수가 있는 위치를 가져옴(포인터와 비슷)
{
	// myClass는 변수이지만 원래 입력 변수를 참조할 수 있음: 참조 == 접근 권한
	myClass.print();
}

int main()
{
	// 생성자 호출의 전통적 방법
	//std::cout << "Hello World!\n";
	{
		MyClass myClass0;
		myClass0.print();
	}
	MyClass myClass(1); // 인스턴스 생성할 때 입력은 함수 호출처럼 입력을 넣음
	MyClass myClass2('m');
	MyClass myClass3(10, 'a');
	myClass.print();
	myClass2.print();
	myClass3.print();

	// 생성자 호출의 최근 방법
	MyClass myClass4{ 100 }; // {}로 생성자 호출 가능
	myClass4.print();
	MyClass myClass5{ -100, 'b' };
	myClass5.print();
	MyClass myClass6{ 'c' , 99 }; // 입력 순서를 바꾸면, 원래 생성자 입력 변수에 정의된 순서대로 생성자가 호출됨
	myClass6.print();
	MyClass myClass7 = { 200, 'd' }; // 배열 초기화처럼 생성자 호출
	myClass7.print();

	myClass7.setInt(-5000);
	cout << "myClass7의 int = " << myClass7.getInt() << endl;

	// 생성자 호출처럼 원시 자료형(char, int, double 등)의 초기화를 할 수 있음
	//int i = 10; // 초기화로 변수 정의
	int i(10); // 마치 생성자 호출처럼 변수 정의
	cout << "i = " << i << endl;
	double x = 20.1;
	i = (int)x; // C 방식: 형 선정(type casting)
	i = int(x); // C++ 방식: 형 선정(type casting)
	cout << "i = " << i << endl;

	MyClass myClass8 = myClass7; // 할당 연산자: 프로퍼티 전부가 저절로 복사
	myClass8.print();

	printClass(myClass8); // 깊은 복사: 함수 입력인 myClass = 입력한 변수인 myClass8 -> 실행 속도가 느림(프로퍼티 복사 때문에)
	printClassRef(myClass8); // 얕은 복사: 입력한 변수인 myClass8의 참조를 넘겨줌: 프로퍼티가 복사되지 않고 접근 권한만 생김 -> 실행 속도가 빨라짐(접근 권한만 넘기기 때문)
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
