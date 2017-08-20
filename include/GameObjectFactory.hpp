#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H
#include <memory>
#include "Player.hpp"
#include "PassiveRenderRectangle.hpp"
#include "PassiveTexturedRectangle.hpp"

class GameObjectFactory
{
public:
    GameObjectFactory() {}
    std::unique_ptr<Player> createPlayer();
    std::unique_ptr<PassiveRenderRectangle> createPassiveRenderRectangle(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color);
	std::unique_ptr<PassiveTexturedRectangle> createPassiveTexturedRectangle(float p_x, float p_y, float p_rotation, sf::Sprite p_sprite);
};





#endif
