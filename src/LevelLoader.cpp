#include "easylogging++.h"
#include "GameObjectFactory.hpp"
#include "LevelLoader.hpp"

Level LevelLoader::load(const std::string p_id)
{
	Level l_level;

	if (p_id.empty())
	{
		LOG(ERROR) << "Level id must be passed to load game objects!";
		return l_level;
	}
	
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