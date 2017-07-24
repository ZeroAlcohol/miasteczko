#ifndef OBJECT
#define OBJECT
#include <tuple>
#include <SFML/Graphics.hpp>

class IObject
{
public:
	virtual void run() = 0;
    virtual void render(sf::RenderWindow& p_window) = 0;
    virtual ~IObject(){}

private:
	std::pair<int, int> m_xy;


};

#endif
