#ifndef JUMPER
#define JUMPER
#include <Windows.h>

enum class Direction {
	UP,
	DOWN
};

class Jumper {
private:
	COORD jumperCoord;
	COORD groundCoord;
	SHORT h;
	Direction dir = Direction::UP;
	HANDLE* buffer;

	char eye = '*';

public:
	Jumper(HANDLE* , COORD, SHORT h  = 6);
	bool go();
	void draw();

};
#endif //JUMPMER