#include "TextureContainer.hpp"

void TextureContainer::createResources()
{
    //use putImage
}

sf::Texture &TextureContainer::getTexture(std::string p_name)
{
    return TextureContainer::getInstance().m_textureMap[p_name];
}

void TextureContainer::putTexture(std::string p_name, std::string p_adresImage)
{
    sf::Texture l_texture;
    l_texture.loadFromFile(p_adresImage);
    TextureContainer::getInstance().m_textureMap.emplace(std::make_pair(p_name, l_texture));
    sf::Sprite l_sprite;
    l_sprite.setTexture(TextureContainer::getInstance().m_textureMap[p_name]);
    TextureContainer::getInstance().m_spriteMap.emplace(std::make_pair(p_name, l_sprite));
}

sf::Sprite& TextureContainer::getSprite(std::string p_name)
{
    return TextureContainer::getInstance().m_spriteMap[p_name];
}

TextureContainer &TextureContainer::getInstance()
{
    static TextureContainer instance{};
    return instance;
}

TextureContainer::~TextureContainer()
{
}
