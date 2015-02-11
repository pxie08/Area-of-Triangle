#include "ccc_win.h"
#include "Triangle.h"

int ccc_win_main() {
	Triangle t;
	t = Triangle(Point(5,5),Point(-6,1),Point(-4,-6));
	t.draw();
	t.rotate(60);
	t.draw();
	t.scale(1);
	t.move(5,5);
	t.draw();
		Point x,y,z;
	t.getPoints(x,y,z);
	cwin << x << y << z;
	return 0;
}
