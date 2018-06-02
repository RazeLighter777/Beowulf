#ifndef ENTITY
#define ENTITY

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <utility>
#include "Entity.h"
#include "typedefs.h"
//Class prototypes
struct WorldInterface;
struct AttackDescriptor;
struct Item;

//Implementation of the abstract entity interface.
struct BasicEntity {

	//Dynamic constructor.
	BasicEntity(Position position_, WorldInterface& worldInterface_);

	BasicEntity(std::string serialization, WorldInterface& worldInterface_);

	//Returns the position of the entity on the gameboard
	virtual Position getPosition();

	virtual std::string getFactoryName() const;

	//Renders the entity onto the screen 
	virtual std::vector<sf::Sprite*> render();

	//Returns the name of the entity. (not the name of the type of the entity, but rather the entities own personal name)
	virtual std::string getName();

	//Returns the name of the type of the entity. (Refers to a species, not )
	virtual std::string getTypeName();

	//Returns 1 if the entity is dead (IE should be removed)
	virtual bool isDead();
	
	//Updates the properties of the entity for 1 ingame tick.
	virtual void update();

	//serializes the entity into a string.
	virtual std::string serialize();

	//Returns the WorldInterface of the Entity;
	virtual WorldInterface& getWorld() const;

	//Does damage or applies an effect using an attack descriptor. Does nothing in this case. 
	virtual void damage(AttackDescriptor& Descriptor);

	//Sends a string to the entity. Does nothing in this case.
	virtual void sendMessage(std::string& Msg, Entity& Sender);
	
	//Transfers ownership of an item to the entity. Does nothing in this case.
	virtual void giveItem(std::unique_ptr<Item> Item);
	
	//Virtual destructor for the entity
	virtual ~BasicEntity() {};

protected:

	Postion position;

	WorldInterface& worldInterface;

	std::vector<sf::Sprite*> spriteLayers;

	bool dead = 0;


};
#endif
