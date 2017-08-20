#pragma once
#include <SFML/Graphics.hpp>

#include <chrono>

using namespace std::chrono_literals;


class Animation : public sf::Sprite
{
public:
    Animation(std::chrono::microseconds p_duration = 50ms);

    void setFrameDuration(std::chrono::microseconds p_duration);
    void setFrame(unsigned p_frame);   
    void addFrame(sf::IntRect p_rect);
    sf::IntRect getFrame(unsigned p_n);

    void playAnimation();
    void pauseAnimation();
    void stopAnimation();
    void updateAnimation();

    void setLooped(bool p_looped);
    bool isLooped();
    bool isPlaying();

    std::chrono::microseconds getFrameDuration();
    std::chrono::time_point<std::chrono::system_clock> getCurrentTime();

private:
    std::chrono::microseconds m_frameDuration;
    std::chrono::time_point<std::chrono::system_clock> m_currentTime;
    std::chrono::time_point<std::chrono::system_clock> m_frameTime;
    unsigned m_currentFrame;
    bool m_isPaused;
    bool m_isLooped;
    std::vector<sf::IntRect> m_frames;


};
