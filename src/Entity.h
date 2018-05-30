#ifndef ENTITY
#define ENTITY

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <utility>
#include "typedefs.h"
//Class prototypes
struct WorldInterface;
struct AttackDescriptor;
struct Item;

//Implementation of the abstract entity interface.
struct Entity {


	//Returns the position of the entity on the gameboard
	virtual Position getPosition() = 0;

	//Renders the entity onto the screen 
	virtual sf::Sprite& render() = 0;

	//Returns the name of the entity. (not the name of the type of the entity, but rather the entities own personal name)
	virtual std::string getName() = 0;

	//Returns the name of the type of the entity. (Refers to a species)
	virtual std::string getTypeName() = 0;

	//Returns 1 if the entity is dead (IE should be removed)
	virtual bool isDead() = 0;
	
	//Updates the properties of the entity for 1 ingame tick.
	virtual void update() = 0;

	//serializes the entity into a string.
	virtual std::string serialize() = 0;

	//Returns the WorldInterface of the Entity;
	virtual WorldInterface& getWorld() const = 0;

	//Does damage or applies an effect using an attack descriptor
	virtual void damage(AttackDescriptor& Descriptor) = 0;

	//Sends a string to the entity.
	virtual void sendMessage(std::string& Msg, Entity& Sender) = 0;
	
	//Transfers ownership of an item to the entity.
	virtual void giveItem(std::unique_ptr<Item> Item)  = 0;
	
	//Virtual destructor for the entity
	virtual ~Entity() {};

	
};
#endif
