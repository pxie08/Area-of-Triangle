/*******************************************
** rectangles.cpp
** Simple example to use the Rectangle class.
** Todd Wittman, 11/2/07
*******************************************/

#include "ccc_win.h"
#include "Rectangle.h"

int ccc_win_main() {
	Rectangle r1;
	Rectangle r2(Point(-3,5),3,5);
	r1 = Rectangle(Point(2,-3),6,6);
	r1.draw();
	r2.draw();
	r2.move(-3,-2);
	r2.draw();
	if (r1 <= r2)
		cwin << Message(Point(0,0),"r1 is smaller");
	else
		cwin << Message(Point(0,0),"r2 is smaller");

	return 0;
}










