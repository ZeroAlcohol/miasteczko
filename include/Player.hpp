#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <memory>
#include "IObject.hpp"
#include "Animation.hpp"

class Player : public IObject
{
public:
    Player();
    Player(std::string p_name, Animation p_animation);
    ~Player();
    std::string getName() const;
    void run() override;
    void render(sf::RenderWindow& p_window) override;
	std::pair <float, float> getCenterCoordinates() const;
	
private:
    std::string m_name;
    Animation m_animation;
    float m_speed;
};

#endif // PLAYER_H
