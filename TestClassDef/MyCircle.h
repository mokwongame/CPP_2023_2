#pragma once // 이 헤더 파일을 한 번만(once) 잘(pragmatic) 포함시키라는 뜻
// 파일명: MyCircle.h
// 객체(object): 문제를 풀기 위한 코드 블록의 기본 구조
// 클래스(class): 객체의 설계도
// 권고 사항: 파일명 == 클래스명
// 클래스명은 보통 대문자로 시작
class MyCircle // MyCircle이 클래스명
{
public: // public 그룹: 아래 있는 멤버는 모두 public
	double m_rad = 0.; // 반지름(radius); 접두어 m_는 멤버(member)를 표시; C 언어처럼 초기화

private: // private 그룹: 아래 있는 멤버는 모두 private(클래스 외부에서 접근 불가)

	double m_x = 0., m_y = 0.; // 원의 중심 좌표; C 언어처럼 초기화
protected: // protected 그룹
};