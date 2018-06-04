#ifndef ITEM
#define ITEM
#include <string>
#include "typedefs.h"
struct Entity;
struct WorldInterface;
struct Item {

	   //Returns the name of the Item  (not the name of the type of the entity, but rather the items own personal name)
		virtual std::string getName() = 0;

		//Returns the sprite of this item
		virtual sf::Sprite& render() = 0;

		//Returns the name of the type of the item.  (Refers to a category)
		virtual std::string getTypeName() = 0;

		//Returns the name of the factory of the item. (IE the factory used to construct it)
		virtual std::string getFactoryName() = 0;

		//Returns the weight of the item.
		virtual Weight getWeight() = 0;

		//Returns the value of the item
		virtual Currency getValue() = 0;

		//Returns the serialization string of the item for serialization purposes.
		virtual std::string serialize()  = 0;

		//Returns 1 if the item is destroyed and should be removed from  the inventory.
		virtual bool isDead() = 0;

		//Uses the item on the given entity. Sender and target may both be nullptr in some case, so check for both. Returns a string describing the action.
		virtual std::string use(Entity* sender, Entity* target) = 0;

		//Fetches a description of the item.
		virtual std::string getDescription() = 0;


		virtual ~Item() {};

};

#endif
