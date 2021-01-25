#pragma once
#include "SortVisualizer.h"


template<class T> 
class ShakerSort : public SortVisualizer<T>
{
public:

	ShakerSort(int width, int height, std::vector<T> data);

	void sortWithDrawingSteps() override;
	void sortWithoutDrawingSteps() override;

private:

	void sort(bool draw) override;


};

template<class T>
inline ShakerSort<T>::ShakerSort(int width, int height, std::vector<T> data)
	:SortVisualizer<T>(width, height, data)
{
}

template<class T>
inline void ShakerSort<T>::sortWithDrawingSteps()
{
	sort(true);
	this->doneSorting();
}

template<class T>
inline void ShakerSort<T>::sortWithoutDrawingSteps()
{
	sort(false);
	this->reloadVisuals();
	this->doneSorting();
}

template<class T>
inline void ShakerSort<T>::sort(bool draw)
{
	this->timerStart();

	size_t left = 0, right = this->m_data.size() - 2;

	for (size_t i = 0; i < this->m_data.size()/2; ++i)
	{
		// left to right
		for (size_t j = left; j <= right; ++j)
		{
			if (draw)
			{
				this->setColor(j, sf::Color::Red);
			}

			if (this->m_data[j] > this->m_data[j + 1])
			{
				this->switchPos(j, j + 1);

				if (draw)
				{
					this->switchPosVisual(j, j + 1);
					this->drawData();
				}
			}

			if (draw)
			{
				this->resetColor(j);
				this->resetColor(j + 1);
			}
		}

		// right to left
		for (size_t j = right; j > left; --j)
		{
			if (draw)
			{
				this->setColor(j, sf::Color::Red);
			}

			if (this->m_data[j] < this->m_data[j - 1])
			{
				this->switchPos(j, j - 1);

				if (draw)
				{
					this->switchPosVisual(j, j - 1);
					this->drawData();
				}
			}

			if (draw)
			{
				this->resetColor(j);
				this->resetColor(j - 1);
			}
		}

		left++;
		right--;
	}

	this->timerStop();
}
