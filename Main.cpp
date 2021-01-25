#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "ShakerSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "Random.h"


#define DATA_TYPE double

int main()
{
	std::vector<DATA_TYPE> randVec = Random::getRandomVector<DATA_TYPE>(0, 100, 10000);

	HeapSort<DATA_TYPE> sorter(1000, 750, randVec);

	sorter.sortWithoutDrawingSteps(HEAP_MODE::MAX_HEAP);

	std::cout << "Done in: " << sorter.getDuration() << "s\n";

	std::cin.get();

	return 0;
}