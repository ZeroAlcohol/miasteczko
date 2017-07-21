#include "GameObjectLoader.hpp"



std::unique_ptr<Player> GameObjectLoader::createPlayer()
{
    std::unique_ptr<Player> l_player(new Player("Robert"));
    return std::move(l_player);
}
