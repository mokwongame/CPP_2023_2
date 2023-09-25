// Ȯ���� CoinTossGame.c(C compliler ���) -> CoinTossGame.cpp(C++ compiler ���)
// CoinTossGame.c�� �ʿ䰡 ��� �Ӽ� > ���忡�� ���� > ���� ����

/*
[Coin Toss Game ��Ģ]
0. ������ �ΰ�(���� �̸�, ������ �̸�) ���: namespace�� �Լ��� �ֱ�
1. ����ڰ� �ո�(Front), �޸�(Back) ����: ����� �Է�
2. ���� �߻� -> ������ �ո�, �޸� ����
3. ����� �Է°� ������ ���ؼ� ����
4. �·��� ���(�̻������δ� 50%)
*/

#include "CoinTossGame.h"

// �������� namespace �̸����� ���
//using namespace mglib; // mglib namespace ��ü ���

// ����ڷ��� �Լ���(�Է� ����, ...) {...}
int main(void) // void(����); main() �Լ��� return�� �ݵ�� int
{
	// main() �ڵ� ��Ͽ����� ����
	using namespace std; // std namespace ��ü ���
	using namespace mglib; // mglib namespace ��ü ���; mglib:: ���� ����� ���� ����
	randseed(); // ���� �ʱ�ȭ; LibGameTool.h�� ����
	while (1) // ��, ���� �Ǵ�: 0���� �ƴ��� �Ǵ�
	{
		// namespace ��� ����: namespace��::�����
		// �ڷ��� ������ = �ʱⰪ;
		CoinType nInput = inputCoin(); // =: �Ҵ� ������(������ �� -> ���� ������ �Ҵ�)
		if (nInput == CT_NULL) continue; // continue: �ݺ����� ó������ ���ư���
		// ���� ������: ���� �߻�
		CoinType nRand = randCoin();
		checkCoin(nInput, nRand);
	}
	return 0;
}