#include "LoadText.h"

std::string GetPathToDocuments()//Getting the path to a file with text
{
	wchar_t* pBuffer = new wchar_t[1000];
	SHGetFolderPathW(NULL, CSIDL_MYDOCUMENTS, NULL, SHGFP_TYPE_CURRENT, pBuffer);
	std::wstring wpath = pBuffer;
	std::string path(wpath.begin(), wpath.end());
	path += "\\KeyboardTrainer\\TextSource.txt";
	return path;
}

char GetNextSymbol(std::ifstream &textOpener)//Getting the next character from a file
{
	char symbol;
	textOpener.get(symbol);
	return symbol;
}