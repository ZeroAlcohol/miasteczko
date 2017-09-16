#pragma once

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "ILevelObject.hpp"

class PassiveTexturedRectangle : public ILevelObject
{
public:
	PassiveTexturedRectangle(float p_x, float p_y, float p_rotation, sf::Sprite p_sprite);
	~PassiveTexturedRectangle();
	virtual void update() override;
	virtual void render(sf::RenderWindow& p_window) override;

private:
	sf::Sprite m_sprite;
};
