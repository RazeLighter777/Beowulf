#include "World.h"

World::World(Game& game_, 
		std::string filename_,
		std::vector<EntityFactory*> entityFactories_,
		std::vector<ItemFactory*> itemFactories_,
		std::vector<EffectFactory*> effectFactories_,
		std::vector<RoomFactory*> roomFactories_,
		WorldGenerator& wgen
		) :
worldGame(game_),
filename(filename_),
entityFactories(entityFactories_),
itemFactories(itemFactories_),
effectFactories(effectFactories_),
roomFactories(roomFactories_),
worldGenerator(wgen)
{
	//Begin by opening the file for reading.
	std::ifstream in(filename);
	//If it does not work, close it.
	if (!in.good()) {
		std::cerr << "There was an issue opening the world at " << filename << " for reading.\n";
		return;
	}
	//Construct all of the rooms from the files.
	while (true) {
		std::string input = "";
		unsigned x,y;
		in >> input;
		//Keep reading until you encounter a break.
		if (input == "BREAK")
		{
			break;
		}
		//Read the serialization of the room
		std::string serialiazation;
		in >> serialiazation;

		//read the coordinates of the room.
		in >> x >> y;
		for (int i = 0; i < roomFactories.size(); i++)
		{
			if (roomFactories[i]->getFactoryName() == input)
			{
				Room* rm = roomFactories[i]->createNewRoom(serialiazation, *this);
				rooms.insert(std::make_pair(Position(x,y), rm));
				break;

			}
		}
	}
	//Load and construct all of the entities from files.
	while (true) {
		std::string input;
		std::string serializationData;
		in >> input;
		//Keep reading until you encounter a break.
		if (input == "BREAK") {
			break;
		}
		in >> serializationData;
		for (EntityFactory* i : entityFactories) {
			if (i->getFactoryName() == input) {
				entities.push_back(i->loadEntity(serializationData, *this));
				//Comment this in to check if the object was constructed correctly.
			}
		} 
	}
	in.close();
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

void World::createEntity(std::string serializationData, std::string name) 
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
	//Return the first item in the list, to prevent errors.
	return itemFactories[0]->createNewItem();
}

std::unique_ptr<Item> World::createItem(std::string serializationData, std::string name) 
{
	for (ItemFactory* i : itemFactories) {
		if (i->getFactoryName() == name) {
			return i->loadItem(serializationData);
		}
	}
	std::cerr << "Item type " << name << " does not exist.\n";
	//Return the first item in the list, to prevent errors.
	return itemFactories[0]->createNewItem();
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
	if ( rooms.find(pos) == rooms.end()) 
	{
		rooms[pos] = worldGenerator.generateRoomAt(pos);
		return *(rooms[pos]);
	} 
	else 
	{
		return *(rooms[pos]);
	}
}

bool World::isValidMove(Position pos)
{
	return !getRoomAt(pos).isSolid();
}


//TODO: Make this function wrap around corners of the map.
std::vector<std::shared_ptr<Entity>> World::getEntitiesInRadius(Position pos, unsigned radius)
{
	std::vector<std::shared_ptr<Entity>> targets;
	for (unsigned i = 0; i < entities.size(); i++) {
		Position entpos = entities[i]->getPosition();
		//Check if the entity is within the radius
		if ((entpos.first > (pos.first - radius)) &&
				(entpos.first < (pos.first + radius)) &&
				(entpos.second > (pos.second - radius)) &&
				(entpos.second < (pos.second + radius))) {
				targets.push_back(entities[i]);
		}
	}
	return targets;
}

void World::saveWorld() 
{
	//Open the output file.
	std::ofstream out(filename);
	//Loop through each of the rooms
	for ( auto it = rooms.begin(); it != rooms.end(); it++ )
	{
    	out << it->second->getFactoryName() << it->first.first  << "\n" << it->first.second <<  it->second->serialize() << "\n"; 
	}
  	//Add a break to end the section.
  	out << "BREAK\n";
  	//Write each of the entities and thier serialiazation to the file.
  	for (unsigned i = 0; i < entities.size(); i++) 
  	{
  		out << entities[i]->getFactoryName() << "\n" << entities[i]->serialize() << "\n";
  	}
  	//Output a break to end the section.
  	out << "BREAK\n";
} 

void World::update()
{
	for (unsigned i = 0; i < entities.size(); i++) 
  	{
  		entities[i]->update();
  		if (entities[i]->isDead()) 
  		{
  			entities.erase(std::remove(entities.begin(), entities.end(), entities[i]), entities.end());
  		}
  	}
  	//Increment the time counter.
  	time++;
}