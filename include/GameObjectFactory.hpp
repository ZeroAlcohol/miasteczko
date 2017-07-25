#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H
#include "Player.hpp"
#include "FpsCounter.hpp"
#include <memory>

class GameObjectFactory
{
public:
    GameObjectFactory() {}
    std::unique_ptr<Player> createPlayer();
    FpsCounter createFpsCounter();

};





#endif
