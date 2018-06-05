#ifndef WORLDGENERATOR
#define WORLDGENERATOR
#include "WorldInterface.h"
#include "typedefs.h"
#include "Room.h"

struct WorldGenerator {
	
	virtual std::shared_ptr<Room> generateRoomAt(Position pos, WorldInterface& worldInterface) = 0;

};

#endif