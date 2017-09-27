#pragma once

#include <tuple>
#include <vector>
#include <cmath>


class CollisionBox
{
	enum class FigureType {circle, rectangle};

    using Point = std::pair<float, float>;

public:
	CollisionBox();
    CollisionBox(std::vector<Point> p_points);

	float calculateRadius() const;//only for circle
    bool detectCollision(const CollisionBox& p_a);
	void translate(std::pair<float, float> p_translationVector);

private:
	std::vector<Point> m_points; //in case of circle one point is center second point is one from edge
    FigureType m_figureType;

	float distancePointPoint(const Point& p_a, const Point& p_b) const;
	float distancePointLine(const Point& p_point, const Point& p_line1, const Point& p_line2) const;
	bool pointBetweenLines(const Point& p_point, const Point& p_lineA1, const Point& p_lineA2, const Point& p_lineB1, const Point& p_lineB2) const;
	bool collisionCircleCircle(const CollisionBox& p_a, const CollisionBox& p_b);
	bool collisionCircleRectangle(const CollisionBox& p_a, const CollisionBox& p_b);
	bool collisionRectangleRectangle(const CollisionBox& p_a, const CollisionBox& p_b);

};

