#ifndef WORLDGENERATOR
#define WORLDGENERATOR
#include "WorldInterface.h"
#include "typedef.h"
#include "Room.h"

struct WorldGenerator {
	
	virtual std::shared_ptr<Room> generateRoomAt(Position pos) = 0;

}

#endif