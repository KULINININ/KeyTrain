#include "InputControl.h"

/*bool InputValidation(char& c)//Checking for the necessary signs Is it necessary at all?
{
	if (((c >= 'à') && (c <= 'ÿ')) || ((c >= 'a') && (c <= 'z')) || (c == '.') || (c == ',') || (c == ' ') || ((c >= 'À') && (c <= 'ß')) || ((c >= 'A') && (c <= 'Z')) || (c == ':') || (c == ';') || (c == '"'))
	{
		return true;
	}

	return false;
}*/

void PrintInput(std::queue <char> &inputSymbols)// Outputs characters received from the keyboard
{
	if (inputSymbols.size() > 48)
	{
		inputSymbols.pop();
	}

	int x = 25 - inputSymbols.size() / 2;

	for (size_t i = 0; i < inputSymbols.size(); i++)
	{
		gotoxy(x + i, 18);
		std::cout << inputSymbols.front();
		inputSymbols.push(inputSymbols.front());
		inputSymbols.pop();
	}
}

void InputControl(std::queue <char> &bwSymbols, 
	std::queue <std::pair <char, ConsoleColor>> &lgbtSymbols, 
	std::queue <char> &inputSymbols, 
	int &mistakes, 
	unsigned int &oldTime,
	std::array <int, 5> &times)
{// Receiving keyboard input, adding LGBT characters to a queue, controlling the length of this queue
	char input = _getch();

	/*if (InputValidation(input))
	{*/
		inputSymbols.push(input);

		PrintInput(inputSymbols);
		
		std::pair <char, ConsoleColor> p;

		if (input == bwSymbols.front())
		{
			
			p = std::make_pair(bwSymbols.front(), Green);
			SpeedCalculation(oldTime, lgbtSymbols, times);
			lgbtSymbols.push(p);
		}
		else
		{
			p = std::make_pair(bwSymbols.front(), Red);
			lgbtSymbols.push(p);
			PrintNumberOfMistakes(mistakes);
		}

		if (lgbtSymbols.size() > 24)
		{
			lgbtSymbols.pop();
		}
	/*}*/
}