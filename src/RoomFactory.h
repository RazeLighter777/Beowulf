/*
 * RoomFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_ROOMFACTORY_H_
#define SRC_ROOMFACTORY_H_
#include <vector>
#include <string>
struct Room;
struct WorldInterface;
class RoomFactory {
public:

	virtual std::string getFactoryName() const = 0;

	virtual Room* createNewRoom(WorldInterface& winterface) = 0;

	virtual ~RoomFactory() {};

};

#endif /* SRC_ROOMFACTORY_H_ */
