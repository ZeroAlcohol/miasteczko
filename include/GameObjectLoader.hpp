#ifndef GAME_OBJECT_LOADER_H
#define GAME_OBJECT_LOADER_H
#include "Player.hpp"
#include <memory>

class GameObjectLoader
{
public:
    GameObjectLoader() {}
    std::unique_ptr<Player> createPlayer();

};





#endif
