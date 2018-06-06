#ifndef TESTWORLDGENERATOR
#define TESTWORLDGENERATOR

#include "WorldGenerator.h"
#include "BasicRoom.h"
#include "Room.h"
class TestWorldGenerator : public WorldGenerator
{
public:
    std::shared_ptr<Room> generateRoomAt(Position pos, WorldInterface& worldInterface);
protected:

        const char* defaultRoomTexture = "../assets/art/FloorTiles/grassfloor.png";
}; 

#endif