#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player(std::string p_name);
    std::string getName();
private:
    std::string m_name;

};

#endif // PLAYER_H
