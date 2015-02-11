/******************************************
** Rectangle.h
** Declaration of the Rectangle class.
** Todd Wittman, 11/2/07
******************************************/

#include "ccc_win.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
	Rectangle();
	Rectangle(Point TopLeft, double Height, double Width);
	void draw() const;
	void move(double dx, double dy);
	bool operator<= (Rectangle r2) const;
private:
	Point topLeft;
	double height;
	double width;
};

#endif