#include "CollisionBox.hpp"    

CollisionBox::CollisionBox()
{

}

CollisionBox::CollisionBox(std::vector<std::pair<float, float> > p_points)
{
	if (p_points.size() == 2)
	{
		m_figureType = circle;
	}
	if (p_points.size() == 4)
	{
		m_figureType = rectangle;
	}

	m_points = p_points;
}

CollisionBox::~CollisionBox()
{

}

float CollisionBox::distancePointPoint(const std::pair<float, float>& p_a,const std::pair<float, float>& p_b)
{
	return sqrt((p_a.first - p_b.first) * (p_a.first - p_b.first) + (p_a.second - p_b.second) * (p_a.second - p_b.second));
}


float CollisionBox::distancePointLine(const std::pair<float, float>& p_point, const std::pair<float, float>& p_line1,const std::pair<float, float>& p_line2)
{
	if ( p_line1 == p_line2)
	{
		distancePointPoint(p_point, p_line2);
	}

	if (p_line2.first == p_line1.first)
	{
		return p_line2.first - p_point.first;
	}

	//ax+by+c = 0
	float a = (p_line2.second - p_line1.second) / (p_line2.first - p_line1.first);
	float b = -1;
	float c = p_line1.second - a*p_line1.first;

	return abs(a*p_point.first + b*p_point.second + c) / (sqrt(a*a + b*b));

}

bool CollisionBox::pointBetweenLines(const std::pair<float, float>& p_point, const std::pair<float, float> & p_lineA1, const std::pair<float, float> & p_lineA2, const std::pair<float, float> & p_lineB1, const std::pair<float, float> & p_lineB2)
{
	float aA = (p_lineA2.second - p_lineA1.second) / (p_lineA2.first - p_lineA1.first);
	float bA = p_lineA1.second - aA*p_lineA1.first;

	float aB = (p_lineB2.second - p_lineB1.second) / (p_lineB2.first - p_lineB1.first);
	float bB = p_lineB1.second - aA*p_lineB1.first;

	if (aA*p_point.first + bA < p_point.second)
	{
		if (aB*p_point.first + bB > p_point.second)
		{
			return true;
		}
	}

	if (aB*p_point.first + bB < p_point.second)
	{
		if (aA*p_point.first + bA > p_point.second)
		{
			return true;
		}
	}

	return false;
}


float CollisionBox::calculateRadius()
{
	if (m_figureType == circle)
	{
		return distancePointPoint(m_points[0], m_points[1]);
	}

	else
	{
		return 0;
	}
}

bool CollisionBox::detectCollision(const CollisionBox& p_a)
{
	if (m_figureType == circle && p_a.m_figureType == circle)
	{
		return collisionCircleCircle(*this, p_a);
	}

	if (m_figureType == circle && p_a.m_figureType == rectangle)
	{
		return collisionCircleRectangle(*this, p_a);
	}

	if (m_figureType == rectangle && p_a.m_figureType == circle)
	{
		return collisionCircleRectangle(p_a, *this);
	}

	if (m_figureType == rectangle && p_a.m_figureType == rectangle)
	{
		return collisionRectangleRectangle(*this, p_a);
	}

	return false;
}


bool CollisionBox::collisionCircleCircle(const CollisionBox p_a, const CollisionBox p_b)
{
	if (distancePointPoint(p_a.m_points[0], p_b.m_points[0] ) < p_a.calculateRadius + p_b.calculateRadius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionBox::collisionCircleRectangle(const CollisionBox p_a, const CollisionBox p_b)
{
	float l_circleRadius = p_a.calculateRadius;
	for (int i = 0; i < 3; i++)
	{
		if (distancePointPoint(p_a.m_points[0], p_b.m_points[i]) < l_circleRadius)
		{
			return true;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (distancePointLine(p_a.m_points[0], p_b.m_points[i], p_b.m_points[i+1]) < l_circleRadius)
		{
			return true;
		}
	}

	if (distancePointLine(p_a.m_points[0], p_b.m_points[3], p_b.m_points[0]) < l_circleRadius)
	{
		return true;
	}

	return false;
}


bool CollisionBox::collisionRectangleRectangle(const CollisionBox p_a, const CollisionBox p_b)
{
	for (int i = 0; i < 3; i++)
	{
		if (pointBetweenLines(p_a.m_points[i], p_b.m_points[0], p_b.m_points[1], p_b.m_points[2], p_b.m_points[3]))
		{
			if (pointBetweenLines(p_a.m_points[i], p_b.m_points[1], p_b.m_points[2], p_b.m_points[3], p_b.m_points[0]))
			{
				return true;
			}
		}
	}

	return false;
}
