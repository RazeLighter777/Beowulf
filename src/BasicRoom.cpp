#include "BasicRoom.h"

BasicRoom::BasicRoom(std::string serial, WorldInterface& worldInterface_) :
worldInterface(worldInterface_)
{
    texturename = getNextProperty(serial);
    sprite.setTexture(worldInterface.getTexture(texturename));

}

WorldInterface& BasicRoom::getWorld() const
{
    return worldInterface;
}

sf::Sprite& BasicRoom::render()
{
    return sprite;
}

std::string BasicRoom::getName()
{
    return "BasicRoom:" + texturename;
}

bool BasicRoom::isSolid() 
{
    return false;
}

std::string BasicRoom::serialize()
{
    return texturename + ":";
}

std::string BasicRoom::getTypeName()
{
    return "BasicRoom";
}

std::string BasicRoom::getFactoryName()
{
    return typeid(BasicRoom).name();
}