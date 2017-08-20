#pragma once

#include "level.hpp"

class LevelLoader
{
public:
	LevelLoader();
	Level load(const std::string p_id);

private:
	std::map<unsigned, sf::Sprite > m_tilesMapper;

};