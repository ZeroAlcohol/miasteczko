#pragma once
#include <SFML/Graphics.hpp>
#include <Text.hpp>

class Menu
{
public:

    enum class State {Play = 1, Options, Exit};

    Menu();
    State run();
    void renderFrame(sf::RenderWindow& p_window);

private:
    State m_currentState;
    Text Play;
    Text Options;
    Text Exit;




};
