#include "World.h"

World::World(Game& game_, std::string filename_) : worldGame(game_), filename(filename_)
{
	std::clog << "Beginning world construction . . .\n";

}

sf::Texture& World::getTexture(std::string textureName) 
{
	return worldGame.getTexture(textureName);
}

sf::SoundBuffer& World::getSound(std::string soundName)
{
	return worldGame.getSound(soundName);
}

unsigned long World::getTime() {
	return time;
}

void createEntity(std::string serializationData, std::string name) 
{
	for (int i = 0; i < entityFactories.size(); i++) 
	{
		if (entityFactories[i]->getFactoryName() == name) {
			entities.push_back(entityFactories[i]->loadEntity(serializationData, *this));
		}
	}

}
std::unique_ptr<Item> World::createItem(std::string name) 
{
	for (ItemFactory* i : itemFactories) {
		if (i->getFactoryName() == name) {
			return i->createNewItem();
		}
	}
	std::cerr << "Item type " << name << " does not exist.\n";
	exit(1);
}

void World::createEntity(Position pos, std::string name) {
	for (int i = 0; i < entityFactories.size(); i++) 
	{
		if (entityFactories[i]->getFactoryName() == name) {
			entities.push_back(entityFactories[i]->createNewEntity(pos, *this));
		}
	}
}

bool World::entityTypeExists(std::string name)
{
	for (int i = 0; i < entityFactories.size(); i++) 
	{
		if (entityFactories[i]->getFactoryName() == name) {
			return 1;
		}
	}
	return 0;
}

bool World::itemTypeExists(std::string name) 
{
	for (int i = 0; i < itemFactories.size(); i++) 
	{
		if (itemFactories[i]->getFactoryName() == name) {
			return 1;
		}
	}
	return 0;
}

std::vector<std::shared_ptr<Entity>> World::getEntitiesOnTile(Position pos)
{
	std::vector<std::shared_ptr<Entity>> result;
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getPosition() == pos)
		{
			result.push_back(entities[i]);
		}
	}
	return result;
}

Room& World::getRoomAt(Position pos) 
{
	if ( rooms.find(pos) == m.end() ) 
	{
		rooms[pos] = worldGenerator.generateRoomAt(pos);
		return rooms[pos];
	} 
	else 
	{
		return rooms[pos];
	}
}

bool World::isValidMove(Position pos)
{
	return getRoomAt(pos).isSolid();
}