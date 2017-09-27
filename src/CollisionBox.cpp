#include "CollisionBox.hpp"    

CollisionBox::CollisionBox()
{

}

CollisionBox::CollisionBox(std::vector<Point> p_points)
{
	if (p_points.size() == 2)
	{
		m_figureType = FigureType::circle;
	}
	if (p_points.size() == 4)
	{
		m_figureType = FigureType::rectangle;
	}

	m_points = p_points;
}


float CollisionBox::distancePointPoint(const Point& p_a, const Point& p_b) const
{
	return sqrt((p_a.first - p_b.first) * (p_a.first - p_b.first) + (p_a.second - p_b.second) * (p_a.second - p_b.second));
}


float CollisionBox::distancePointLine(const Point& p_point, const Point& p_line1, const Point& p_line2) const
{
	if (p_line1 == p_line2)
	{
		return distancePointPoint(p_point, p_line2);
	}

	if (p_line2.first == p_line1.first)
	{
		return p_line2.second - p_point.second;
	}

	//y = a1 * x + b1 - line made of 2 points
	float a1 = (p_line2.second - p_line1.second) / (p_line2.first - p_line1.first);
	float b1 = p_line2.second - a1 * p_line2.first;

	//y = a2 * x + b2 - line normal to previously calculated 
	float a2 = (-1 / a1);
	float b2 = p_point.second - a2 * p_point.first;

	//cross point of lines
	float x = (b2 - b1) / (a1 - a2);
	float y = a1 * x + b1;

	if ( (x > p_line1.first && x < p_line2.first)  || (x < p_line1.first && x > p_line2.first))
	{
		return distancePointPoint(p_point, std::pair<float, float>(x, y));
	}
	
	float dist1 = distancePointPoint(p_point, p_line1);
	float dist2 = distancePointPoint(p_point, p_line1);

	return (dist1 < dist2) ? dist1 : dist2;
}

bool CollisionBox::pointBetweenLines(const Point& p_point, const Point& p_lineA1, const Point& p_lineA2, const Point& p_lineB1, const Point& p_lineB2) const
{
	if (p_lineA2.first == p_lineA1.first)
	{
		if (p_lineA2.first > p_point.first &&  p_lineB2.first < p_point.first)
		{
			return true;
		}

		if (p_lineA2.first < p_point.first &&  p_lineB2.first > p_point.first)
		{
			return true;
		}

		return false;
	}

	float aA = (p_lineA2.second - p_lineA1.second) / (p_lineA2.first - p_lineA1.first);
	float bA = p_lineA1.second - aA * p_lineA1.first;

	float aB = (p_lineB2.second - p_lineB1.second) / (p_lineB2.first - p_lineB1.first);
	float bB = p_lineB1.second - aB * p_lineB1.first;

	if (aA * p_point.first + bA < p_point.second)
	{
		if (aB * p_point.first + bB > p_point.second)
		{
			return true;
		}
	}

	if (aB * p_point.first + bB < p_point.second)
	{
		if (aA * p_point.first + bA > p_point.second)
		{
			return true;
		}
	}

	return false;
}


float CollisionBox::calculateRadius() const
{
	float result;
	result = ((m_figureType == FigureType::circle) ? (distancePointPoint(m_points[0], m_points[1])) : (0));
	return result;
}

bool CollisionBox::detectCollision(const CollisionBox& p_a)
{
	if (m_figureType == FigureType::circle && p_a.m_figureType == FigureType::circle)
	{
		return collisionCircleCircle(*this, p_a);
	}

	if (m_figureType == FigureType::circle && p_a.m_figureType == FigureType::rectangle)
	{
		return collisionCircleRectangle(*this, p_a);
	}

	if (m_figureType == FigureType::rectangle && p_a.m_figureType == FigureType::circle)
	{
		return collisionCircleRectangle(p_a, *this);
	}

	if (m_figureType == FigureType::rectangle && p_a.m_figureType == FigureType::rectangle)
	{
		return collisionRectangleRectangle(*this, p_a);
	}

	return false;
}

void CollisionBox::translate(std::pair<float, float> p_translationVector)
{
	for (int i = 0; i < m_points.size(); i++)
	{
		m_points[i].first += p_translationVector.first;
		m_points[i].second += p_translationVector.second;
	}
}

void CollisionBox::rotate(float angle)
{
	if (m_figureType == FigureType::circle)
	{
		//do nothing in general, circle is the same no matter what happens
	}

	if (m_figureType == FigureType::rectangle)
	{
		rotateRectangle(angle);
	}
}



bool CollisionBox::collisionCircleCircle(const CollisionBox& p_a, const CollisionBox& p_b)
{
	if (distancePointPoint(p_a.m_points[0], p_b.m_points[0] ) < p_a.calculateRadius() + p_b.calculateRadius() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionBox::collisionCircleRectangle(const CollisionBox& p_a, const CollisionBox& p_b)
{
	float l_circleRadius = p_a.calculateRadius();

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


bool CollisionBox::collisionRectangleRectangle(const CollisionBox& p_a, const CollisionBox& p_b)
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

	for (int i = 0; i < 3; i++)
	{
		if (pointBetweenLines(p_b.m_points[i], p_a.m_points[0], p_a.m_points[1], p_a.m_points[2], p_a.m_points[3]))
		{
			if (pointBetweenLines(p_b.m_points[i], p_a.m_points[1], p_a.m_points[2], p_a.m_points[3], p_a.m_points[0]))
			{
				return true;
			}
		}
	}
	return false;
}

void CollisionBox::rotateRectangle(float angle) //angle in degrees
{
	for (int i = 0; i < 4; i++)
	{
	Point center;
	center.first = m_points[0].first + 0.5 * (m_points[2].first - m_points[0].first);
	center.second = m_points[0].second + 0.5 * (m_points[2].second - m_points[0].second);


	m_points[i].first -= center.first;
	m_points[i].second -= center.second;

	float angleRad = angle * M_PI / 180;
	m_points[i].first = m_points[i].first * cos(angleRad) - m_points[i].second * sin(angleRad);
	m_points[i].second = m_points[i].second * cos(angleRad) + m_points[i].first * sin(angleRad);

	m_points[i].first += center.first;
	m_points[i].second += center.second;
	}
}