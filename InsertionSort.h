#pragma once
#include <vector>
#include <algorithm>
#include "SortVisualizer.h"



template<class T>
class InsertionSort : public SortVisualizer<T>
{
public:

	InsertionSort(int width, int height, std::vector<T> data);


	void sortWithDrawingSteps() override;
	void sortWithoutDrawingSteps() override;


private:

	void sort(bool draw) override;
	
};

template<class T>
inline InsertionSort<T>::InsertionSort(int width, int height, std::vector<T> data)
	: SortVisualizer<T>(width, height, data)
{
}

template<class T>
inline void InsertionSort<T>::sort(bool draw)
{	
	this->timerStart();

	for (size_t i = 0; i < this->m_data.size(); ++i)
	{
		unsigned int currI = i;
		
		this->setColor(currI, sf::Color::Red);

		while (true)
		{
			if (currI == 0)
			{
				this->resetColor(currI);
				break;
			}
			else if(this->m_data.at(currI - 1) <= this->m_data.at(currI))
			{
				this->resetColor(currI);
				break;
			}
			else if (this->m_data.at(currI - 1) > this->m_data.at(currI))
			{
				T temp = this->m_data.at(currI - 1);
				sf::RectangleShape& tempRect = this->m_visualizedData.at(currI- 1);

				this->switchPos(currI - 1, currI);

				if (draw)
					this->switchPosVisual(currI, currI - 1);
				

				currI--;
			}

			if (draw)
				this->drawData();
		}
		
		
	}

	this->timerStop();
}

template<class T>
inline void InsertionSort<T>::sortWithDrawingSteps()
{
	sort(true);
	this->doneSorting();
}

template<class T>
inline void InsertionSort<T>::sortWithoutDrawingSteps()
{
	sort(false);
	this->reloadVisuals();
	this->doneSorting();
}
