#include "TextureContainer.hpp"

void TextureContainer::createResources()
{
    //use putImage
}

sf::Texture &TextureContainer::getImage(std::string p_name)
{
    return TextureContainer::getInstance().m_textureMap[p_name];
}

void TextureContainer::putImage(std::string p_name, std::string p_adresImage)
{
    sf::Texture l_texture;
    l_texture.loadFromFile(p_adresImage);
    TextureContainer::getInstance().m_textureMap.emplace(std::make_pair(p_name, l_texture));
}

TextureContainer &TextureContainer::getInstance()
{
    static TextureContainer instance{};
    return instance;
}

TextureContainer::~TextureContainer()
{

}
