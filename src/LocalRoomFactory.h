/*
 * LocalRoomFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_LOCALROOMFACTORY_H_
#define SRC_LOCALROOMFACTORY_H_

#include <iostream>
#include <typeinfo>
#include "RoomFactory.h"

template<typename T>
class LocalRoomFactory: public RoomFactory {

	std::string getFactoryName() const override;

	Room* createNewRoom(std::string serialization, WorldInterface& winterface) override;

};

template<typename T>
Room* LocalRoomFactory<T>::createNewRoom(std::string serialization, WorldInterface& winterface) {
	return new T(serialization, winterface);
}

template<typename T>
std::string LocalRoomFactory<T>::getFactoryName() const {
	return typeid(T).name();
}

#endif /* SRC_LOCALROOMFACTORY_H_ */
