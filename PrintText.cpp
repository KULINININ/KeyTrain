#include "PrintText.h"

void ChooseColor (ConsoleColor color)
{
	if (color == Green)
	{
		SetColor(White, Green);
	}
	else
	{
		SetColor(White, Red);
	}
}

void PrintText(std::queue <char> &bwSymbols, std::queue <std::pair <char, ConsoleColor>> &lgbtSymbols, char &symbol)
{
	if (lgbtSymbols.size() < 25)
	{
		for (size_t i = 0; i < lgbtSymbols.size(); i++)//Output of LGBT text with a shift to the left
		{
			gotoxy(25 - lgbtSymbols.size() + i, 7);
			ChooseColor(lgbtSymbols.front().second);
			std::cout << lgbtSymbols.front().first;
			lgbtSymbols.push(lgbtSymbols.front());
			lgbtSymbols.pop();
		}
	}
	else
	{
		for (size_t i = 0; i < lgbtSymbols.size(); i++)//Output of LGBT text
		{
			gotoxy(1 + i,7);
			ChooseColor(lgbtSymbols.front().second);
			std::cout << lgbtSymbols.front().first;
			lgbtSymbols.push(lgbtSymbols.front());
			lgbtSymbols.pop();
		}
	}

	bwSymbols.push(symbol);
	bwSymbols.pop();

	SetColor(Black, White);

	for (size_t i = 0; i < bwSymbols.size(); i++)//Output of BW text
	{
		gotoxy(25 + i, 7);
		std::cout << bwSymbols.front();
		bwSymbols.push(bwSymbols.front());
		bwSymbols.pop();
	}
}