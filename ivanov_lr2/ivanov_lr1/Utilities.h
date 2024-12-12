#pragma once
#include <iostream>

template <typename T>
T GetCorrectData(T min, T max)
{
	T x;
	while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cout << "\nPlease, enter the correct data! Data must be in the range [" << min << " - " << max << "]";
		std::cout << "\nTry again: ";
	}
	return x;
}