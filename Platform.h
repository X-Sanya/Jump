#ifndef PLATFORM
#define PLATFORM
#include  <Windows.h>

class Platform {
private:
	COORD coord;
	HANDLE* buffer;
	SHORT size;
	void checkCoord();
	void chekSize();
public:
	Platform(HANDLE* ,COORD, SHORT size =3);
	bool draw();
	bool clear();
	COORD getCoord();
	SHORT getSize();
	bool isPlatform(COORD, SHORT);
};
#endif //PLATFORM
