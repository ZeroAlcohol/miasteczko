#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H
#include <memory>
#include "Player.hpp"
#include "PassiveTexturedRectangle.hpp"

class GameObjectFactory
{
public:
    GameObjectFactory() {}
    std::unique_ptr<Player> createPlayer(sf::Sprite p_sprite);
	std::unique_ptr<PassiveTexturedRectangle> createPassiveTexturedRectangle(float p_x, float p_y, float p_rotation, sf::Sprite p_sprite);
};





#endif
