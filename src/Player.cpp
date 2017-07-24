#include"Player.hpp"
#include <iostream>

Player::Player(std::string p_name) : m_name(p_name)
{

}

Player::~Player()
{

}

std::string Player::getName()
{
    return m_name;
}

void Player::run()
{
   // std::cout<< "my name is "<< m_name <<std::endl;

}

void Player::render()
{

}
