#pragma once
#include <iostream>
#include <cstdlib>

class CPoint2D
{
public:
	CPoint2D() : _x(0), _y(0) {}
	CPoint2D(double x, double y) : _x(x), _y(y) {}
	CPoint2D(double x) : _x(x), _y(0) {}

	double GetX() {return _x;}
	double GetY() {return _y;}

	void Print() {std::cout<<"Point:: ("<<_x<<","<<_y<<")\n";}

private:
	double _x;
	double _y;
};

CPoint2D operator+ (CPoint2D a, CPoint2D b);