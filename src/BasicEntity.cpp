#include "BasicRoom.h"

WorldInterface& BasicEntity::getWorld() const
{
    return worldInterface;
}

std::string BasicEntity::getName() 
{
    return "BasicEntity";
}

BasicEntity::BasicEntity(Position position_, WorldInterface& worldInterface_) :
worldInterface(worldInterface_),
position(position_)
{
    sf::Sprite* defaultsprite = new sf::Sprite();
    defaultsprite->setTexture(worldInterface.getTexture(textureName));
    spriteLayers.push_back(defaultsprite);
}

BasicEntity::BasicEntity(std::string& serialization, WorldInterface& worldInterface_) :
worldInterface(worldInterface_)
{
    sf::Sprite* defaultsprite = new sf::Sprite();
    textureName = getNextProperty(serialization);
    defaultsprite->setTexture(worldInterface.getTexture(textureName));
    spriteLayers.push_back(defaultsprite);
    position.first = std::stoi(getNextProperty(serialization));
    position.second = std::stoi(getNextProperty(serialization));
}

Position BasicEntity::getPosition()
{
    return position;
}

std::string BasicEntity::getFactoryName() const
{
    return typeid(BasicEntity).name();
}

std::vector<sf::Sprite*> BasicEntity::render()
{
    return spriteLayers;
}

std::string BasicEntity::getTypeName()
{
    return std::string("BasicEntity");
}

bool BasicEntity::isDead()
{
    return false;
}

void BasicEntity::update()
{
    return;
}

std::string BasicEntity::serialize()
{
    return textureName + ":" + std::to_string(position.first) + ":" + std::to_string(position.second) + ":";
}

void BasicEntity::damage(AttackDescriptor& Descriptor)
{
    return;
}

void BasicEntity::sendMessage(std::string& Msg, Entity& Sender)
{
    return;
}

void BasicEntity::giveItem(std::unique_ptr<Item> Item)
{
    //XXX - Make it so the item drops in the world instead of deleting.
    delete Item.release();
    return;
}

