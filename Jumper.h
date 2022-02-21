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
	bool goUp();
	bool goDown();
public:
	Jumper(HANDLE* , COORD, SHORT h  = 6);
	bool go();
	bool draw();
	bool setGround(COORD);
	bool moveRight();
	bool moveLeft();
	bool clear();
};
#endif //JUMPMER