#include "Jumper.h"

Jumper::Jumper(HANDLE* _buffer, COORD _coord, SHORT _h) :buffer(_buffer),jumperCoord(_coord),h(_h){
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(*_buffer, &info);
	this->defGround = new Platform(_buffer, { 0, info.dwSize.Y }, info.dwSize.X-1);
	this->setGround(nullptr);
}
Jumper::~Jumper() { delete defGround; }
bool Jumper::draw() {
	DWORD dwBytesWrite = 0;
	COORD coordUp = this->jumperCoord;
	coordUp.Y--;
	if (!FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY, this->size, coordUp, &dwBytesWrite))
		return 0;
	if(!FillConsoleOutputCharacter(*this->buffer, this->eye, this->size, coordUp, &dwBytesWrite))
		return 0;
	if(!FillConsoleOutputCharacter(*this->buffer, ' ', this->size, this->jumperCoord, &dwBytesWrite))
		return 0;
	if(!FillConsoleOutputAttribute(*this->buffer, BACKGROUND_GREEN | BACKGROUND_INTENSITY, this->size, this->jumperCoord, &dwBytesWrite))
		return 0;
	return 1;
}
bool Jumper::go() {
	if (this->dir == Direction::UP) {
		if ((this->jumperCoord.Y + h) >= (this->ground->getCoord().Y)) {
			//move up
			return this->goUp();
		}
		//move down
		this->dir = Direction::DOWN;
		return this->goDown();
	}
	if ((this->jumperCoord.Y) < (this->ground->getCoord().Y-1)) {
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
	if (!this->clear())
		return 0;
	this->jumperCoord.X++;
	if (this->jumperCoord.X == this->defGround->getSize()) {
		this->jumperCoord.X = 0;
	}
	SHORT jumperX = this->jumperCoord.X;
	SHORT groundX = this->ground->getCoord().X;
	if ((jumperX + this->size-1 < groundX) || (jumperX > groundX + this->ground->getSize()-1))
		this->setGround(nullptr);
	return 1;
}
bool Jumper::moveLeft() {
	if (!this->clear())
		return 0;
	if (this->jumperCoord.X == 0) {
		this->jumperCoord.X = this->defGround->getSize();
	}
	this->jumperCoord.X--; 

	SHORT jumperX = this->jumperCoord.X;
	SHORT groundX = this->ground->getCoord().X;
	if ((jumperX + this->size-1 < groundX) || (jumperX > groundX + this->ground->getSize() - 1))
		this->setGround(nullptr);
	return 1;
}
bool Jumper::clear() {
	DWORD dwBytesWrite = 0;
	COORD coordUp = this->jumperCoord;
	coordUp.Y--;
	if (!FillConsoleOutputAttribute(*this->buffer, NULL, this->size, coordUp, &dwBytesWrite))
		return 0;
	if (!FillConsoleOutputCharacter(*this->buffer, ' ', this->size, coordUp, &dwBytesWrite))
		return 0;
	if (!FillConsoleOutputAttribute(*this->buffer, NULL, this->size, this->jumperCoord, &dwBytesWrite))
		return 0;
	return 1;
}
COORD Jumper::getCoord() {
	return this->jumperCoord;
}
bool Jumper::setGround(Platform* _ground) {
	if (_ground == nullptr)
		_ground = this->defGround;
	this->ground = _ground;
	return 1;
}