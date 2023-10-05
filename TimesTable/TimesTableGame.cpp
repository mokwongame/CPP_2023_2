#include "TimesTableGame.h"

/* [구구단 게임]
0. 구구단 규칙
 - 9단 이하 출력은 1부터 9까지 곱한 결과를 생성: 1*a = , 2*a = , ..., 9*a =
 - 10단 이상 출력은 최대 단까지 곱한 결과를 생성: 1*a = , 2*a = , ..., 9*a = , 10*a = , ... a*a =
1. 메뉴 선택
(1) 모든 구구단 출력: 최대 단수를 입력받아서 1단부터 최대 단까지 출력
(2) 사용자가 원하는 단만 출력
*/

int main(void)
{
	using namespace std;
	// 인스턴스 선언: 클래스명 인스턴스명(변수명);
	// 이때 생성자가 호출
	TimesTableGame timesTableGame;
	timesTableGame.printLogo(); // 인스턴스의 멤버 접근은 점(.) 연산자
	// 메뉴 출력
	timesTableGame.printMenu();
	// 사용자 입력
	int nMenu = timesTableGame.inputMenu();
	//cout << "입력한 번호: " << nMenu;
	timesTableGame.exeMenu(nMenu);
	return 0;
	// 인스턴스가 파괴될 때는 소멸자 호출
}