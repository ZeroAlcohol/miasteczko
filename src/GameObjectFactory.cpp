#include "GameObjectFactory.hpp"



std::unique_ptr<Player> GameObjectFactory::createPlayer(sf::Sprite p_sprite)
{
    std::unique_ptr<Player> l_player = std::make_unique<Player>("Robert", p_sprite);
    return std::move(l_player);
}

std::unique_ptr<PassiveTexturedRectangle> GameObjectFactory::createPassiveTexturedRectangle(float p_x, float p_y, float p_rotation, sf::Sprite p_sprite)
{
	std::unique_ptr<PassiveTexturedRectangle> l_object = std::make_unique<PassiveTexturedRectangle>(p_x, p_y, p_rotation, p_sprite);
	return std::move(l_object);
}
