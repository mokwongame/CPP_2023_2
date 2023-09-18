// 확장자 CoinTossGame.c(C compliler 사용) -> CoinTossGame.cpp(C++ compiler 사용)
// CoinTossGame.c는 필요가 없어서 속성 > 빌드에서 제외 > 예로 선택

/*
[Coin Toss Game 규칙]
1. 사용자가 앞면(Front), 뒷면(Back) 선택: 사용자 입력
2. 난수 발생 -> 동전의 앞면, 뒷면 선택
3. 사용자 입력과 난수를 비교해서 득점
*/

#include "CoinTossGame.h"

// 출력자료형 함수명(입력 선언, ...) {...}
int main(void) // void(없는); main() 함수의 return은 반드시 int
{
	randseed(); // 난수 초기화; LibGameTool.h에 정의
	while (1) // 참, 거짓 판단: 0인지 아닌지 판단
	{
		// 자료형 변수명 = 초기값;
		CoinType nInput = inputCoin(); // =: 할당 연산자(오른쪽 값 -> 왼쪽 변수에 할당)
		if (nInput == CT_NULL) continue; // continue: 반복문의 처음으로 돌아가기
		// 동전 던지기: 난수 발생
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
	return 0;
}