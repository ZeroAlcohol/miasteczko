#ifndef OBJECT
#define OBJECT
#include <tuple>

class IObject
{
public:
	virtual void run() = 0;
	virtual void render() = 0;
	virtual ~IObject();

private:
	std::pair<int, int> m_xy;


};

#endif