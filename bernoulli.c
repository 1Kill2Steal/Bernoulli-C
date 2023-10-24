#include <stdio.h>
#include <stdlib.h>

void evalBernoulli(int n, int k, int q, int pUpper, int pLower);

int main(int argc, char * argv[])
{
	int n, k, q, pUpper, pLower;
	n = k = q = pUpper = pLower = 0;

	if (argc < 5)
	{
        printf("Usage: %s <total> <positiveInstances> <positiveOutcome> <totalOutcome>\n", argv[0]);
        return 1;
    }

	n = atoi(argv[1]);
	k = atoi(argv[2]);
	q = n-k;
	pUpper = atoi(argv[3]);
	pLower = atoi(argv[4]);
	
	evalBernoulli(n, k, q, pUpper, pLower);

	return 0;
}

void evalBernoulli(int n, int k, int q, int pUpper, int pLower)
{
	double combinations = n;
	double combinations2 = 1;


	double positive = (double)pUpper/pLower;
	double negative = 1 - positive;
	
	double cSumTop, cSumBottom, positiveSum, negativeSum;
	cSumTop = cSumBottom = positiveSum = negativeSum = 1;

	for(int i = 0; i < k; ++i)
	{
		cSumTop *= (combinations - i);
		cSumBottom *= (combinations2 + i);
		positiveSum *= positive;
	}

	for(int i = 0; i < q; ++i)
	{
		negativeSum *= negative;
	}

	double resultPercentage = (cSumTop/cSumBottom) * positiveSum * negativeSum * 100.0;
	printf("%f%%\n", resultPercentage);
}
