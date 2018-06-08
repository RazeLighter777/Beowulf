#include "Player.h"

std::string Player::getFactoryName() const
{
    return typeid(Player).name();
}

std::string Player::getName()
{
    return playerName;
}

std::string Player::getTypeName()
{
    return "Player:Friendly";
}

void Player::update()
{
    return;
}

std::string Player::serialize()
{
    return BasicEntity::serialize() + playerName + ":";
}

void Player::damage(AttackDescriptor& Descriptor)
{
    return;
}

void Player::sendMessage(std::string& Msg, Entity& Sender)
{
    return;
}

void Player::giveItem(std::unique_ptr<Item> Item)
{
    delete Item.release();
}

Player::Player(std::string serialization, WorldInterface& worldInterface_) :
BasicEntity(serialization, worldInterface_)
{
    playerName = getNextProperty(serialization);
}

Player::Player(Position position_, WorldInterface& worldInterface_) :
BasicEntity(position_, worldInterface_)
{

}

void Player::drawMap(sf::RenderWindow& win)
{
    std::vector<std::shared_ptr<Entity>> entitiesOnTiles = worldInterface.getEntitiesInRadius(position, 32);
    for (unsigned i = 0; i < 16; i++)
    {
        unsigned actualY = position.second - 8 + i;
        for (unsigned j = 0; j < 24; j++)
        {
            unsigned actualX = position.first - 12 + j;

            unsigned drawingX = actualX * 32;
            unsigned drawingY = actualY * 32;

            worldInterface.getRoomAt(Position(actualX, actualY)).render().setPosition(sf::Vector2f(drawingX, drawingY));
            win.draw(worldInterface.getRoomAt(Position(actualX, actualY)).render());

            for (unsigned k = 0; k < entitiesOnTiles.size(); k++)
            {
                if (Position(actualX, actualY) == entitiesOnTiles[k]->getPosition())
                {
                    for (unsigned h = 0; h < entitiesOnTiles[k]->render().size(); h++)
                    {
                        entitiesOnTiles[k]->render()[h]->setPosition(sf::Vector2f(drawingX, drawingY));
                        win.draw(*entitiesOnTiles[k]->render()[h]);
                    }
                }
            }
        }
    }                    
}