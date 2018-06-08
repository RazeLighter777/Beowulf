#ifndef PLAYER
#define PLAYER

#include "WorldInterface.h"
#include "Serialization.h"
#include "Room.h"
#include "BasicEntity.h"

class Player : public BasicEntity {
public:

    //Dynamic constructor, allows for player creation interface.
	Player(Position position_, WorldInterface& worldInterface_);

    Player(std::string serialization, WorldInterface& worldInterface_);

    virtual std::string getFactoryName() const override;

    virtual std::string getName();

    virtual std::string getTypeName();

    virtual void update();

    virtual std::string serialize();

    virtual void damage(AttackDescriptor& Descriptor);

	virtual void sendMessage(std::string& Msg, Entity& Sender);

    virtual void giveItem(std::unique_ptr<Item> Item);

    virtual ~Player() {};

private:

    void drawMap(sf::RenderWindow& win);

    std::string playerName;

};

#endif