#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int total, positiveInstances, negativeInstances, positiveOutcome, totalOutcome;
	total = positiveInstances = negativeInstances = positiveOutcome = totalOutcome;

	if (argc < 5) {
        printf("Usage: %s <total> <positiveInstances> <positiveOutcome> <totalOutcome>\n", argv[0]);
        return 1;
    }

	total = atoi(argv[1]);
	positiveInstances = atoi(argv[2]);
	negativeInstances = total-positiveInstances;
	positiveOutcome = atoi(argv[3]);
	totalOutcome = atoi(argv[4]);
	
	/* if(totalOutcome == 0) */
	/* 	return "arguments: total instances (1), positive instances (2), positive outcome/s (3), total possivle outcomes (4)"; */

	printf("%d, %d, %d, %d, %d\n", total, positiveInstances, negativeInstances, positiveOutcome, totalOutcome); // added it for debug purposes

	double combinations = total;
	double combinations2 = 1;


	double positive = (double)positiveOutcome/totalOutcome;
	double negative = 1 - positive;

	double cSumTop = 1;
	double cSumBottom = 1;

	double positiveSum = 1;
	double negativeSum = 1;
	
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

	double result = (cSumTop/cSumBottom) * positiveSum * negativeSum * 100.0;
	printf("%f%%\n", result);
	
	return 0;
}
