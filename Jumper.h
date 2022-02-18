#ifndef JUMPER
#define JUMPER
#include <Windows.h>
class Jumper {
private:
	COORD coord;
	HANDLE* buffer;
	char eye = '*';

public:
	Jumper(HANDLE* , COORD);
	void drawJumper();

};
#endif //JUMPMER