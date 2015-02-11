#include "ccc_win.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
	public:
		//Default constructor.
		Triangle();

		//Constructor that takes 3 points.
		Triangle (Point newA, Point newB, Point newC);

		//Draw the current triangle in the graphics window.
		void draw() const;

		//Move the triangle horizontally by amount dx, vertically by dy.
		void move(double dx, double dy);

		//Scale the triangle by a factor size.
		//Should be resized around its center.
		void scale(double size);

		//Rotate the triangle around its center by a radian angle theta.
		void rotate(double theta);

		//Compute the perimeter of the triangle.
		double computePerimeter() const;

		//Compute the area of the triangle.
		double computeArea() const;

		//Return the triangle's three points in the parameters.
		void getPoints (Point& myA, Point& myB, Point& myC) const;

		//The following operator compare the areas of 2 triangles.
		bool operator> (Triangle t) const;
		bool operator< (Triangle t) const;
		bool operator>= (Triangle t) const;
		bool operator<= (Triangle t) const;
		bool operator== (Triangle t) const;

	private:
		Point A, B, C;

		//Get the length of the side opposite point A.
		double get_a() const;

		//Get the length of the side opposite point B.
		double get_b() const;

		//Get the length of the side opposite point C.
		double get_c() const;

		//Get the center of the triangle.
		Point get_center() const;
};



#endif