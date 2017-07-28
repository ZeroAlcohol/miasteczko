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
    bool createGame();
    void mainRun();
	void physicsIteration();
	void renderIteration();

private:
    sf::RenderWindow m_window;
    sf::Event m_event;

	std::list<std::unique_ptr<IObject>> m_activeObjects; //objects which are performing actions during run()
	std::list<std::unique_ptr<IObject>> m_passiveObjects; //objects which aren't performing actions during run()

	
};



#endif // GAME_H
