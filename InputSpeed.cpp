#include "InputSpeed.h"

void PrintSpeed(std::array <int, 5> &times)
{
	unsigned int sum = 0;

	for (auto elem:times)
	{
		sum += elem;
	}

	gotoxy(30, 1);
	std::cout << "Скорость: " << (60 * 1000) / (sum / times.size());
}

void SpeedCalculation(unsigned int &oldTime, std::queue <std::pair <char, ConsoleColor>>& lgbtSymbols, std::array <int, 5> &times)
{
	unsigned int newTime = clock();
	unsigned int time = newTime - oldTime;

	if (lgbtSymbols.size() >= times.size())
	{
		for (size_t i = 1; i < times.size() - 1; i++)
		{
			times[i - 1] = times[i];
		}

		times[times.size() - 1] = time;

		PrintSpeed(times);
	}
	else
	{
		times[lgbtSymbols.size()] = time;
	}
}