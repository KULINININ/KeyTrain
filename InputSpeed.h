#pragma once

#include <ctime>
#include <queue>
#include <array>

#include "Colors.h"
#include "ConsoleEdit.h"

void SpeedCalculation(unsigned int &oldTime, std::queue <std::pair <char, ConsoleColor>>& lgbtSymbols, std::array <int, 5> &times);