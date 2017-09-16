#pragma once

#include <map>
#include "ITextureProvider.hpp"

namespace Spirit
{
	class TextureContainer : public ITextureProvider
	{
	public:
		virtual const sf::Texture& getTexture(const std::string p_name) const override;
    
		void putTexture(std::string p_name, std::string p_adresImage);
		void putTextureByKey(const std::string p_key, const std::string p_path = "", const std::string p_format = "png");
		void putTexturesByKey(std::initializer_list<const std::string> p_keys, const std::string p_path = "", const std::string p_format = "png");
		TextureContainer() {}
		TextureContainer(std::initializer_list<const std::string> p_keys, const std::string p_path = "", const std::string p_format = "png");

	private:
		std::map<std::string, sf::Texture> m_textureMap;
		static sf::Texture defaultTexture;
	};
}

