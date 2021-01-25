#pragma once
#include "SortVisualizer.h"
#include <deque>


/*

	Doesn't work rn.

*/


template<class T> 
class MergeSort : public SortVisualizer<T>
{
public:

	MergeSort(int width, int height, std::vector<T> data);

	void sortWithDrawingSteps() override;
	void sortWithoutDrawingSteps() override;

private:

	void sort(bool draw) override;

	std::vector<T>& mergeParts(std::vector<T>& leftPart, std::vector<T>& rightPart) const;
	std::vector<T> sortParts(std::vector<T>& part) const;
};

template<class T>
inline MergeSort<T>::MergeSort(int width, int height, std::vector<T> data)
	:SortVisualizer<T>(width, height, data)
{
}

template<class T>
inline void MergeSort<T>::sortWithDrawingSteps()
{
	sort(true);

	this->doneSorting();
}

template<class T>
inline void MergeSort<T>::sortWithoutDrawingSteps()
{
	sort(false);

	this->reloadVisuals();
	this->doneSorting();
}

template<class T>
inline void MergeSort<T>::sort(bool draw)
{
	this->timerStart();
	std::vector<T> res = sortParts(this->m_data);
	this->timerStop();

	this->m_data = res;
}

template<class T>
inline std::vector<T>& MergeSort<T>::mergeParts(std::vector<T>& leftPart, std::vector<T>& rightPart) const
{
	std::vector<T> combinedPart(leftPart.size()+rightPart.size());

	while (!leftPart.empty() && !rightPart.empty())
	{
		if (leftPart.at(0) <= rightPart.at(0))
		{
			combinedPart.push_back(leftPart.at(0));
			leftPart.erase(leftPart.begin());
		}
		else
		{
			combinedPart.push_back(rightPart.at(0));
			rightPart.erase(rightPart.begin());
		}
	}

	while (!leftPart.empty())
	{
		combinedPart.push_back(leftPart.at(0));
		leftPart.erase(leftPart.begin());
	}

	while (!rightPart.empty())
	{
		combinedPart.push_back(rightPart.at(0));
		rightPart.erase(rightPart.begin());
	}

	return combinedPart;
}

template<class T>
inline std::vector<T> MergeSort<T>::sortParts(std::vector<T>& part) const
{
	int half = part.size() / 2;

	std::vector<T> leftPart = { part.begin(), part.begin() + half };
	std::vector<T> rightPart = { part.begin() + half + 1, part.end() };


	try
	{
		if(leftPart.size() > 1)
			sortParts(leftPart);
		if(rightPart.size() > 1)
			sortParts(rightPart);
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}

	return mergeParts(leftPart, rightPart);
	
}
