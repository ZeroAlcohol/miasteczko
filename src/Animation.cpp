#include "Animation.hpp"

Animation::Animation(unsigned p_duration) : m_isLooped(true), m_isPaused(false), m_currentFrame{0}
{
    m_currentTime = std::chrono::system_clock::now();
    m_frameDuration = std::chrono::microseconds(p_duration);
    m_frameTime = m_currentTime + m_frameDuration;
}

void Animation::playAnimation()
{
    m_isPaused = false;
}

void Animation::setFrame(unsigned p_frame)
{
    m_currentFrame = p_frame;
}

void Animation::setFrameDuration(unsigned p_duration)
{
    m_frameDuration = std::chrono::microseconds(p_duration);
}

void Animation::pauseAnimation()
{
    m_isPaused = true;
}

void Animation::stopAnimation()
{
    m_isPaused = true;
    m_currentFrame = 0;
}

void Animation::setLooped(bool p_looped)
{
    m_isLooped = p_looped;
}

bool Animation::isLooped()
{
    return m_isLooped;
}

bool Animation::isPlaying()
{
    return !m_isPaused;
}

Animation::TimePoint Animation::getCurrentTime()
{
    return m_currentTime;
}

std::chrono::microseconds Animation::getFrameDuration()
{
    return m_frameDuration;
}

void Animation::updateAnimation()
{

    if (! m_isPaused)
    {
        m_currentTime = std::chrono::system_clock::now();

        if(m_currentTime > m_frameTime)
        {
            m_frameTime = m_currentTime + m_frameDuration;
            if (m_currentFrame +1 < m_frames.size())
                    m_currentFrame++;
            else
                m_currentFrame = 0;
        }

        setTextureRect(m_frames[m_currentFrame]);
    }
}

sf::IntRect Animation::getFrame(unsigned p_n)
{
    return m_frames[p_n];
}

void Animation::addFrame(sf::IntRect p_rect)
{
    m_frames.push_back(p_rect);
}
