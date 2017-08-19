#ifndef COLLISION_BOX
#define COLLISION_BOX
#include <tuple>
#include <vector>
#include <cmath>


class CollisionBox
{
	enum class figureType {circle, rectangle};

public:
	CollisionBox();
    CollisionBox(std::vector<std::pair<float, float> > p_points);
	~CollisionBox();

	inline float calculateRadius();//only for circle

	bool CollisionBox::detectCollision(const CollisionBox& p_a);
	bool collisionCircleCircle(const CollisionBox p_a, const CollisionBox p_b);
	bool collisionCircleRectangle(const CollisionBox p_a, const CollisionBox p_b);
	bool collisionRectangleRectangle(const CollisionBox p_a, const CollisionBox p_b);


private:
	std::vector <std::pair <float, float> > m_points; //in case of circle one point is center second point is one from edge
	figureType m_figureType;

	float distancePointPoint(const std::pair<float, float>& p_a, const std::pair<float, float>& p_b);
	float distancePointLine(const std::pair<float, float>& p_point, const std::pair<float, float>& p_line1, const std::pair<float, float>& p_line2);
	bool pointBetweenLines(const std::pair<float, float>& p_point, const std::pair<float, float> & p_lineA1, const std::pair<float, float> & p_lineA2, const std::pair<float, float> & p_lineB1, const std::pair<float, float> & p_lineB2);
};

#endif
