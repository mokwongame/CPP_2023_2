// 확장자 CoinTossGame.c(C compliler 사용) -> CoinTossGame.cpp(C++ compiler 사용)
// CoinTossGame.c는 필요가 없어서 속성 > 빌드에서 제외 > 예로 선택

/*
[Coin Toss Game 규칙]
0. 게임의 로고(게임 이름, 개발자 이름) 출력: namespace의 함수로 넣기
1. 사용자가 앞면(Front), 뒷면(Back) 선택: 사용자 입력
2. 난수 발생 -> 동전의 앞면, 뒷면 선택
3. 사용자 입력과 난수를 비교해서 득점
4. 승률도 출력(이상적으로는 50%)
*/

#include "CoinTossGame.h"

// 전역으로 namespace 이름없이 사용
//using namespace mglib; // mglib namespace 전체 사용

// 출력자료형 함수명(입력 선언, ...) {...}
int main(void) // void(없는); main() 함수의 return은 반드시 int
{
	// main() 코드 블록에서만 적용
	using namespace std; // std namespace 전체 사용
	using namespace mglib; // mglib namespace 전체 사용; mglib:: 없이 멤버에 접근 가능
	randseed(); // 난수 초기화; LibGameTool.h에 정의
	while (1) // 참, 거짓 판단: 0인지 아닌지 판단
	{
		// namespace 멤버 접근: namespace명::멤버명
		// 자료형 변수명 = 초기값;
		CoinType nInput = inputCoin(); // =: 할당 연산자(오른쪽 값 -> 왼쪽 변수에 할당)
		if (nInput == CT_NULL) continue; // continue: 반복문의 처음으로 돌아가기
		// 동전 던지기: 난수 발생
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
	return 0;
}