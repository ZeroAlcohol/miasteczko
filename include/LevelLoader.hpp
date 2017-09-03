#pragma once

#include "level.hpp"

class LevelLoader
{
public:
	LevelLoader();
	Level load(const std::string p_id);

private:
	std::list<std::unique_ptr<IObject>> loadPassiveObjects() const;
	std::list<std::unique_ptr<IObject>> loadActiveObjects() const;
	bool validateObjectsCollection(std::list<std::unique_ptr<IObject>> & p_objectsList) const;
	std::pair <std::unique_ptr<sf::RenderTexture>, sf::Sprite> loadBackround(unsigned p_width, unsigned p_height, unsigned p_tileSize);

	std::map<unsigned, sf::Sprite > m_tilesMapper;
	const unsigned m_tileSize;

};