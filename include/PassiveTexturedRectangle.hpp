#pragma once

#include <memory>
#include "IObject.hpp"


class PassiveTexturedRectangle : public IObject
{
public:
	PassiveTexturedRectangle(float p_x, float p_y, float p_rotation, sf::Sprite p_sprite);
	~PassiveTexturedRectangle();
	virtual void run() override;
	virtual void render(sf::RenderWindow& p_window) override;

private:
	sf::Sprite m_sprite;
};