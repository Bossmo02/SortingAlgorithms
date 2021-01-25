#pragma once
#include "SortVisualizer.h"


template<class T>
class BubbleSort : public SortVisualizer<T>
{
public:

	BubbleSort(int width, int height, std::vector<T> data);


	void sortWithDrawingSteps() override;
	void sortWithoutDrawingSteps() override;


private:

	void sort(bool draw) override;

};



template<class T>
inline BubbleSort<T>::BubbleSort(int width, int height, std::vector<T> data)
	:SortVisualizer<T>(width, height, data)
{
}

template<class T>
inline void BubbleSort<T>::sortWithDrawingSteps()
{
	sort(true);
	this->doneSorting();
}

template<class T>
inline void BubbleSort<T>::sortWithoutDrawingSteps()
{
	sort(false);
	this->reloadVisuals();
	this->doneSorting();
}

template<class T>
inline void BubbleSort<T>::sort(bool draw)
{
	this->timerStart();

	for (size_t i = this->m_data.size(); i > 1; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (draw)
			{
				this->setColor(j, sf::Color::Red);
				this->setColor(j+1, sf::Color::Red);
			}

			if (this->m_data.at(j) > this->m_data.at(j + 1))
			{
				this->switchPos(j, j+1);
				
				if (draw)
				{
					this->switchPosVisual(j, j + 1);
					this->drawData();
				}
			}

			if (draw)
			{
				this->resetColor(j);
				this->resetColor(j+1);
			}
		}
	}


	this->timerStop();
}
