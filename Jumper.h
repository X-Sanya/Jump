#ifndef JUMPER
#define JUMPER
#include <Windows.h>
#include "Platform.h"

enum class Direction {
	UP,
	DOWN
};

class Jumper {
private:
	COORD jumperCoord;
	Platform* ground;
	Platform* defGround;
	SHORT h;
	SHORT size = 2;
	Direction dir = Direction::UP;
	HANDLE* buffer;

	char eye = '*';
	bool goUp();
	bool goDown();
public:
	Jumper(HANDLE* , COORD, SHORT h  = 6 );
	~Jumper();
	bool go();
	bool draw();
	bool setGround(Platform*);
	bool moveRight();
	bool moveLeft();
	bool clear();
	COORD getCoord();
};
#endif //JUMPMER