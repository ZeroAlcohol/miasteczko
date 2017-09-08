#include <array>
#include "easylogging++.h"
#include "TextureContainer.hpp"
#include "GameObjectFactory.hpp"
#include "LevelLoader.hpp"
#include "TextFactory.hpp"
#include "FpsCounter.hpp"

constexpr unsigned g_tilesArrayHeight{ 32 };
constexpr unsigned g_tilesArrayWidth{ 32 };

const unsigned g_tilesMap[g_tilesArrayHeight][g_tilesArrayWidth]{
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

const std::array<const LevelObjectData, 3> g_passiveLevelObjectsData
{
	LevelObjectData{ "flowerBox00", "passive-textured-rectangle", "idle", 50.0f, 50.0f, 0.0f },
	LevelObjectData{ "flowerBox01", "passive-textured-rectangle", "idle", 50.0f, 400.0f, 0.0f },
	LevelObjectData{ "bench00", "passive-textured-rectangle", "idle", 50.0f, 170.0f, 0.0f }
};

const std::array<const LevelObjectData, 1> g_activeLevelObjectsData
{
	LevelObjectData{ "player01", "player", "idle", 200.0f, 100.0f, 0.0f}
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
	},
	m_tileSize{ unsigned(m_tilesMapper[0].getTextureRect().width) }
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


	l_level.setDimension(std::make_pair( m_tileSize * g_tilesArrayWidth, m_tileSize * g_tilesArrayHeight));
	auto background = loadBackround(l_level.getDimension().first, l_level.getDimension().second, m_tileSize);
	l_level.setBackgroundTexture(std::move(background.first));
	l_level.setBackgroundSprite(background.second);
	l_level.setPassiveObjects(loadPassiveObjects());
	l_level.setActiveObjects(loadActiveObjects());
	l_level.setId(p_id);

	return l_level;
}

std::pair <std::unique_ptr<sf::RenderTexture>, sf::Sprite> LevelLoader::loadBackround(unsigned p_width, unsigned p_height, unsigned p_tileSize)
{
	std::unique_ptr<sf::RenderTexture> l_backgroundTexture = std::make_unique<sf::RenderTexture>();
	sf::Sprite l_backgroundSrite;

	if (!l_backgroundTexture || !l_backgroundTexture->create(p_width, p_height))
	{
		LOG(ERROR) << "Unable to create level's background!";
		return std::make_pair(nullptr, sf::Sprite());
	}

	for (int i = 0; i < g_tilesArrayHeight; ++i)
	{
		for (int j = 0; j < g_tilesArrayWidth; ++j)
		{
			sf::Sprite & l_tile = m_tilesMapper[g_tilesMap[i][j]];
			l_tile.setPosition(float(j*p_tileSize), float(i*p_tileSize));
			l_backgroundTexture->draw(l_tile);
		}
	}

	l_backgroundTexture->display();
	l_backgroundSrite.setTexture(l_backgroundTexture->getTexture());

	return make_pair(std::move(l_backgroundTexture), l_backgroundSrite);
}

bool LevelLoader::validateObjectsCollection(std::list<std::unique_ptr<IObject>> & p_objectsList) const
{
	auto l_objectsIterator = std::find_if(p_objectsList.begin(), p_objectsList.end(), [](const auto& p) {return p == nullptr; });
	
	if (p_objectsList.end() != l_objectsIterator && *l_objectsIterator == nullptr)
	{
		LOG(ERROR) << "One of passive objects can't be loaded, clear collection!";
		p_objectsList.clear();
		return false;
	}

	return true;
}

std::list<std::unique_ptr<IObject>> LevelLoader::loadPassiveObjects() const 
{
	std::list<std::unique_ptr<IObject>> l_loadedObjects;

	for (auto & objectData : g_passiveLevelObjectsData)
	{
		l_loadedObjects.push_back(GameObjectFactory().createLevelObject(objectData));
	}

	//temp
    l_loadedObjects.push_back(std::make_unique<FpsCounter>());

	validateObjectsCollection(l_loadedObjects);

	return l_loadedObjects;
}

std::list<std::unique_ptr<IObject>> LevelLoader::loadActiveObjects() const 
{
	std::list<std::unique_ptr<IObject>> l_loadedObjects;

	for (auto & objectData : g_activeLevelObjectsData)
	{
		l_loadedObjects.push_back(GameObjectFactory().createLevelObject(objectData));
	}

	validateObjectsCollection(l_loadedObjects);

	return l_loadedObjects;
}
