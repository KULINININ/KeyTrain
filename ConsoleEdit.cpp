#include "ConsoleEdit.h"

HANDLE hOutput;
CONSOLE_FONT_INFOEX fontInfo;

// Place "cursor" on position
void gotoxy(int x, int y) {//ПЕРЕДАТЬ ПО ССЫЛКЕ ???
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(hOutput, c);
}

// Set text and background color
void SetColor(ConsoleColor text, ConsoleColor background) {
	SetConsoleTextAttribute(hOutput, (WORD)((background << 4) | text));
}

// Resize the console window
void ResizeWindow() {
	system("mode con cols=50 lines=20");// Ограничение на размер окна

	system("color F0");//Покрасить в белый
}

// Change font // Works poorly
void EditFont() {
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hOutput, TRUE, &fontInfo);
	//wcscpy_s(fontInfo.FaceName, L"Times New Roman"); //Шрифт коряво работает
	fontInfo.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hOutput, TRUE, &fontInfo);
}

// Black bar + set cursor to center
void BlackStringAndSet() {
	gotoxy(0, 15);

	for (size_t i = 0; i < 50; i++)
	{
		SetColor(Black, Black);
		std::cout << " ";
	}

	SetColor(Black, White);
	gotoxy(25, 18);
}

// ResizeWindow and BlackStringAndSet
void EditField() {
	ResizeWindow();
	BlackStringAndSet();
	EditFont();
}

// Initializing access to the console window and enabling the Russian language
void Init() {
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	EditField();
}