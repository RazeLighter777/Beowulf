/*
 * Room.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_
#include <rapidjson/document.h>
#include "typedefs.h"
struct WorldInterface;

struct Room {

	//Returns the world the item is in.
	virtual WorldInterface& getWorld() const = 0;

	//Returns the character displayed by the entity upon the screen.
	virtual sf::Sprite& render() = 0;

	//Returns the name of the entity. (not the name of the type of the entity, but rather the entities own personal name)
	virtual std::string getName() = 0;

	//Returns 1 if the room is solid
	virtual bool isSolid() = 0;

	//Returns the name of the type of the entity. (Refers to a species)
	virtual std::string getTypeName() = 0;

	//Returns the name of the factory of the entity. (IE the factory used to construct it) !!!! Should be equal to typeid(T).name() !!!!
	virtual std::string getFactoryName() = 0;

	virtual ~Room() {};

};



#endif /* SRC_ROOM_H_ */
