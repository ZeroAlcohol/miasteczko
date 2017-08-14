#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
    Animation(){}

    void addFrame(sf::IntRect rect);
    void setTexture(const sf::Texture& texture);
    const sf::Texture* getTexture() const;
    std::size_t getSize() const;
    const sf::IntRect &getFrame(std::size_t n) const;

private:
    std::vector<sf::IntRect> m_frames;
    const sf::Texture* m_texture;
};
