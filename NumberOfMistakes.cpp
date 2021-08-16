#include "NumberOfMistakes.h"

void PrintNumberOfMistakes(int &mistakes)
{
	mistakes++;
	gotoxy(1, 1);
	std::cout << "Ошибок: " << mistakes;
}