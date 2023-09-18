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
		// �ڷ��� ������ = �ʱⰪ;
		CoinType nInput = inputCoin(); // =: �Ҵ� ������(������ �� -> ���� ������ �Ҵ�)
		if (nInput == CT_NULL) continue; // continue: �ݺ����� ó������ ���ư���
		// ���� ������: ���� �߻�
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
	return 0;
}