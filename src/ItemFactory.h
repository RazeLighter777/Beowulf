/*
 * ItemFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_ITEMFACTORY_H_
#define SRC_ITEMFACTORY_H_
#include <string>
#include <memory>
#include "typedefs.h"
struct WorldInterface;
struct Item;
class ItemFactory {
public:

	virtual std::string getFactoryName() const = 0;

	virtual std::unique_ptr<Item> createNewItem() = 0;

	virtual std::unique_ptr<Item> loadItem(std::string serializationString) = 0;

	virtual ~ItemFactory() {};

};


#endif /* SRC_ITEMFACTORY_H_ */
