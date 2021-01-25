#pragma once

#include <random>
#include <vector>

class Random
{
public:
	
	static Random & get();

	int getIntInRange(int min, int max);
	float getFloatInRange(float min, float max);

	template<class T>
	static std::vector<T> getRandomVector(int min, int max, int size);

protected:

	Random();

private:

	std::mt19937 m_gen;

};

template<class T>
inline std::vector<T> Random::getRandomVector(int min, int max, int size)
{
	std::vector<T> vec;
	vec.reserve(size);

	for (size_t i = 0; i < size; ++i)
	{
		vec.push_back(static_cast<T>(get().getFloatInRange(min, max)));
	}

	return vec;
}
