#include "Jumper.h"


int main() {
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	CONSOLE_CURSOR_INFO infCurs = { 1, 0 };
	CONSOLE_SCREEN_BUFFER_INFO infScr;
	SetConsoleCursorInfo(hConsole, &infCurs);

	DWORD dwBytesWrite = 0;
	COORD coord = { 40, 29 };

 	Jumper* jumper = new Jumper(&hConsole, coord);
	jumper->drawJumper();


	SetConsoleActiveScreenBuffer(hConsole);


	Sleep(15000);
	delete jumper;
	return 0;
}