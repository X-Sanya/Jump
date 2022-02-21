#include "Jumper.h"
#include <conio.h>

Jumper* jumper;

bool handler() {
	char sign = _getch();
	switch (sign) {
	case -32:
		sign = _getch();
		switch (sign) {
		case 77:
			jumper->moveRight();
			break;
		case 75:
			jumper->moveLeft();
			break;
		}
		break;
	}
	return 1;
}

int main(){
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	CONSOLE_CURSOR_INFO infCurs = { 1, 0 };
	CONSOLE_SCREEN_BUFFER_INFO infScr;
	SetConsoleCursorInfo(hConsole, &infCurs);

	DWORD dwBytesWrite = 0;
	COORD coord = { 40, 29 };

 	jumper = new Jumper(&hConsole, coord, 6);
	jumper->draw();


	SetConsoleActiveScreenBuffer(hConsole);
	while(jumper->go()){
		if (_kbhit())
			handler();

		jumper->draw();
		Sleep(50);
	}

	Sleep(15000);
	delete jumper;
	return 0;
}