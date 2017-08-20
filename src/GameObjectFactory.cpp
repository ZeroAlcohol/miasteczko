#include "GameObjectFactory.hpp"



std::unique_ptr<Player> GameObjectFactory::createPlayer(sf::Sprite p_sprite)
{
    std::unique_ptr<Player> l_player = std::make_unique<Player>("Robert", p_sprite);
    return std::move(l_player);
}

std::unique_ptr<PassiveRenderRectangle> GameObjectFactory::createPassiveRenderRectangle(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color)
{
    std::unique_ptr<PassiveRenderRectangle> l_object = std::make_unique<PassiveRenderRectangle>(p_x, p_y, p_w, p_h, p_rotation, p_color);
    return std::move(l_object);

}

std::unique_ptr<PassiveTexturedRectangle> GameObjectFactory::createPassiveTexturedRectangle(float p_x, float p_y, float p_rotation, sf::Sprite p_sprite)
{
	std::unique_ptr<PassiveTexturedRectangle> l_object = std::make_unique<PassiveTexturedRectangle>(p_x, p_y, p_rotation, p_sprite);
	return std::move(l_object);
}
