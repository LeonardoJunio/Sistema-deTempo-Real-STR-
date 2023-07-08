#include <iostream>

#include "VectorUtil.hpp"

using namespace std;

// Note that the numbers are randomly generated based on a seed.
// If the same seed is passed, the random numbers will be the same
void VectorUtil::criarVector(
	int sizeVector, 
	int seed, 
	int *vectorQuickSort, 
	int *vectorBubbleSort)
{
	srand(seed);

	for (int i = 0; i < sizeVector; i++) {
		vectorQuickSort[i] = rand() % 100000;
		vectorBubbleSort[i] = vectorQuickSort[i]; // Using the same values
	}
}
