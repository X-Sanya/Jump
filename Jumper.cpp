#include "Jumper.h"

Jumper::Jumper(HANDLE* _buffer, COORD _coord) :coord(_coord){
	this->buffer = _buffer;
}
void Jumper::drawJumper() {
	DWORD dwBytesWrite = 0;
	COORD coordUp = this->coord;
	coordUp.Y--;
	FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY, 2, coordUp, &dwBytesWrite);
	FillConsoleOutputCharacter(*this->buffer, eye, 2, coordUp, &dwBytesWrite);
	FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_INTENSITY, 2, this->coord, &dwBytesWrite);
}