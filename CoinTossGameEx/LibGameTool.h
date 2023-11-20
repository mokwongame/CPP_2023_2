/*-------------------------------------------------------------------
LibGameTool.h: Library for Game Tool
Author: ictplusud@gmail.com (Department of Game SW Engineering, Mokwon University)

Copyright �� 2023-Forever Mokwon Game, Korea.
All Rights Reserved. Personal and non-commercial purpose only.
-------------------------------------------------------------------*/

#pragma once

#include <stdlib.h>
#include <time.h>

/*-------------------------------------------------------------------
Definition of Data or Types
-------------------------------------------------------------------*/

/*-------------------------------------------------------------------
Random Number Generator
-------------------------------------------------------------------*/
// ���� �߻��� �ʱ�ȭ
inline void randseed()
{
	time_t nTime = time(NULL);
	srand((unsigned int)llabs(nTime * nTime));
}

// rmin, rmin+1, ..., rmax-1 ������ ���� ���
inline int randrange(int rmin, int rmax)
{
	if (rmin < rmax)
	{
		int nRand = rand() % (rmax - rmin);
		return nRand + rmin;
	}
	else if (rmin == rmax) return rmin;
	else return 0;
}

// [0, 1] ������ �յ� ���� ���
inline double random()
{
	return rand() / (double)RAND_MAX;
}

// [dmin, dmax] ������ �յ� ���� ���
inline double uniform(double dmin, double dmax)
{
	if (dmin < dmax) return random() * (dmax - dmin) + dmin;
	else if (dmin == dmax) return dmin;
	else return 0.;
}

/*-------------------------------------------------------------------
Revision Records
---------------------------------------------------------------------
C(2023-04-14): create for random number operations
-------------------------------------------------------------------*/