#include <iostream>

#include "TimeSort.hpp"

int main()
{
	TimeSort timeSort;

	timeSort.checkTimeSorting(1000);
	timeSort.checkTimeSorting(5000);
	timeSort.checkTimeSorting(10000);
	timeSort.checkTimeSorting(50000);
	// timeSort.checkTimeSorting(100000);

	return EXIT_SUCCESS;
}
