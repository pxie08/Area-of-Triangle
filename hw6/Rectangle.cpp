/***************************************************
** Rectangle.cpp
** Definitions of the Rectangle class member functions.
** Todd Wittman, 11/2/07
****************************************************/
#include "Rectangle.h"

/************************************************
** Rectangle()
** Default constructor.
*************************************************/
Rectangle::Rectangle() {
	topLeft = Point(0,0);
	height = 0;
	width = 0;
}

/********************************************************
** Rectangle
** Constructor that takes Point, height, width as input.
**********************************************************/
Rectangle::Rectangle(Point TopLeft, double Height, double Width) {
	topLeft = TopLeft;
	height = Height;
	width = Width;
}

/***************************************************
** draw
** Draws the Rectangle on the screen using cwin<<Line
****************************************************/
void Rectangle::draw() const {
	Point topRight = Point(topLeft.get_x()+width,topLeft.get_y());
	Point bottomLeft = Point(topLeft.get_x(),topLeft.get_y()-height);
	Point bottomRight = Point(topLeft.get_x()+width,topLeft.get_y()-height);
	cwin << Line(topLeft,topRight)
		 << Line(bottomLeft,bottomRight)
		 << Line(topLeft,bottomLeft)
		 << Line(topRight,bottomRight);\
	return;
}

/*******************************************************
** move
** Moves rectangle horizontally by dx, vertically by dy.
** Uses the Point move function.
*******************************************************/
void Rectangle::move(double dx, double dy) {
	topLeft.move(dx,dy);
	return;
}

/*************************************************************
** operator<=
** Used for comparison of rectangles r1 <= r2.
** Returns TRUE if area of Rectangle r1 <= area of Rectangle r2.
**
** NOTE FOR STUDENTS:  This is a good example of operator overloading. 
** The left Rectangle (r1) is the implicit object with dimensions height and width.
** The right Rectangle (r2) is an explicit parameter with dimensions r2.height and r2.width.
**************************************************************/
bool Rectangle::operator<= (Rectangle r2) const {
	return height*width <= r2.height*r2.width;
}