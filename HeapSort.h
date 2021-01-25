#pragma once
#include "SortVisualizer.h"

#include "MaxHeap.h"
#include "MinHeap.h"


enum class HEAP_MODE
{
	MAX_HEAP = 0,
	MIN_HEAP
};

template<class T>
class HeapSort : public SortVisualizer<T>
{
public:

	HeapSort(int width, int height, std::vector<T> data);

	// currently not possible
	//void sortWithDrawingSteps(HEAP_MODE mode);

	void sortWithoutDrawingSteps(HEAP_MODE mode);


private:

	void minSort(bool draw);
	void maxSort(bool draw);

};

template<class T>
inline HeapSort<T>::HeapSort(int width, int height, std::vector<T> data)
	:SortVisualizer<T>(width, height, data)
{
}


template<class T>
inline void HeapSort<T>::sortWithoutDrawingSteps(HEAP_MODE mode)
{
	if (mode == HEAP_MODE::MAX_HEAP)
	{
		maxSort(false);
	}
	else
	{
		minSort(false);
	}

	this->reloadVisuals();
	this->doneSorting();
}

template<class T>
inline void HeapSort<T>::minSort(bool draw)
{
	// set up Heap obj
	MinHeap<T> minHeap;
	for (size_t i = 0; i < this->m_data.size(); ++i)
		minHeap.insertElement(this->m_data[i]);


	this->timerStart();

	for (size_t i = 0; i < this->m_data.size(); ++i)
	{
		this->m_data[i] = minHeap.extractNext();

		//if (draw)
		//	this->drawData();
	}

	this->timerStop();
}

template<class T>
inline void HeapSort<T>::maxSort(bool draw)
{
	// set up Heap obj
	MaxHeap<T> maxHeap;
	for (size_t i = 0; i < this->m_data.size(); ++i)
		maxHeap.insertElement(this->m_data[i]);


	this->timerStart();

	for (size_t i = 0; i < this->m_data.size(); ++i)
	{
		this->m_data[i] = maxHeap.extractNext();

		//if (draw)
		//	this->reloadVisuals();
	}

	this->timerStop();
}

