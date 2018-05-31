/*
 * WorldInterface.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_WORLDINTERFACE_H_
#define SRC_WORLDINTERFACE_H_
#include <memory>
#include <vector>
#include "typedefs.h"
struct Room;
struct Item;
struct Entity;
struct WorldInterface {

	//Returns a reference to the room at the given position.
	virtual Room& getRoomAt(Position pos) = 0;

	//Returns all entities within the desired radius.
	virtual std::vector<std::shared_ptr<Entity>> getEntitiesInRadius(Position pos, unsigned radius) = 0;

	//Returns all entities on the tile
	virtual std::vector<std::shared_ptr<Entity>> getEntitiesOnTile(Position pos) = 0;

	//Returns 1 if the position is valid (not blocked with a wall)
	virtual bool isValidMove(Position pos) = 0;

	//Creates an entity at the given position.
	virtual void createEntity(Position pos, std::string name) = 0;

	//Creates an entity at the given position and constructs it with the string.
	virtual void createEntity(std::string serializationData, std::string name) = 0;

	//Returns 1 if the entity exists in the factory database (IE can be constructed). Returns 0 otherwise.
	virtual bool entityTypeExists(std::string name) = 0;

	//Returns the number of ticks since the game started.
	virtual unsigned long getTime() = 0;

	//Constructs an item with the given name and returns a unique pointer to it.
	virtual std::unique_ptr<Item> createItem(std::string name) = 0;

	//Constructs an item with the given name using the json string and returns a unique pointer to it.
	virtual std::unique_ptr<Item> createItem(std::string serializationData, std::string name) = 0;

	//Returns 1 if the item exists in the factory database (IE can be constructed). Returns 0 otherwise.
	virtual bool itemTypeExists(std::string name) = 0;

	//Saves the game world.
	virtual void saveWorld() = 0;

	//Updates the world and passes a tick.
	virtual void update() = 0;

	virtual void dropItem(std::unique_ptr<Item> item, Position pos) = 0;

	virtual ~WorldInterface() {
	};

	virtual sf::Texture& getTexture(std::string textureName) = 0;



};



#endif /* SRC_WORLDINTERFACE_H_ */
