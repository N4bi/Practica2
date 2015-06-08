#ifndef __Point2D_H__
#define __Point2D_H__

class Point2D{

public:
	float x, y;


	///////////////////////
	// Functions
	///////////////////////

	Point2D& setZero();
	bool check0() const;
	Point2D& negativeCoord();

	///////////////////////
	//Operators
	//////////////////////

	Point2D operator + (const Point2D &a) const;
	Point2D operator += (const Point2D &a);
	Point2D operator - (const Point2D &a) const;
	Point2D operator -= (const Point2D &a);
	
	bool operator == (const Point2D &a) const;
	bool operator != (const Point2D &a);

	float distanceTo (const Point2D &a) const;



};



#endif // __Point2D_H__