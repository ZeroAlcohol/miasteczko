#pragma once

#include <memory>
#include "IObject.hpp"


class PassiveRenderRectangle: public IObject
{
public:
    PassiveRenderRectangle(float p_x, float p_y, float p_w, float p_h, float p_rotation, sf::Color p_color);
    ~PassiveRenderRectangle();
    virtual void run() override;
    virtual void render(sf::RenderWindow& p_window) override;

private:
    sf::Sprite m_sprite;
    std::unique_ptr<sf::RenderTexture> l_renderTexture;

};
