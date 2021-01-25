#pragma once
#include "SortVisualizer.h"

template<class T>
class QuickSort : public SortVisualizer<T>
{
public:

	QuickSort(int width, int height, std::vector<T> data);

	void sortWithDrawingSteps() override;
	void sortWithoutDrawingSteps() override;

private:

	void sort(bool draw) override;

	// extra Quicksort functions
	T sortSection(T leftBorder, T rightBorder, bool draw);
	void quickSort(T left, T right, bool draw);
};


template<class T>
inline QuickSort<T>::QuickSort(int width, int height, std::vector<T> data)
	:SortVisualizer<T>(width, height, data)
{
}

template<class T>
inline void QuickSort<T>::sortWithDrawingSteps()
{
	this->timerStart();
	sort(true);
	this->timerStop();
	this->doneSorting();
}

template<class T>
inline void QuickSort<T>::sortWithoutDrawingSteps()
{
	this->timerStart();
	sort(false);
	this->timerStop();
	this->reloadVisuals();
	this->doneSorting();
}

template<class T>
inline void QuickSort<T>::sort(bool draw)
{
	quickSort(0, this->m_data.size()-1, draw);
}


template<class T>
inline T QuickSort<T>::sortSection(T leftBorder, T rightBorder, bool draw)
{
	T left = leftBorder;
	T right = rightBorder - 1;
	T pivot = this->m_data.at(rightBorder);

	while (left < right)
	{
		while (left < rightBorder && this->m_data.at(left) < pivot)
		{
			left++;
		}

		while (right > leftBorder && this->m_data.at(right) >= pivot)
		{
			right--;
		}

		if (left < right)
		{
			this->switchPos(left, right);

			if (draw)
			{
				this->switchPosVisual(left, right);
				this->drawData();
			}
		}
	}

	if (this->m_data.at(left) > pivot)
	{
		this->switchPos(left, rightBorder);

		if (draw)
		{
			this->switchPosVisual(left, rightBorder);
			this->drawData();
		}
	}

	return left;
}

template<class T>
inline void QuickSort<T>::quickSort(T left, T right, bool draw)
{
	if (left < right)
	{
		T divider = sortSection(left, right, draw);
		quickSort(left, divider - 1, draw);
		quickSort(divider + 1, right, draw);
	}
}
