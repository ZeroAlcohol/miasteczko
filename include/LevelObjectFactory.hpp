#pragma once

#include <memory>
#include <map>

#include "LevelObjectData.hpp"
#include "ILevelObject.hpp"
#include "ITextureProvider.hpp"


class LevelObjectFactory
{
public:
	LevelObjectFactory(const Spirit::ITextureProvider &);
	std::unique_ptr<ILevelObject> createLevelObject(const LevelObjectData& p_data);

private:
	const Spirit::ITextureProvider & m_textureProvider;
	std::unique_ptr<ILevelObject> createPlayer(const LevelObjectData& p_data);
	std::unique_ptr<ILevelObject> createPassiveTexturedRectangle(const LevelObjectData& p_data);

    typedef std::unique_ptr<ILevelObject>(LevelObjectFactory::*ObjectCreateMethod_t)(const LevelObjectData& p_data);

    std::map<std::string, ObjectCreateMethod_t> m_levelObjectMapper;
};
