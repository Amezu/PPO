#include "Point2D.h"

CPoint2D operator+ (CPoint2D a, CPoint2D b)
{
	return CPoint2D(a.GetX()+b.GetX(), a.GetY()+b.GetY());
}