#pragma once

#include "IObject.hpp"
#include <memory>
#include <list>

struct Level
{
	std::string id;
	std::list<std::unique_ptr<IObject>> activeObjects; //objects which are performing actions during run()
	std::list<std::unique_ptr<IObject>> passiveObjects; //objects which aren't performing actions during run()
	std::unique_ptr<sf::RenderTexture> backgroundTexture;
	sf::Sprite backgroundSrite;

	unsigned width;
	unsigned height;
};