/*
 * EffectFactory.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_EFFECTFACTORY_H_
#define SRC_EFFECTFACTORY_H_
#include <string>
#include <rapidjson/document.h>
#include <memory>
#include "typedefs.h"
struct Effect;
class EffectFactory {
public:

	virtual std::string getFactoryName() const = 0;

	virtual std::shared_ptr<Effect> createEffect(unsigned str, unsigned duration) = 0;

	virtual ~EffectFactory() {};

};



#endif /* SRC_EFFECTFACTORY_H_ */
