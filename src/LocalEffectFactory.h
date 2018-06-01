/*
 * LocalEffectFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_LOCALEFFECTFACTORY_H_
#define SRC_LOCALEFFECTFACTORY_H_

#include "EffectFactory.h"

template<typename T>
class LocalEffectFactory: public EffectFactory {

	std::string getFactoryName() const override;

	std::shared_ptr<Effect> createEffect(unsigned str, unsigned duration) override;

};

template<typename T>
std::shared_ptr<Effect> LocalEffectFactory<T>::createEffect(unsigned int str, unsigned int duration) {
	return  std::make_shared<Effect>(new T(str, duration));
}

template<typename T>
std::string LocalEffectFactory<T>::getFactoryName() const {
	return typeid(T).name();
}
#endif /* SRC_LOCALEFFECTFACTORY_H_ */
