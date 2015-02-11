/***************************************************
** triangle.cpp
** Definitions of the Triangle class member functions.
** Patrick Xie, 2/20/10
****************************************************/
#include "Triangle.h"
#include <cmath>

/***************************************************
** Triangle
** default constructor
****************************************************/
Triangle::Triangle() {
	A = Point(0,1);
	B = Point(1,0);
	C = Point(-1,0);
}

/***************************************************
** Triangle
** constructor that takes three different Points as 
** input
****************************************************/
Triangle::Triangle(Point newA, Point newB, Point newC) {
	A = newA;
	B = newB;
	C = newC;
}

/***************************************************
** get_a
** For private. returns the length of a which is
** across the corner of A
****************************************************/
double Triangle::get_a() const {
	double p1,p2,a;
	p1 = pow((B.get_x()-C.get_x()),2);
	p2 = pow((B.get_y()-C.get_y()),2);
	a = sqrt(p1+p2);
	return a;
}

/***************************************************
** get_b
** For private. returns the length of a which is
** across the corner of B
****************************************************/
double Triangle::get_b() const {
	double p1,p2,b;
	p1 = pow((A.get_x()-C.get_x()),2);
	p2 = pow((A.get_y()-C.get_y()),2);
	b = sqrt(p1+p2);
	return b;
}

/***************************************************
** get_c
** For private. returns the length of a which is
** across the corner of C
****************************************************/
double Triangle::get_c() const {
	double p1,p2,c;
	p1 = pow((A.get_x()-B.get_x()),2);
	p2 = pow((A.get_y()-B.get_y()),2);
	c = sqrt(p1+p2);
	return c;
}

/***************************************************
** draw
** Draws the triangle using the Points A,B, and C
** by using cwin << Line
****************************************************/
void Triangle::draw() const {
	cwin << Line (Point(A),Point(B))
		<< Line (Point(B),Point(C))
		<< Line (Point(C),Point(A));
	return;
}

/***************************************************
** get_center
** For private. Returns the Point where the center is
****************************************************/
Point Triangle::get_center() const {
	double xA,xB,xC,yA,yB,yC,xcoord,ycoord;
	xA = A.get_x();
	yA = A.get_y();
	xB = B.get_x();
	yB = B.get_y();
	xC = C.get_x();
	yC = C.get_y();
	xcoord = (xA+xB+xC)/3;
	ycoord = (yA+yB+yC)/3;
	return Point(xcoord,ycoord);
}

/***************************************************
** move
** Move the triangle horizontally by amount dx, 
** vertically by dy
****************************************************/
void Triangle::move(double dx, double dy) {
	A = Point (A.get_x()+dx,A.get_y()+dy);
	B = Point (B.get_x()+dx,B.get_y()+dy);
	C = Point (C.get_x()+dx,C.get_y()+dy);
	return;
}

/***************************************************
** computePerimeter
** returns the perimeter of the triangle
****************************************************/
double Triangle::computePerimeter() const {
	double perimeter;
	perimeter = get_a()+get_b()+get_c();
	return perimeter;
}

/***************************************************
** computeArea
** returns the area of the triangle
****************************************************/
double Triangle::computeArea() const {
	double s;
	double area;
	s = computePerimeter()/2;
	area = sqrt((s*(s-get_a())*(s-get_b())*(s-get_c())));
	return area;
}

/***************************************************
** getPoints
** Returns the triangle's three points in the 
** parameters
****************************************************/
void Triangle::getPoints (Point& myA, Point& myB, Point& myC) const {
	myA = A;
	myB = B;
	myC = C;
}

/***************************************************
** operator<=,>=,<,>,==
** Used for comparison of Triangles t1 and t2.
** Returns TRUE if bool statement is true.
****************************************************/
bool Triangle::operator> (Triangle t) const {
	return computeArea() > t.computeArea();
}
bool Triangle::operator< (Triangle t) const {
	return computeArea() < t.computeArea();
}
bool Triangle::operator>= (Triangle t) const {
	return computeArea() >= t.computeArea();
}
bool Triangle::operator<= (Triangle t) const{
	return computeArea() <= t.computeArea();
}
bool Triangle::operator== (Triangle t) const{
	return computeArea() == t.computeArea();
}

/***************************************************
** scale
** returns a new Triangle scaled by the input
****************************************************/
void Triangle::scale(double size) {
	Point center = get_center();
	double xA,yA,xB,yB,xC,yC,xcenter,ycenter,a1,a2,b1,b2,c1,c2;
	xcenter = center.get_x();
	ycenter = center.get_y();
	xA = A.get_x() - xcenter;
	yA = A.get_y() - ycenter;
	xB = B.get_x() - xcenter;
	yB = B.get_y() - ycenter;
	xC = C.get_x() - xcenter; 
	yC = C.get_y() - ycenter;
	a1 = xA*size + xcenter;
	a2 = yA*size + ycenter;
	b1 = xB*size + xcenter;
	b2 = yB*size + ycenter;
	c1 = xC*size + xcenter;
	c2 = yC*size + ycenter;
	A = Point(a1,a2);
	B = Point(b1,b2);
	C = Point(c1,c2);
	return;
}

/***************************************************
** rotate
** rotates the Triangle according to the theta 
** the user inputs.
****************************************************/
void Triangle::rotate(double theta) {
	Point center = get_center();
	double xA,yA,xB,yB,xC,yC,xcenter,ycenter,a1,a2,b1,b2,c1,c2;
	xcenter = center.get_x();
	ycenter = center.get_y();
	xA = A.get_x() - xcenter;
	yA = A.get_y() - ycenter;
	xB = B.get_x() - xcenter;
	yB = B.get_y() - ycenter;
	xC = C.get_x() - xcenter; 
	yC = C.get_y() - ycenter;
	a1 = xA*cos(theta) - yA*sin(theta) +xcenter;
	a2 = yA*cos(theta) + xA*sin(theta) +ycenter;
	b1 = xB*cos(theta) - yB*sin(theta) +xcenter;
	b2 = yB*cos(theta) + xB*sin(theta) +ycenter;
	c1 = xC*cos(theta) - yC*sin(theta) +xcenter;
	c2 = yC*cos(theta) + xC*sin(theta) +ycenter;
	A = Point(a1,a2);
	B = Point(b1,b2);
	C = Point(c1,c2);
	return;
}