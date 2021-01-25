#pragma once

#include "SortVisualizer.h"


template<class T>
class SelectionSort : public SortVisualizer<T>
{
public:

	SelectionSort(int width, int height, std::vector<T> data);


	void sortWithDrawingSteps() override;
	void sortWithoutDrawingSteps() override;


private:

	void sort(bool draw);


};

template<class T>
inline SelectionSort<T>::SelectionSort(int width, int height, std::vector<T> data)
	:SortVisualizer<T>(width, height, data)
{
}

template<class T>
inline void SelectionSort<T>::sortWithDrawingSteps()
{
	this->timerStart();
	sort(true);
	this->timerStop();
	this->doneSorting();
}

template<class T>
inline void SelectionSort<T>::sortWithoutDrawingSteps()
{
	this->timerStart();
	sort(false);
	this->timerStop();
	this->reloadVisuals();
	this->doneSorting();
}

template<class T>
inline void SelectionSort<T>::sort(bool draw)
{
	for (size_t i = 0; i < this->m_data.size(); ++i)
	{
		for (size_t j = i; j < this->m_data.size(); ++j)
		{
			if(draw)
				this->setColor(i, sf::Color::Red);

			if (this->m_data.at(i) > this->m_data.at(j))
			{
				this->switchPos(i, j);

				if (draw)
				{
					this->resetColor(i);
					this->switchPosVisual(i, j);
				}
			}

			if (draw)
			{
				this->drawData();
				this->resetColor(i);
			}
		}
	}
}
