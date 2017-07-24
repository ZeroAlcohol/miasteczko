#ifndef TEXTURE_CONTAINER_H
#define TEXTURE_CONTAINER_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>


class TextureContainer
{
public:
    static void createResources();

    sf::Texture& getTexture(std::string p_name);
    void putTexture(std::string p_name, std::string p_adresImage);

    sf::Sprite& getSprite(std::string p_name);

    TextureContainer(const TextureContainer&) = delete;
    TextureContainer& operator=(const TextureContainer&) = delete;

    static TextureContainer& getInstance();

private:
    TextureContainer() {}
     ~TextureContainer();
    std::map<std::string, sf::Texture> m_textureMap;
    std::map<std::string, sf::Sprite> m_spriteMap;

};


#endif // RESOURCE_PROVIDER_H
