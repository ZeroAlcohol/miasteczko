#include "Level.hpp"
#include "Player.hpp"

sf::View Level::getLevelView()
{
    auto const l_player = dynamic_cast<Player*> (m_activeObjects.front().get());

    if (l_player == nullptr)
    {
        return sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    }

    auto l_coords = l_player->getCenterCoordinates();

    float l_rectLeft {std::max(0.0f, std::min(l_coords.first - WINDOW_WIDTH * 0.5f, static_cast<float>(m_dimension.first - WINDOW_WIDTH)))};
    float l_rectTop {std::max(0.0f, std::min(l_coords.second - WINDOW_HEIGHT * 0.5f, static_cast<float>(m_dimension.second - WINDOW_HEIGHT)))};

    return sf::View(sf::FloatRect(l_rectLeft, l_rectTop, WINDOW_WIDTH, WINDOW_HEIGHT));
}

Level::Dimension Level::getDimension()
{
    return m_dimension;
}

void Level::setDimension(Level::Dimension p_dimension)
{
    m_dimension.first = p_dimension.first;
    m_dimension.second = p_dimension.second;
}

std::string Level::getId()
{
    return m_id;
}
void Level::setId(std::string p_id)
{
    m_id = p_id;
}

Level::Objects& Level::getActiveObjects()
{
    return m_activeObjects;
}

void Level::setActiveObjects(Objects p_objects)
{
    m_activeObjects = std::move(p_objects);
}

Level::Objects& Level::getPassiveObjects()
{
    return m_passiveObjects;
}
void Level::setPassiveObjects(Objects p_objects)
{
    m_passiveObjects = std::move(p_objects);
}

sf::Sprite& Level::getBackgroundSprite()
{
    return m_backgroundSrite;
}

void Level::setBackgroundSprite(sf::Sprite p_sprite)
{
    m_backgroundSrite = p_sprite;
}

void Level::setBackgroundTexture(std::unique_ptr<sf::RenderTexture> p_texture)
{
    m_backgroundTexture = std::move(p_texture);
}