/*
 * EntityFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_ENTITYFACTORY_H_
#define SRC_ENTITYFACTORY_H_
#include <string>
#include <memory>
#include "typedefs.h"
struct WorldInterface;
struct Entity;
class EntityFactory {
public:

	virtual std::string getFactoryName() const = 0;

	virtual std::shared_ptr<Entity> createNewEntity(Position pos,  WorldInterface& winterface) = 0;

	virtual std::shared_ptr<Entity> loadEntity(std::string serialstring, WorldInterface& winterface) = 0;

	virtual ~EntityFactory() {};

};



#endif /* SRC_ENTITYFACTORY_H_ */
