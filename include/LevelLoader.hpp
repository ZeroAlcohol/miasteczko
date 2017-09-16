#pragma once

#include "Level.hpp"
#include "ITextureProvider.hpp"

class LevelLoader
{
public:
	LevelLoader(const Spirit::ITextureProvider & );
	Level load(const std::string p_id);

private:
	const Spirit::ITextureProvider & m_textureProvider;
	std::list<std::unique_ptr<ILevelObject>> loadPassiveObjects() const;
	std::list<std::unique_ptr<ILevelObject>> loadActiveObjects() const;
	bool validateObjectsCollection(std::list<std::unique_ptr<ILevelObject>> & p_objectsList) const;
	std::pair <std::unique_ptr<sf::RenderTexture>, sf::Sprite> loadBackround(unsigned p_width, unsigned p_height, unsigned p_tileSize);

	std::map<unsigned, sf::Sprite > m_tilesMapper;
	const unsigned m_tileSize;

};