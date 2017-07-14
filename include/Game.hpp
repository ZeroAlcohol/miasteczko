#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Player.hpp"


class Game
{
public:
    Game();
    bool createGame();
    void run();

private:
    sf::RenderWindow m_window;
    sf::Event m_event;
};



#endif // GAME_H
