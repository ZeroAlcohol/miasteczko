#pragma once

#include <memory>
#include <map>

#include "LevelObjectData.hpp"
#include "IObject.hpp"
#include "ITextureProvider.hpp"


class GameObjectFactory
{
public:
	GameObjectFactory(const Spirit::ITextureProvider &);
	std::unique_ptr<IObject> createLevelObject(const LevelObjectData& p_data);

private:
	const Spirit::ITextureProvider & m_textureProvider;
	std::unique_ptr<IObject> createPlayer(const LevelObjectData& p_data);
	std::unique_ptr<IObject> createPassiveTexturedRectangle(const LevelObjectData& p_data);

    typedef std::unique_ptr<IObject>(GameObjectFactory::*ObjectCreateMethod_t)(const LevelObjectData& p_data);

    std::map<std::string, ObjectCreateMethod_t> m_levelObjectMapper;
};
