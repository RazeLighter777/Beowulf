/*
 * Effect.h
 *
 *  Created on: Apr 3, 2018
 *      Author: justin
 */

#ifndef SRC_EFFECT_H_
#define SRC_EFFECT_H_
#include <string>
struct Entity;
//Refers to the effect interface.

struct Effect {

	//Refers to the name of the effect. Also refers to the name of the factory of the effect.
	virtual std::string getName() = 0;

	//Retrieves the number of ticks the effect has remaining.
	virtual unsigned getTimeRemaining() = 0;

	//Returns the strength level of the effect.
	virtual unsigned getStrength() = 0;

	//Applies the effect to an entity.
	virtual void apply(Entity* target);

	virtual ~Effect() = 0;

};




#endif /* SRC_EFFECT_H_ */
