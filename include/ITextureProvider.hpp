#pragma once

#include <SFML/Graphics.hpp>

namespace Spirit
{
	class ITextureProvider
	{
	public:
		virtual const sf::Texture& getTexture(const std::string p_name) const = 0;
	};
}
