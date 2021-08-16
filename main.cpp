#include <iostream>
#include <fstream>
#include <queue>
#include <ctime>
#include <array>

#include "LoadText.h"
#include "PrintText.h"
#include "ConsoleEdit.h"
#include "InputControl.h"

int main()
{
    Init();

    std::string path = GetPathToDocuments();

    std::ifstream textOpener(path);

    std::queue <char> bwSymbols;

    std::queue <std::pair <char, ConsoleColor>> lgbtSymbols;

    std::queue <char> inputSymbols;

    int mistakes = 0;

    unsigned int oldTime;

    std::array <int, 5> times;

    char symbol;

    if (textOpener.good())
    {
        for (size_t i = 0; i < 24; i++)
        {
            textOpener.get(symbol);
            bwSymbols.push(symbol);
            gotoxy(25 + i, 7);
            std::cout << symbol;
        }

        while (!textOpener.eof())
        {
            oldTime = clock();
            InputControl(bwSymbols, lgbtSymbols, inputSymbols, mistakes, oldTime, times);
            symbol = GetNextSymbol(textOpener);
            PrintText(bwSymbols, lgbtSymbols, symbol);
        }
    }

	return 0;
}