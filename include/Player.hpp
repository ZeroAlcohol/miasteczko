#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <memory>
#include <vector>
#include "IObject.hpp"
#include "Animation.hpp"

class Player : public IObject
{
public:
    Player(std::string p_name, sf::Sprite p_sprite);
    ~Player();
    std::string getName();
    void run() override;
    void render(sf::RenderWindow& p_window) override;
	std::pair <float, float> getCenterCoordinates() const;
	
private:
    std::string m_name;
    Animation m_animation;
};

#endif // PLAYER_H
