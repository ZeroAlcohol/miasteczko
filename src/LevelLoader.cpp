#include "easylogging++.h"
#include "TextureContainer.hpp"
#include "GameObjectFactory.hpp"
#include "LevelLoader.hpp"
#include "TextFactory.hpp"
#include "FpsCounter.hpp"

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


	l_level.width = m_tileSize * tilesArrayWidth;
	l_level.height = m_tileSize * tilesArrayHeight;
	auto background = loadBackround(l_level.width, l_level.height, m_tileSize);
	l_level.backgroundTexture = std::move(background.first);
	l_level.backgroundSrite = background.second;
	l_level.passiveObjects = loadPassiveObjects();
	l_level.activeObjects = loadActiveObjects();
	l_level.id = p_id;

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

	for (int i = 0; i < tilesArrayHeight; ++i)
	{
		for (int j = 0; j < tilesArrayWidth; ++j)
		{
			sf::Sprite & l_tile = m_tilesMapper[tilesMap[i][j]];
			l_tile.setPosition(j*p_tileSize, i*p_tileSize);
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

	l_loadedObjects.push_back(GameObjectFactory().createPassiveTexturedRectangle(50, 50, 0, TextureContainer::getSprite(rs::tx::flowerBox)));
	l_loadedObjects.push_back(GameObjectFactory().createPassiveTexturedRectangle(50, 400, 0, TextureContainer::getSprite(rs::tx::flowerBox)));
	l_loadedObjects.push_back(GameObjectFactory().createPassiveTexturedRectangle(50, 170, 0, TextureContainer::getSprite(rs::tx::bench)));

	//temp
	l_loadedObjects.push_back(std::make_unique<TextFactory>(std::to_string(33390), 200, "../data/xxx.ttf"));

	validateObjectsCollection(l_loadedObjects);

	return l_loadedObjects;
}

std::list<std::unique_ptr<IObject>> LevelLoader::loadActiveObjects() const 
{
	std::list<std::unique_ptr<IObject>> l_loadedObjects;

	l_loadedObjects.push_back(GameObjectFactory().createPlayer(TextureContainer::getSprite(rs::tx::player)));

	validateObjectsCollection(l_loadedObjects);

	return l_loadedObjects;
}
