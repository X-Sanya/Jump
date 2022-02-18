#include "Jumper.h"

Jumper::Jumper(HANDLE* _buffer, COORD _coord, SHORT _h) :buffer(_buffer),jumperCoord(_coord), groundCoord(_coord),h(_h){}
void Jumper::draw() {
	DWORD dwBytesWrite = 0;
	COORD coordUp = this->jumperCoord;
	coordUp.Y--;
	FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY, 2, coordUp, &dwBytesWrite);
	FillConsoleOutputCharacter(*this->buffer, this->eye, 2, coordUp, &dwBytesWrite);
	FillConsoleOutputCharacter(*this->buffer, ' ', 2, this->jumperCoord, &dwBytesWrite);
	FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_INTENSITY, 2, this->jumperCoord, &dwBytesWrite);
}
bool Jumper::go() {
	if (this->dir == Direction::UP) {
		if ((this->jumperCoord.Y + h) != (this->groundCoord.Y)) {
			DWORD dwBytesWrite = 0;
			FillConsoleOutputAttribute(*this->buffer, NULL, 2, this->jumperCoord, &dwBytesWrite);
			this->jumperCoord.Y--;
			return true;
		}
		this->dir = Direction::DOWN;
	}
	if (this->dir == Direction::DOWN) {
		if ((this->jumperCoord.Y) != (this->groundCoord.Y)) {
			DWORD dwBytesWrite = 0;
			COORD coordUp = this->jumperCoord;
			coordUp.Y--;
			FillConsoleOutputAttribute(*this->buffer, NULL, 2, coordUp, &dwBytesWrite);
			FillConsoleOutputCharacter(*this->buffer, ' ', 2, coordUp, &dwBytesWrite);
			this->jumperCoord.Y++;
			return true;
		}
	}
	return false;
}