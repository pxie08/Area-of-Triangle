#include "ccc_win.h"
#include "Triangle.h"

int ccc_win_main() {

	Triangle t1;
	t1 = Triangle(Point(-1,3),Point(-2,6),Point(-7,-4));
	t1.move(-2,-3);
	t1.draw();
	Point x,y,z;
	t1.getPoints(x,y,z);
	cwin << x << y << z;
	cwin << Message(Point(-6,-8),"Area:");
	cwin << Message(Point(-4,-8),t1.computeArea());
	cwin << Message(Point(-6,-9),"Perimeter:");
	cwin << Message(Point(-4,-9),t1.computePerimeter());

	Triangle t2(Point(4,6),Point(8,1),Point(3,-8));
	t2.scale(0.5);
	t2.rotate(1.5);
	t2.draw();
	cwin << Message(Point(6,-8),"Area:");
	cwin << Message(Point(8,-8),t2.computeArea());
	cwin << Message(Point(6,-9),"Perimeter:");
	cwin << Message(Point(8,-9),t2.computePerimeter());

	if (t1 == t2)
		cwin << Message(Point(-2,0), "The triangles have the same size.");
	else if (t1 > t2)
		cwin << Message(Point(-2,0), "The left triangle is bigger.");
	else if (t1 < t2)
		cwin << Message(Point(-2,0), "The right triangle is bigger.");
	return 0;
}