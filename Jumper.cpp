#include "Jumper.h"

Jumper::Jumper(HANDLE* _buffer, COORD _coord, SHORT _h) :buffer(_buffer),jumperCoord(_coord), groundCoord(_coord),h(_h){}
bool Jumper::draw() {
	DWORD dwBytesWrite = 0;
	COORD coordUp = this->jumperCoord;
	coordUp.Y--;
	if (!FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY, 2, coordUp, &dwBytesWrite))
		return 0;
	if(!FillConsoleOutputCharacter(*this->buffer, this->eye, 2, coordUp, &dwBytesWrite))
		return 0;
	if(!FillConsoleOutputCharacter(*this->buffer, ' ', 2, this->jumperCoord, &dwBytesWrite))
		return 0;
	if(!FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_INTENSITY, 2, this->jumperCoord, &dwBytesWrite))
		return 0;
	return 1;
}
bool Jumper::go() {
	if (this->dir == Direction::UP) {
		if ((this->jumperCoord.Y + h) != (this->groundCoord.Y)) {
			//move up
			return this->goUp();
		}
		//move down
		this->dir = Direction::DOWN;
		return this->goDown();
	}
	if ((this->jumperCoord.Y) != (this->groundCoord.Y)) {
		//move down
		return this->goDown();
	}
	this->dir = Direction::UP;
	return goUp();
}
bool Jumper::goUp() {
	if(!this->clear())
		return 0;
	this->jumperCoord.Y--;
	return true;
}
bool Jumper::goDown() {
	if(!this->clear())
		return 0;
	this->jumperCoord.Y++;
	return true;
}
bool Jumper::moveRight() {
	CONSOLE_SCREEN_BUFFER_INFO inf;
	if (!GetConsoleScreenBufferInfo(*this->buffer, &inf))
		return 0;
	if (!this->clear())
		return 0;
	this->jumperCoord.X++;
	if (this->jumperCoord.X == inf.dwSize.X) {
		this->jumperCoord.X = 0;
	}
	return 1;
}
bool Jumper::moveLeft() {
	CONSOLE_SCREEN_BUFFER_INFO inf;
	if (!GetConsoleScreenBufferInfo(*this->buffer, &inf))
		return 0;
	if (!this->clear())
		return 0;
	if (this->jumperCoord.X == 0) {
		this->jumperCoord.X = inf.dwSize.X;
	}
	this->jumperCoord.X--;
	return 1;
}
bool Jumper::clear() {
	DWORD dwBytesWrite = 0;
	COORD coordUp = this->jumperCoord;
	coordUp.Y--;
	if (!FillConsoleOutputAttribute(*this->buffer, NULL, 2, coordUp, &dwBytesWrite))
		return 0;
	if (!FillConsoleOutputCharacter(*this->buffer, ' ', 2, coordUp, &dwBytesWrite))
		return 0;
	if (!FillConsoleOutputAttribute(*this->buffer, NULL, 2, this->jumperCoord, &dwBytesWrite))
		return 0;
	return 1;
}