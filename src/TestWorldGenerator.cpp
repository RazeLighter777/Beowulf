#include "TestWorldGenerator.h"

std::shared_ptr<Room> TestWorldGenerator::generateRoomAt(Position pos, WorldInterface& worldInterface)
{
    return worldInterface.createRoom(typeid(BasicRoom).name(), defaultRoomTexture);
}
