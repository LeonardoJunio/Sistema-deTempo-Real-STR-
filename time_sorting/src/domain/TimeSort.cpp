#include <cstdlib> //qsort
#include <time.h>  // clock(),time()
#include <stdio.h> // printf()

#include "TimeSort.hpp"
#include "../utils/SortUtil.hpp"
#include "../utils/VectorUtil.hpp"

using namespace std;

void TimeSort::checkTimeSorting(int size)
{
    // Vectors used by the sorting methods
    int *vectorQuickSort = new int[size];
    int *vectorBubbleSort = new int[size];

    clock_t clockIniQSort, clockEndQSort, clockIniBSort, clockEndBSort;

    VectorUtil vectorUtil;

    // Create vectors with random elements
    vectorUtil.criarVector(size, 23, vectorQuickSort, vectorBubbleSort);

    clockIniQSort = clock();
    qsort(vectorQuickSort, size, sizeof(int), SortUtil::compareInts);
    clockEndQSort = clock();

    printf("Time %d QSort: %f \n", size, (double)(clockEndQSort - clockIniQSort) / (double)CLOCKS_PER_SEC);

    clockIniBSort = clock();
    SortUtil::bubbleSort(vectorBubbleSort, size);
    clockEndBSort = clock();

    printf("Time %d BubbleSort: %f \n", size, (double)(clockEndBSort - clockIniBSort) / (double)CLOCKS_PER_SEC);
}
