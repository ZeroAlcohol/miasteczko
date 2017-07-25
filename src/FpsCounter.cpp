#include "FpsCounter.hpp"

FpsCounter::FpsCounter()
{

}

unsigned FpsCounter::getFrames()
{
    sf::Time m_elpasedTime = m_clock.getElapsedTime();
    unsigned l_frames = 1.0/m_elpasedTime.asSeconds();
    m_clock.restart().asSeconds();
    return l_frames;
}
