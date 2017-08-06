#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "IObject.hpp"
#include <memory>
#include <list>

class Game
{
public:
    Game();
	void onEvent(sf::Event & p_event);
	void renderFrame(sf::RenderWindow & p_window);
	void update(const float dt);
    bool createGame();

private:
	sf::Sprite m_exampleSprite;

	std::list<std::unique_ptr<IObject>> m_activeObjects; //objects which are performing actions during run()
	std::list<std::unique_ptr<IObject>> m_passiveObjects; //objects which aren't performing actions during run()
	

};



#endif // GAME_H
