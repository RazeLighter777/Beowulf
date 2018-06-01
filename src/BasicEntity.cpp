#include "BasicEntity.h"

BasicEntity::BasicEntity(Position position_, WorldInterface& worldInterface_)
: position(position_),
worldInterface(worldInterface_)
{
	
}

BasicEntity::BasicEntity(std::string serialization, WorldInterface& worldInterface_)
: worldInterface(worldInterface_)
{

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

std::string BasicEntity::getName()
{
	return std::string("BasicEntity");
}

std::string BasicEntity::getTypeName()
{
	return std::string("BasicEntity");
}

bool BasicEntity::isDead()
{
	return dead;
}

void BasicEntity::update()
{
	return;
}

std::string BasicEntity::serialize()
{
	return std::string(position.first) + ":" + std::string(position.second);
}

WorldInterface& BasicEntity::getWorld() const
{
	return worldInterface;
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
	return;
}

