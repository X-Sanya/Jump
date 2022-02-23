#include "Jumper.h"
#include "Platform.h"
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
	Platform* platf1 = new Platform(&hConsole, { -1,0 }, 6);
	jumper->draw();
	platf1->draw();

	

	SetConsoleActiveScreenBuffer(hConsole);
	while(jumper->go()){
		if (_kbhit())
			handler();
		if (platf1->isPlatform(jumper->getCoord(), 2))
			jumper->setGround(platf1);
		platf1->draw();
		jumper->draw();
		Sleep(50);
	}

	Sleep(15000);
	delete jumper;
	delete platf1;
	return 0;
}