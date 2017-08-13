#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <memory>
#include <vector>
#include "IObject.hpp"
#include "AnimatedSprite.hpp"

class Player : public IObject
{
public:
    Player(std::string p_name);
    ~Player();
    std::string getName();
    void run() override;
    void render(sf::RenderWindow& p_window) override;
private:
    std::string m_name;
    AnimatedSprite m_animatedSprite;
    std::unique_ptr<sf::RenderTexture> l_renderTexture; //temporary
};

#endif // PLAYER_H
