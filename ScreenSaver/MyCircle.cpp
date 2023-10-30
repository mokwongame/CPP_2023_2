#include "MyCircle.h"

// 멤버 함수 정의
// 클래스명::함수명()
// 클래스 안에서 멤버에 접근할 때는 콜론 2개 사용(::)
// 이 코드 블록도 클래스 내부로 생각
void MyCircle::setCenter(double x, double y)
{
	m_x = x;
	m_y = y;
}
