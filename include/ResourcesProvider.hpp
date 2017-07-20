#ifndef RESOURCE_PROVIDER_H
#define RESOURCE_PROVIDER_H

#include <SFML/Graphics.hpp>
#include <map>


class ResourcesProvider
{
public:
    static void createResources();

    sf::Texture& getImage(std::string p_name);
    void putImage(std::string p_name, std::string p_adresImage);

    ResourcesProvider(const ResourcesProvider&) = delete;
    ResourcesProvider& operator=(const ResourcesProvider&) = delete;

    static ResourcesProvider& getInstance();

private:
    ResourcesProvider();
     ~ResourcesProvider();
    std::map<std::string, sf::Texture> m_textureMap;

};


#endif // RESOURCE_PROVIDER_H
