#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H
#include "Player.hpp"
#include <memory>

class GameObjectFactory
{
public:
    GameObjectFactory() {}
    std::unique_ptr<Player> createPlayer();

};





#endif
