#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <level.hpp>

class Game
{
public:
    Game();
	void onEvent(sf::Event & p_event);
	void renderFrame(sf::RenderWindow & p_window, const float dt);
	void update(const float dt);
    bool createGame();

private:
	Level m_level;

	sf::View getLevelView() const;
};



#endif // GAME_H
