#include "CoinTossGame.h"

// 전역 변수와 함수: 캡슐화 X
int g_testVar = 10;
void testGlobalFun(void) {}

namespace mglib // namespace 파편화 가능: 아주 초보적인 상속(코드를 진화시킴) 개념
{
	void printMyName(void)
	{
		puts("Name: Cho");
	}
}

int main(void) // C++의 조건: main() 함수의 return은 반드시 int; (void): 입력이 없음(void)
{
	using mglib::CoinType; // using(사용하겠음): namespace 멤버를 편하게 사용하겠음; using을 쓰면 현재 코드 블록의 마지막까지만 적용됨
	using namespace mglib; // namespace 전체 멤버를 편하게 사용하겠음; using을 쓰면 현재 코드 블록의 마지막까지만 적용됨

	//int totalScore = 0; // 지역이 아니고 전역으로 쓰고 싶으면 헤더 파일과 다른 소스 파일을 사용
	int gameCount = 0;
	double winRatio = 0.;
	::g_testVar = 10; // 전역(global) namespace 관점으로 활용

	randseed();
	// namespace명::멤버(함수, 변수, 상수)
	// 콜론 연산자: 조건문을 삼항 연산자 -> (판별식) ? 표현식1 : 표현식2; namespace 멤버 접근에 콜론 2개를 사용
	showLogo(); // 인라인 함수라서 인라인 함수의 정의로 교체
	printMyName();
	while (1)
	{
		gameCount++;
		CoinType nInput = inputCoinType();
		if (nInput == mglib::CT_NULL) continue;

		CoinType nRand = mglib::randomCoinType();

		if (nInput == nRand)
		{
			puts("맞추었습니다.");
			g_totalScore++;
		}
		else
		{
			puts("틀렸습니다.");
			g_totalScore--;
		}

		winRatio = g_totalScore / (double)gameCount * 100.;
		mglib::printResult(g_totalScore, winRatio);
	}
	return 0;
}

void testFun(void)
{
	mglib::CoinType nCoin;
}