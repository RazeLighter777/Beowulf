#ifndef WORLD
#define WORLD
#include <map>
#include <memory>
#include <utility>
#include <iostream>
#include <fstream>
#include "EntityFactory.h"
#include "RoomFactory.h"
#include "ItemFactory.h"
#include "EffectFactory.h"
#include "WorldInterface.h"
#include "Room.h"
#include "Item.h"
#include "WorldGenerator.h"
#include "Entity.h"
#include "game.h"

class Game;

class World : public WorldInterface {
public:

	//Constructs the world object.
	World(Game& game_, 
		std::string filename_,
		std::vector<EntityFactory*> entityFactories_,
		std::vector<ItemFactory*> itemFactories_,
		std::vector<EffectFactory*> effectFactories_,
		std::vector<RoomFactory*> roomFactories_,
		WorldGenerator& wgen
		);

	//Requests a texture from the game engine. Will always return something, even if the texture is missing. 
	sf::Texture& getTexture(std::string textureName);

	//Requests a sound from the game engine. Will always return something, even if the sound is missing.
	sf::SoundBuffer& getSound(std::string soundName);

	//Returns the time since the game session started
	unsigned long getTime();

	//Creates an item and returns a pointer to it.
	std::unique_ptr<Item> createItem(std::string name);

	//Same as above, but creates it from serialization data.
	std::unique_ptr<Item> createItem(std::string serializationData, std::string name);

	bool entityTypeExists(std::string name);

	void createEntity(std::string serializationData, std::string name);

	void createEntity(Position pos, std::string name);

	bool itemTypeExists(std::string name);

	std::vector<std::shared_ptr<Entity>> getEntitiesOnTile(Position pos);

	std::vector<std::shared_ptr<Entity>> getEntitiesInRadius(Position pos, unsigned radius);

	bool isValidMove(Position pos);

	Room& getRoomAt(Position pos);

	//Saves to world to the serialization file in  a retrievable format.
	void saveWorld();

	//Updates the world.
	void update();

	std::shared_ptr<Room> createRoom(std::string type, std::string serializationData);

	sf::RenderWindow& exposeWindow();

//Data members for the world
private:

	//The game object, where we get all of the textures from.
	Game& worldGame;

	//The file upon which we do IO.
	std::string filename;

	//The world generator for this world
	WorldGenerator& worldGenerator;

	//The time that has passed since the game has begun.
	unsigned long time = 0;

	//Holds the vector of entities.
	std::vector<std::shared_ptr<Entity>> entities;

	//holds the list of rooms, in a map like structure, allowing for expansion.
	std::map<std::pair<unsigned, unsigned>, std::shared_ptr<Room>> rooms;

//Factories for the world to construct its objects.
private:

	std::vector<EntityFactory*> entityFactories;

	std::vector<RoomFactory*> roomFactories;

	std::vector<ItemFactory*> itemFactories;

	std::vector<EffectFactory*> effectFactories;

};

#endif