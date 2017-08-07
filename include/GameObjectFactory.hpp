#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H
#include <memory>
#include "Player.hpp"
#include "passive-game-object-mock.hpp"

class GameObjectFactory
{
public:
    GameObjectFactory() {}
    std::unique_ptr<Player> createPlayer();
	std::unique_ptr<PassiveGameObjectMock> createPassiveObjectMock(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color);
};





#endif
