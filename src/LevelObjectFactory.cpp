#include "LevelObjectFactory.hpp"
#include "Player.hpp"
#include "PassiveTexturedRectangle.hpp"
#include "resources.textures.hpp"

std::map<std::string, std::string> g_staticObjectsData
{
	std::make_pair("flowerBox00", rs::tx::flowerBox),
	std::make_pair("flowerBox01", rs::tx::flowerBox),
	std::make_pair("bench00", rs::tx::bench)
};

LevelObjectFactory::LevelObjectFactory(const Spirit::ITextureProvider & p_textureProvider) :
	m_textureProvider { p_textureProvider },
	m_levelObjectMapper
	{
        std::make_pair("player", &LevelObjectFactory::createPlayer),
        std::make_pair("passive-textured-rectangle", &LevelObjectFactory::createPassiveTexturedRectangle)
	}
{}

std::unique_ptr<ILevelObject> LevelObjectFactory::createPlayer(const LevelObjectData & p_data)
{
    sf::Sprite l_sprite(m_textureProvider.getTexture(rs::tx::player));
    Animation l_animation;
    l_animation.setTexture(*l_sprite.getTexture());
    l_animation.addFrame(sf::IntRect(0, 0, 152, 252));
    l_animation.addFrame(sf::IntRect(152, 0, 152, 252));
    l_animation.addFrame(sf::IntRect(0, 255, 152, 252));
    l_animation.addFrame(sf::IntRect(152, 252, 152, 252));
    l_animation.addFrame(sf::IntRect(0, 504, 152, 252));
    l_animation.addFrame(sf::IntRect(152, 504, 152, 252));

    l_animation.setFrameDuration(100);

    l_animation.setPosition(p_data.x, p_data.y);
    l_animation.setRotation(p_data.rotation);

    auto l_defaultPlayerSpeed = 5;

    std::unique_ptr<Player> l_player = std::make_unique<Player>("Robert", l_animation, l_defaultPlayerSpeed);

    return std::move(l_player);
}

std::unique_ptr<ILevelObject> LevelObjectFactory::createPassiveTexturedRectangle(const LevelObjectData & p_data)
{
	const std::string textureKey = g_staticObjectsData[p_data.id];
	sf::Sprite l_sprite(m_textureProvider.getTexture(textureKey));
	std::unique_ptr<PassiveTexturedRectangle> l_object = std::make_unique<PassiveTexturedRectangle>(p_data.x, p_data.y, p_data.rotation, l_sprite);

    return std::move(l_object);
}

std::unique_ptr<ILevelObject> LevelObjectFactory::createLevelObject(const LevelObjectData& p_data)
{
    ObjectCreateMethod_t createFunction = m_levelObjectMapper[p_data.type];

    return (this->*createFunction)(p_data);

}
