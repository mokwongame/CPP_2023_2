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
{
	CT_BACK = 0, CT_FRONT, CT_NULL
}; // CT_FRONT=1, CT_NULL=2

// 함수 선언(헤더 파일) -> 함수 정의(소스 파일)
enum CoinType inputCoin(void);
enum CoinType randCoin(void);

// 출력자료형 함수명(입력 선언, ...) {...}
void main(void) // void(없는)
{
	randseed(); // 난수 초기화; LibGameTool.h에 정의
	while (1) // 참, 거짓 판단: 0인지 아닌지 판단
	{
		// 자료형 변수명 = 초기값;
		enum CoinType nInput = inputCoin(); // =: 할당 연산자(오른쪽 값 -> 왼쪽 변수에 할당)
		if (nInput == CT_NULL) continue; // continue: 반복문의 처음으로 돌아가기
		// 동전 던지기: 난수 발생
		enum CoinType nRand = randCoin();
	}
}

// 함수 정의: 출력자료형 함수명(입력 선언, ...) {...}
enum CoinType inputCoin(void)
{
	puts("동전 앞면(F)이나 뒷면(B)을 선택하세요."); // 문자열(string) 출력
	printf("당신의 선택은? ");
	char cInput = _getche(); // e: echo(반향)
	if (cInput == 'F' || cInput == 'f')
	{
		puts("\n앞면을 선택했습니다.");
		return CT_FRONT;
	}
	else if (cInput == 'B' || cInput == 'b')
	{
		puts("\n뒷면을 선택했습니다.");
		return CT_BACK;
	}
	else
	{
		puts("\n잘못 입력했습니다.");
		return CT_NULL;
	}
}

enum CoinType randCoin(void)
{
	puts("아무 키나 누르면 동전을 던집니다.");
	_getch(); // 글자 한 자(char) 입력; echo X
	int nRand = randrange(0, 2); // (0, 2-1) 범위에서 정수 난수 발생
	enum CoinType nRandCoin = (enum CoinType)nRand;
	if (nRandCoin == CT_BACK)
		puts("나온 동전은 뒷면입니다.");
	else puts("나온 동전은 앞면입니다.");
	return nRandCoin;
}
