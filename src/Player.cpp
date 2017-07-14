#include"Player.hpp"

Player::Player(std::string p_name) : m_name(p_name)
{

}

std::string Player::getName()
{
    return m_name;
}
