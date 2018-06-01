/*
 * LocalItemFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_LOCALITEMFACTORY_H_
#define SRC_LOCALITEMFACTORY_H_

#include "ItemFactory.h"

template<typename T>
class LocalItemFactory: public ItemFactory {

	std::string getFactoryName() const override;

	std::unique_ptr<Item> createNewItem() override ;

	std::unique_ptr<Item> loadItem(std::string serialization) override;

	virtual ~LocalItemFactory() {};
};

template<typename T>
std::string LocalItemFactory<T>::getFactoryName() const {
	return typeid(T).name();
}

template<typename T>
std::unique_ptr<Item> LocalItemFactory<T>::createNewItem() {
	return std::unique_ptr<T>(new T);
}

template<typename T>
std::unique_ptr<Item> LocalItemFactory<T>::loadItem(std::string serialization) {
	return std::unique_ptr<T>(new T(serialization));
}

#endif /* SRC_LOCALITEMFACTORY_H_ */
