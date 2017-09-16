#include "config.hpp"
#include "TextureContainer.hpp"
#include "easylogging++.h"

namespace Spirit
{
	sf::Texture TextureContainer::defaultTexture;

	const sf::Texture &TextureContainer::getTexture(const std::string p_name) const
	{
		try
		{
			return m_textureMap.at(p_name);
		}
		catch (const std::out_of_range & oor) {
			LOG(ERROR) << oor.what() << " (key: " << p_name << ")";
			return TextureContainer::defaultTexture;
		}
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
			m_textureMap.emplace(std::make_pair(p_name, l_texture));
		}
		else
		{
			LOG(ERROR) << "Failed to load resource, name: " << p_name << ", adress: " << p_addressImage;
		}
	}

	TextureContainer::TextureContainer(std::initializer_list<const std::string> p_keys, const std::string p_path, const std::string p_format)
	{
		putTexturesByKey(p_keys, p_path, p_format);
	}
}
