#include "CoinTossGame.h"

// namespace ���� ����: namespace��::������
//int mglib::nTotalScore = 0;

// �·� ����ϱ� ���� ����
// 1. ���� ȸ�� ����: int nTotalTry
// 2. �̱� ȸ�� ����: int nTotalWin
// 3. �·�: nTotalWin/(double)nTotalTry*100
int mglib::nTotalTry = 0;
int mglib::nTotalWin = 0;

// namespace ��� ���� ���� namespace�� �ٽ� �����ؼ� ���� ���� ����(����)
namespace mglib
{
	int nTotalScore = 0;
}