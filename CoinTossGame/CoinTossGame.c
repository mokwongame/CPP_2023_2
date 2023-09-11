/*
[Coin Toss Game 규칙]
1. 사용자가 앞면(Front), 뒷면(Back) 선택: 사용자 입력
2. 난수 발생 -> 동전의 앞면, 뒷면 선택
3. 사용자 입력과 난수를 비교해서 득점
*/
#include <stdio.h> // VS 헤더 파일 폴더 검색
#include "LibConsole.h" // 현재 폴더 검색
#include "LibGameTool.h"

// 상수 나열(enumeration): enum 상수나열명 {상수 선언};
enum CoinType
{CT_BACK=0, CT_FRONT, CT_NULL}; // CT_FRONT=1, CT_NULL=2

// 함수 선언(헤더 파일) -> 함수 정의(소스 파일)
enum CoinType inputCoin(void);

// 출력자료형 함수명(입력 선언, ...) {...}
void main(void) // void(없는)
{
	randseed(); // 난수 초기화; LibGameTool.h에 정의
	// 자료형 변수명 = 초기값;
	enum CoinType nInput = inputCoin(); // =: 할당 연산자(오른쪽 값 -> 왼쪽 변수에 할당)
}

// 함수 정의: 출력자료형 함수명(입력 선언, ...) {...}
enum CoinType inputCoin(void)
{
	return CT_NULL;
}
