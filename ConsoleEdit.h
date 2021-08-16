#pragma once

#include <iostream>
#include <windows.h>

#include "Colors.h"

// Initializing access to the console window and enabling the Russian language
void Init();

// Place "cursor" on position
void gotoxy(int x, int y);

// Set text and background color
void SetColor(ConsoleColor text, ConsoleColor background);