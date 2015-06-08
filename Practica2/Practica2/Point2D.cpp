#include <math.h>
#include "Point2D.h"

///////////////////
//Operators
//////////////////


	
	Point2D Point2D::operator + (const Point2D &a) const
	{
		Point2D tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}

	Point2D Point2D::operator += (const Point2D &a)
	{
		Point2D tmp;
		x += a.x;
		y += a.y;
		return (*this);
	}

	Point2D Point2D::operator - (const Point2D &a) const
	{
		Point2D tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	}

	Point2D Point2D::operator -= (const Point2D &a)
	{
		Point2D tmp;
		x -= a.x;
		y -= a.y;
		return (*this);
	}

	//////////////////////
	// Compare 
	/////////////////////

	bool Point2D::operator == (const Point2D &a) const
	{
		return (x == a.x && y == a.y);
	}

	bool Point2D::operator != (const Point2D &a)
	{
		return (x != a.x || y != a.y);
	}

	///////////////////////
	// Distance
	///////////////////////

	float Point2D::distanceTo(const Point2D &a) const
	{
		float vx = x - a.x;
		float vy = y - a.y;
		return sqrtf((vx * vx) + (vy * vy));

	}

	///////////////////////
	// Functions
	///////////////////////

	Point2D& Point2D::setZero()
	{
		x = y = 0.0f;
		return (*this);
	}
	
	bool Point2D::check0() const
	{
		return (x == 0.0f && y == 0.0f);
	}

	Point2D& Point2D::negativeCoord()
	{
		x = -x;
		y = -y;
		return (*this);
	}