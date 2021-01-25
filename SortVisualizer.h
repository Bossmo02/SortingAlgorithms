#pragma once
#include <iostream>
#include <chrono>
#include "SFML/Graphics.hpp"



template<class T>
class SortVisualizer
{
public:

	SortVisualizer(int width, int height, std::vector<T> data);

	virtual void sortWithDrawingSteps();
	virtual void sortWithoutDrawingSteps();

	const double getDuration();
	

protected:

	virtual void sort(bool draw);

	void resetColor(int pos);
	void setColor(int pos, sf::Color col);
	void doneSorting();

	void switchPosVisual(int pos1, int pos2);
	void switchPos(int pos1, int pos2);
	void timerStart();
	void timerStop();
	void reloadVisuals();
	void drawData();

	std::vector<T> m_data;
	std::vector<sf::RectangleShape> m_visualizedData;

private:

	std::chrono::steady_clock::time_point startTime; 
	std::chrono::steady_clock::time_point stopTime;

	sf::RenderWindow m_window;

	double m_widthVisuals;
	double m_stepHeightVisuals;
};

template<class T>
inline SortVisualizer<T>::SortVisualizer(int width, int height, std::vector<T> data)
{
	m_window.create(sf::VideoMode(width, height), "Sort Visualizer");
	m_data = data;

	m_widthVisuals = (double)width / m_data.size();

	try
	{
		float highestVal = 0;
		for (auto a : m_data)
		{
			if (a > highestVal)
				highestVal = a;
		}

		m_stepHeightVisuals = height / highestVal;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	for (size_t i = 0; i < m_data.size(); ++i)
	{
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(m_widthVisuals, m_stepHeightVisuals * m_data.at(i)));
		rect.setPosition(m_widthVisuals * i, m_window.getSize().y - rect.getSize().y);
		rect.setFillColor(sf::Color::White);
		m_visualizedData.push_back(rect);
	}

	std::cout << m_widthVisuals << std::endl;
	std::cout << m_stepHeightVisuals << std::endl;

	drawData();
}

template<class T>
inline void SortVisualizer<T>::sortWithDrawingSteps()
{
}

template<class T>
inline void SortVisualizer<T>::sortWithoutDrawingSteps()
{
}

template<class T>
inline void SortVisualizer<T>::drawData()
{
	m_window.clear();

	for (auto& a : m_visualizedData)
		m_window.draw(a);

	m_window.display();
}

template<class T>
inline void SortVisualizer<T>::sort(bool draw)
{
}

template<class T>
inline void SortVisualizer<T>::resetColor(int pos)
{
	m_visualizedData.at(pos).setFillColor(sf::Color::White);
}

template<class T>
inline void SortVisualizer<T>::setColor(int pos, sf::Color col)
{
	m_visualizedData.at(pos).setFillColor(col);
}

template<class T>
inline void SortVisualizer<T>::doneSorting()
{
	for (auto& a : m_visualizedData)
		a.setFillColor(sf::Color::Green);

	drawData();
}


template<class T>
inline void SortVisualizer<T>::switchPosVisual(int pos1, int pos2)
{
	// only swaps x-pos
	float tempPosX = m_visualizedData.at(pos1).getPosition().x;
	m_visualizedData.at(pos1).setPosition(m_visualizedData.at(pos2).getPosition().x, m_visualizedData.at(pos1).getPosition().y);
	m_visualizedData.at(pos2).setPosition(tempPosX, m_visualizedData.at(pos2).getPosition().y);

	// swaps data in m_visualizedData
	std::iter_swap(this->m_visualizedData.begin() + pos1, this->m_visualizedData.begin() + pos2);
}

template<class T>
inline void SortVisualizer<T>::switchPos(int pos1, int pos2)
{
	// swaps variables in m_data
	T temp = m_data.at(pos1);
	m_data.at(pos1) = m_data.at(pos2);
	m_data.at(pos2) = temp;
}

template<class T>
inline void SortVisualizer<T>::timerStart() 
{
	startTime = std::chrono::steady_clock::now();
}

template<class T>
inline void SortVisualizer<T>::timerStop()
{
	stopTime = std::chrono::steady_clock::now();
}

template<class T>
inline void SortVisualizer<T>::reloadVisuals()
{
	m_visualizedData.clear();

	for (size_t i = 0; i < m_data.size(); ++i)
	{
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(m_widthVisuals, m_stepHeightVisuals * m_data.at(i)));
		rect.setPosition(m_widthVisuals * i, m_window.getSize().y - rect.getSize().y);
		rect.setFillColor(sf::Color::White);
		m_visualizedData.push_back(rect);
	}
}

template<class T>
inline const double SortVisualizer<T>::getDuration()
{
	std::chrono::duration<double> elapsedTime = stopTime - startTime;
	return elapsedTime.count();
}
