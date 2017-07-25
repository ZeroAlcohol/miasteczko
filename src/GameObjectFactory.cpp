#include "GameObjectFactory.hpp"



std::unique_ptr<Player> GameObjectFactory::createPlayer()
{
    std::unique_ptr<Player> l_player(new Player("Robert"));
    return std::move(l_player);
}

FpsCounter GameObjectFactory::createFpsCounter()
{
    return FpsCounter();
}
