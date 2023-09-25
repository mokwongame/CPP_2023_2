#include "CoinTossGame.h"

// namespace 변수 선언: namespace명::변수명
//int mglib::nTotalScore = 0;

// 승률 계산하기 위한 변수
// 1. 던진 회수 저장: int nTotalTry
// 2. 이긴 회수 저장: int nTotalWin
// 3. 승률: nTotalWin/(double)nTotalTry*100
int mglib::nTotalTry = 0;
int mglib::nTotalWin = 0;

// namespace 멤버 접근 없이 namespace를 다시 정의해서 전역 변수 선언(정의)
namespace mglib
{
	int nTotalScore = 0;
}