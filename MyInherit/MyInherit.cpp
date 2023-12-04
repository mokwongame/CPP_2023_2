// MyInherit.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/* [명함 관리 프로그램]
- 사람들 분류: 가족(Family), 친구(Friend), 동료(Peer) -> Person을 상속 받아서 생성
- 분류된 사람들의 공통 특성을 부모 클래스(Person)
- 명함을 파일에 저장
*/
#include <iostream>
#include "Person.h"
#include "Family.h"
#include "Friend.h"

// 먼저 부모 클래스부터 코딩
// 그 다음에 자식 클래스 코딩
int main()
{
	using namespace std;
	Person person;
	person.setName("홍길동");
	cout << person << endl << endl;

	Family family;
	family.setName("김철수");
	family.setRelation("형제");
	cout << family << endl << endl;

	Friend friend1;
	friend1.setName("이성계");
	friend1.setSchool("공과대");
	cout << friend1 << endl;
}
