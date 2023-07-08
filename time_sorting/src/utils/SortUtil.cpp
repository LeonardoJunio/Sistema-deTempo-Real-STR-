#include <iostream>

#include "SortUtil.hpp"

using namespace std;

void SortUtil::bubbleSort(int *vector, int size)
{
	int aux;
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (vector[j] > vector[j + 1]) {
				aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}
}

// Function used by qsort to compare two numbers
int SortUtil::compareInts(const void *a, const void *b)
{
	int *arg1 = (int *)a;
	int *arg2 = (int *)b;

	if (*arg1 < *arg2) {
		return -1;
	} else if (*arg1 == *arg2) {
		return 0;
	} else {
		return 1;
	}
}
