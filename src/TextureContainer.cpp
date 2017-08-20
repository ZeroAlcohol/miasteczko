#include "config.hpp"
#include "TextureContainer.hpp"
#include "easylogging++.h"

void TextureContainer::createResources()
{
	const std::string basePath = TEXTURES_DIR;
	TextureContainer & instance = TextureContainer::getInstance();
}

sf::Texture &TextureContainer::getTexture(std::string p_name)
{
	sf::Texture l_texture;
#ifndef NDEBUG
	try
	{
		l_texture = TextureContainer::getInstance().m_textureMap.at(p_name);
	}
	catch (const std::out_of_range & oor) {
		LOG(ERROR) << oor.what() << " (key: " << p_name << ")";
	}
#else
    l_texture = TextureContainer::getInstance().m_textureMap[p_name];
#endif
	return l_texture;
}

void TextureContainer::putTexturesByKey(std::initializer_list<const std::string> p_keys, const std::string p_path, const std::string p_format)
{
	for (const std::string & p_key : p_keys)
	{
		putTextureByKey(p_key, p_path, p_format);
	}
}

void TextureContainer::putTextureByKey(const std::string p_key, const std::string p_path, const std::string p_format)
{
	const std::string basePath = TEXTURES_DIR;
	putTexture(p_key, basePath + p_path + p_key + "." + p_format);
}

void TextureContainer::putTexture(std::string p_name, std::string p_addressImage)
{
    sf::Texture l_texture;
	if (l_texture.loadFromFile(p_addressImage))
	{
		// TODO check if alredy exists
		TextureContainer::getInstance().m_textureMap.emplace(std::make_pair(p_name, l_texture));
		sf::Sprite l_sprite;
		l_sprite.setTexture(TextureContainer::getInstance().m_textureMap[p_name]);
		TextureContainer::getInstance().m_spriteMap.emplace(std::make_pair(p_name, l_sprite));
	}
	else
	{
		LOG(ERROR) << "Failed to load resource, name: " << p_name << ", adress: " << p_addressImage;
	}
}

sf::Sprite& TextureContainer::getSprite(std::string p_name)
{
	sf::Sprite l_sprite;

#ifndef NDEBUG
	try
	{
		l_sprite = TextureContainer::getInstance().m_spriteMap.at(p_name);
	}
	catch (const std::out_of_range & oor) {
		LOG(ERROR) << oor.what()<< " (key: "<<p_name<<")";
	}
#else
    l_sprite = TextureContainer::getInstance().m_spriteMap[p_name];
#endif // !NDEBUG
	return l_sprite;
}

TextureContainer &TextureContainer::getInstance()
{
    static TextureContainer instance{};
    return instance;
}

TextureContainer::~TextureContainer()
{
}
