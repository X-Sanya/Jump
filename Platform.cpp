#include "Platform.h"

Platform::Platform(HANDLE* _buffer, COORD _coord, SHORT _size):buffer(_buffer), coord(_coord), size(_size){
	this->chekSize();
	this->checkCoord();
}
void Platform::checkCoord() {
	CONSOLE_SCREEN_BUFFER_INFO inf;
	GetConsoleScreenBufferInfo(*this->buffer, &inf);
	if (this->coord.Y < 0)
		this->coord.Y = 0;
	else if (this->coord.Y >= inf.dwSize.Y)
		this->coord.Y = inf.dwSize.Y - 1;
	if (this->coord.X + this->size > inf.dwSize.X) {
		this->coord.X = inf.dwSize.X - 1;
		this->size = 1;
	}
	if (this->coord.X < 0)
		this->coord.X = 0;
}
void Platform::chekSize() {
	if (this->size > 5) {
		this->size = 5;
		return;
	}
	if (this->size < 1)
		this->size = 1;
}
bool Platform::draw() {
	DWORD dwBytesWrite = 0;
	return FillConsoleOutputAttribute(*this->buffer,BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY, this->size, this->coord, &dwBytesWrite);
}
bool Platform::clear() {
	DWORD dwBytesWrite = 0;
	return FillConsoleOutputAttribute(*this->buffer, NULL, this->size, this->coord, &dwBytesWrite);
}
COORD Platform::getCoord() {
	return this->coord;
}
SHORT Platform::getSize() {
	return this->size;
}
bool Platform::isPlatform(COORD _coord, SHORT _size) {
	return ((this->coord.Y-1 == _coord.Y) && (_coord.X >= this->coord.X - _size + 1) && (_coord.X < this->coord.X + this->size));
}