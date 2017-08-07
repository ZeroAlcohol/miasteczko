#include "GameObjectFactory.hpp"



std::unique_ptr<Player> GameObjectFactory::createPlayer()
{
    std::unique_ptr<Player> l_player(new Player("Robert"));
    return std::move(l_player);
}

std::unique_ptr<PassiveGameObjectMock> GameObjectFactory::createPassiveObjectMock(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color)
{
	std::unique_ptr<PassiveGameObjectMock> l_object(new PassiveGameObjectMock(p_x, p_y, p_w, p_h, p_rotation, p_color));
	return std::move(l_object);
}
