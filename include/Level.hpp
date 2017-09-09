#pragma once

#include <memory>
#include <list>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTexture.hpp"

#include "config.hpp"
#include "IObject.hpp"

class Level
{
public:
	using Dimension = std::pair<unsigned, unsigned>;
	using Objects = std::list<std::unique_ptr<IObject>>;

	Dimension getDimension();
	void setDimension(Dimension p_dimension);
	std::string getId();
	void setId(std::string p_id);

	Objects& getActiveObjects();
	void setActiveObjects(Objects p_objects);

	Objects& getPassiveObjects();
	void setPassiveObjects(Objects p_objects);

	sf::Sprite& getBackgroundSprite();
	void setBackgroundSprite(sf::Sprite p_sprite);

	void setBackgroundTexture(std::unique_ptr<sf::RenderTexture> p_texture);

	sf::View getLevelView();

private:

	Objects m_activeObjects; //objects which are performing actions during run()
	Objects m_passiveObjects; //objects which aren't performing actions during run()
	std::unique_ptr<sf::RenderTexture> m_backgroundTexture;
	sf::Sprite m_backgroundSrite;
	std::string m_id;
	Dimension m_dimension;
};
