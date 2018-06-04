/*
 * LocalEntityFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_LOCALENTITYFACTORY_H_
#define SRC_LOCALENTITYFACTORY_H_

//XXX - Should not include iostream
#include <typeinfo>
#include <iostream>
#include "EntityFactory.h"

template<typename T>
class LocalEntityFactory: public EntityFactory {

	std::string getFactoryName() const override;

	std::shared_ptr<Entity> createNewEntity(Position pos,  WorldInterface& winterface) override ;

	std::shared_ptr<Entity> loadEntity(std::string serialization, WorldInterface& winterface) override;

};

template<typename T>
std::string LocalEntityFactory<T>::getFactoryName() const {
	return typeid(T).name();
}

template<typename T>
std::shared_ptr<Entity> LocalEntityFactory<T>::createNewEntity(Position pos,  WorldInterface& winterface) {

	return std::shared_ptr<T>(new T(pos, winterface));

}

template<typename T>
std::shared_ptr<Entity> LocalEntityFactory<T>::loadEntity(std::string serialization, WorldInterface& winterface) {
	std::shared_ptr<T> x = std::shared_ptr<T>(new T(serialization, winterface));

	return x;
}

#endif /* SRC_LOCALENTITYFACTORY_H_ */
