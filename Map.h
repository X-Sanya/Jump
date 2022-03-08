#ifndef MAP
#define MAP

#include "Platform.h"
#include <vector>

class Map {
private:
	std::vector<Platform*> field;
	HANDLE* buffer;
public:
	Map(HANDLE*);
	Map(HANDLE*, SHORT);
	~Map();
	void init();
	HANDLE& get_buffer();
	bool is_platform(COORD, SHORT);
};

#endif //MAP
