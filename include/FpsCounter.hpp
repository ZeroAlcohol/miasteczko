#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H
#include <SFML/System.hpp>


class FpsCounter
{
public:
    FpsCounter();
    unsigned getFrames();
private:
    sf::Clock m_clock;
    sf::Time m_elpasedTime;
};

#endif // FPS_COUNTER_H
