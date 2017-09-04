#include "GameObjectFactory.hpp"
#include "TextureContainer.hpp"
#include "Player.hpp"
#include "PassiveTexturedRectangle.hpp"

std::map<std::string, std::string> g_staticObjectsData
{
	std::make_pair("flowerBox00", rs::tx::flowerBox),
	std::make_pair("flowerBox01", rs::tx::flowerBox),
	std::make_pair("bench00", rs::tx::bench)
};

GameObjectFactory::GameObjectFactory() :
	m_levelObjectMapper
	{
        std::make_pair("player", &GameObjectFactory::createPlayer),
        std::make_pair("passive-textured-rectangle", &GameObjectFactory::createPassiveTexturedRectangle)
	}
{}

std::unique_ptr<IObject> GameObjectFactory::createPlayer(const LevelObjectData & p_data)
{
    sf::Sprite l_sprite = TextureContainer::getSprite(rs::tx::player);
    Animation l_animation;
    l_animation.setTexture(*l_sprite.getTexture());
    l_animation.addFrame(sf::IntRect(0, 0, 152, 252));
    l_animation.addFrame(sf::IntRect(152, 0, 152, 252));
    l_animation.addFrame(sf::IntRect(0, 255, 152, 252));
    l_animation.addFrame(sf::IntRect(152, 252, 152, 252));
    l_animation.addFrame(sf::IntRect(0, 504, 152, 252));
    l_animation.addFrame(sf::IntRect(152, 504, 152, 252));

    l_animation.setFrameDuration(std::chrono::milliseconds(100));

    l_animation.setPosition(p_data.x, p_data.y);
    l_animation.setRotation(p_data.rotation);


    std::unique_ptr<Player> l_player = std::make_unique<Player>("Robert", l_animation);
	return std::move(l_player);
}

std::unique_ptr<IObject> GameObjectFactory::createPassiveTexturedRectangle(const LevelObjectData & p_data)
{
	const std::string textureKey = g_staticObjectsData[p_data.id];
	sf::Sprite l_sprite = TextureContainer::getSprite(textureKey);
	std::unique_ptr<PassiveTexturedRectangle> l_object = std::make_unique<PassiveTexturedRectangle>(p_data.x, p_data.y, p_data.rotation, l_sprite);
	return std::move(l_object);
}

std::unique_ptr<IObject> GameObjectFactory::createLevelObject(const LevelObjectData & p_data)
{
    ObjectCreateMethod_t createFunction = m_levelObjectMapper[p_data.type];
    return (this->*createFunction)(p_data);

}
