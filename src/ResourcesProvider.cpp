#include "ResourcesProvider.hpp"

void ResourcesProvider::createResources()
{
    //use putImage here
}

sf::Texture &ResourcesProvider::getImage(std::string p_name)
{
    return ResourcesProvider::getInstance().m_textureMap[p_name];
}

void ResourcesProvider::putImage(std::string p_name, std::string p_adresImage)
{
    sf::Texture l_texture;
    l_texture.loadFromFile(p_adresImage);
    ResourcesProvider::getInstance().m_textureMap.emplace(std::make_pair(p_name, l_texture));
}

ResourcesProvider &ResourcesProvider::getInstance()
{
    static ResourcesProvider instance{};
    return instance;
}

ResourcesProvider::ResourcesProvider()
{

}

ResourcesProvider::~ResourcesProvider()
{

}
