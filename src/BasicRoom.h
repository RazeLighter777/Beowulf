#ifndef BASICROOM
#define BASICROOM

#include "World.h"
#include "Room.h"
#include "Serialization.h"

struct WorldInterface;

class BasicRoom : public Room {
public:

    BasicRoom(std::string serial, WorldInterface& worldInterface_);

	//Returns the world the item is in.
	virtual WorldInterface& getWorld() const;

	//Returns the character displayed by the entity upon the screen.
	virtual sf::Sprite& render();

	//Returns the name of the entity. (not the name of the type of the entity, but rather the entities own personal name)
	virtual std::string getName();

	//Returns 1 if the room is solid
	virtual bool isSolid();

	//Serializes the room data, if it has any.
	virtual std::string serialize();

	//Returns the name of the type of the entity. (Refers to a species, not a factory.)
	virtual std::string getTypeName();

	//Returns the name of the factory of the entity. (IE the factory used to construct it) !!!! Should be equal to typeid(T).name() !!!!
	virtual std::string getFactoryName();

	virtual ~BasicRoom() {};

private:

    WorldInterface& worldInterface;

    sf::Sprite sprite;

    std::string texturename;

};

#endif