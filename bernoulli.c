#include <stdio.h>
#include <stdlib.h>

double evalBernoulli(int totalInstances, int positiveInstances, int negativeInstances, int positiveVariations, int totalVariations);

int main(int argc, char * argv[])
{
	int totalInstances, positiveInstances, negativeInstances, positiveVariations, totalVariations;
	totalInstances = positiveInstances = negativeInstances = positiveVariations = totalVariations = 0;

	if (argc < 5)
	{
        printf("Usage: %s <totalInstances> <positiveInstances> <negativeInstances> <positiveVariations> <totalVariations>\n", argv[0]);
        return 1;
	}

	totalInstances = atoi(argv[1]);
	positiveInstances = atoi(argv[2]);
	negativeInstances = totalInstances-positiveInstances;
	positiveVariations = atoi(argv[3]);
	totalVariations = atoi(argv[4]);
	
	double result = evalBernoulli(totalInstances, positiveInstances, negativeInstances, positiveVariations, totalVariations);

	printf("%f%%\n", result * 100.0);

	return 0;
}

double evalBernoulli(int totalInstances, int positiveInstances, int negativeInstances, int positiveVariations, int totalVariations)
{
	double combinations = totalInstances;
	double combinations2 = 1;


	double positive = (double)positiveVariations/totalVariations;
	double negative = 1 - positive;
	
	double cSumTop, cSumBottom, positiveSum, negativeSum;
	cSumTop = cSumBottom = positiveSum = negativeSum = 1;

	for(int i = 0; i < positiveInstances; ++i)
	{
		cSumTop *= (combinations - i);
		cSumBottom *= (combinations2 + i);
		positiveSum *= positive;
	}

	for(int i = 0; i < negativeInstances; ++i)
	{
		negativeSum *= negative;
	}

	return (cSumTop/cSumBottom) * positiveSum * negativeSum;
}
