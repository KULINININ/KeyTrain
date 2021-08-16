#pragma once

#include <conio.h>
#include <queue>
#include <array>

#include "ConsoleEdit.h"
#include "NumberOfMistakes.h"
#include "InputSpeed.h"

void InputControl(std::queue <char> &bwSymbols, 
	std::queue <std::pair <char, ConsoleColor>> &lgbtSymbols, 
	std::queue <char> &inputSymbols, 
	int &mistakes, 
	unsigned int &oldTime, 
	std::array <int, 5> &times);