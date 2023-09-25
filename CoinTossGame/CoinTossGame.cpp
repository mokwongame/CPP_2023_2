// Ȯ���� CoinTossGame.c(C compliler ���) -> CoinTossGame.cpp(C++ compiler ���)
// CoinTossGame.c�� �ʿ䰡 ��� �Ӽ� > ���忡�� ���� > ���� ����

/*
[Coin Toss Game ��Ģ]
1. ����ڰ� �ո�(Front), �޸�(Back) ����: ����� �Է�
2. ���� �߻� -> ������ �ո�, �޸� ����
3. ����� �Է°� ������ ���ؼ� ����
*/

#include "CoinTossGame.h"

// ����ڷ��� �Լ���(�Է� ����, ...) {...}
int main(void) // void(����); main() �Լ��� return�� �ݵ�� int
{
	randseed(); // ���� �ʱ�ȭ; LibGameTool.h�� ����
	while (1) // ��, ���� �Ǵ�: 0���� �ƴ��� �Ǵ�
	{
		// namespace ��� ����: namespace��::�����
		// �ڷ��� ������ = �ʱⰪ;
		mglib::CoinType nInput = mglib::inputCoin(); // =: �Ҵ� ������(������ �� -> ���� ������ �Ҵ�)
		if (nInput == mglib::CT_NULL) continue; // continue: �ݺ����� ó������ ���ư���
		// ���� ������: ���� �߻�
		mglib::CoinType nRand = mglib::randCoin();
		mglib::checkCoin(nInput, nRand);
	}
	return 0;
}