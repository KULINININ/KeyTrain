#pragma once

#include <iostream>
#include <ShlObj.h>
#include <fstream>
#include <queue>

std::string GetPathToDocuments();

char GetNextSymbol(std::ifstream &textOpener);