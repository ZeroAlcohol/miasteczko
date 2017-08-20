#include "easylogging++.h"
#include "TextureContainer.hpp"
#include "GameObjectFactory.hpp"
#include "LevelLoader.hpp"

constexpr unsigned tilesArrayHeight{ 32 };
constexpr unsigned tilesArrayWidth{ 32 };

const unsigned tilesMap[tilesArrayHeight][tilesArrayWidth]{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
	{ 0, 0, 0, 2, 9, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 9, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 2, 3, 4, 4, 4, 4, 4, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

LevelLoader::LevelLoader() : 
	m_tilesMapper
	{
		std::make_pair(0, TextureContainer::getSprite(rs::tx::tile::grass)),
		std::make_pair(2, TextureContainer::getSprite(rs::tx::tile::pavementLeft)),
		std::make_pair(3, TextureContainer::getSprite(rs::tx::tile::pavementRight)),
		std::make_pair(4, TextureContainer::getSprite(rs::tx::tile::asphalt)),
		std::make_pair(5, TextureContainer::getSprite(rs::tx::tile::pavementTopLeft)),
		std::make_pair(6, TextureContainer::getSprite(rs::tx::tile::pavementTop)),
		std::make_pair(7, TextureContainer::getSprite(rs::tx::tile::pavementBottom)),
		std::make_pair(8, TextureContainer::getSprite(rs::tx::tile::pavement)),
		std::make_pair(9, TextureContainer::getSprite(rs::tx::tile::pavementTopLeftIn))
	}
{

}

Level LevelLoader::load(const std::string p_id)
{
	Level l_level;
	
	if (p_id.empty())
	{
		LOG(ERROR) << "Level id must be passed to load game objects!";
		return l_level;
	}

	const int tileSize { m_tilesMapper[0].getTextureRect().width };
	l_level.width = tileSize * tilesArrayWidth;
	l_level.height = tileSize * tilesArrayHeight;

	l_level.backgroundTexture = std::make_unique<sf::RenderTexture>();

	if (!l_level.backgroundTexture || !l_level.backgroundTexture->create(l_level.width, l_level.height))
	{
		LOG(ERROR) << "Unable to create level's background!";
		return l_level;
	}

	for (int i = 0; i < tilesArrayHeight; ++i)
	{
		for (int j = 0; j < tilesArrayWidth; ++j)
		{
			sf::Sprite & l_tile = m_tilesMapper[tilesMap[i][j]];
			l_tile.setPosition(j*tileSize, i*tileSize);
			l_level.backgroundTexture->draw(l_tile);
		}
	}

	l_level.backgroundTexture->display();
	l_level.backgroundSrite.setTexture(l_level.backgroundTexture->getTexture());

	l_level.activeObjects.push_back(GameObjectFactory().createPlayer());
	l_level.passiveObjects.push_back(GameObjectFactory().createPassiveRenderRectangle(200, 100, 100, 100, 50, { 255, 0, 0 }));
	l_level.passiveObjects.push_back(GameObjectFactory().createPassiveRenderRectangle(800, 120, 100, 300, 75, { 0, 255, 0 }));
	l_level.passiveObjects.push_back(GameObjectFactory().createPassiveRenderRectangle(700, 320, 150, 150, 0, { 0, 0, 255 }));

    auto l_activeObjectsIterator = std::find_if(l_level.activeObjects.begin(), l_level.activeObjects.end(), [](const auto& p){return p == nullptr;});
	if(l_level.activeObjects.end() != l_activeObjectsIterator && nullptr == *l_activeObjectsIterator)
	{
		LOG(ERROR) << "One of active objects can't be loaded!";
		return l_level;
	}

    auto l_passiveObjectsIterator = std::find_if(l_level.passiveObjects.begin(), l_level.passiveObjects.end(), [](const auto& p){return p == nullptr;});
   	if(l_level.passiveObjects.end() != l_passiveObjectsIterator && *l_passiveObjectsIterator == nullptr)
	{
		LOG(ERROR) << "One of passive objects can't be loaded!";
		return l_level;
	}
	
	l_level.id = p_id;
	return l_level;
}