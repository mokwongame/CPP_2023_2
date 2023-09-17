#include "CoinTossGame.h"

// ���� ������ �Լ�: ĸ��ȭ X
int g_testVar = 10;
void testGlobalFun(void) {}

namespace mglib // namespace ����ȭ ����: ���� �ʺ����� ���(�ڵ带 ��ȭ��Ŵ) ����
{
	void printMyName(void)
	{
		puts("Name: Cho");
	}
}

int main(void) // C++�� ����: main() �Լ��� return�� �ݵ�� int; (void): �Է��� ����(void)
{
	using mglib::CoinType; // using(����ϰ���): namespace ����� ���ϰ� ����ϰ���; using�� ���� ���� �ڵ� ����� ������������ �����
	using namespace mglib; // namespace ��ü ����� ���ϰ� ����ϰ���; using�� ���� ���� �ڵ� ����� ������������ �����

	//int totalScore = 0; // ������ �ƴϰ� �������� ���� ������ ��� ���ϰ� �ٸ� �ҽ� ������ ���
	int gameCount = 0;
	double winRatio = 0.;
	::g_testVar = 10; // ����(global) namespace �������� Ȱ��

	randseed();
	// namespace��::���(�Լ�, ����, ���)
	// �ݷ� ������: ���ǹ��� ���� ������ -> (�Ǻ���) ? ǥ����1 : ǥ����2; namespace ��� ���ٿ� �ݷ� 2���� ���
	showLogo(); // �ζ��� �Լ��� �ζ��� �Լ��� ���Ƿ� ��ü
	printMyName();
	while (1)
	{
		gameCount++;
		CoinType nInput = inputCoinType();
		if (nInput == mglib::CT_NULL) continue;

		CoinType nRand = mglib::randomCoinType();

		if (nInput == nRand)
		{
			puts("���߾����ϴ�.");
			g_totalScore++;
		}
		else
		{
			puts("Ʋ�Ƚ��ϴ�.");
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