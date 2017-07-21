#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "IObject.hpp"

class Player : public IObject
{
public:
    Player(std::string p_name);
    ~Player();
    std::string getName();
    void run() override;
    void render() override;
private:
    std::string m_name;
};

#endif // PLAYER_H
