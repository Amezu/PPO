#pragma once
#include "Point2D.h"

class CPoint2DArray
{
public:
	CPoint2DArray() {};
	CPoint2DArray(int n) : _n(n) {_t = new CPoint2D[n];}
	CPoint2DArray(CPoint2D p, int n);
	CPoint2DArray (const CPoint2DArray& a);
	~CPoint2DArray() {delete[] _t;}

	/*CPoint2DArray& operator= (const CPoint2DArray& a)
	{
		if(&a == this)
			return (*this);
	}*/
	CPoint2D& operator[] (int x) {return _t[x];}

	void Print();
	void FillRand (int a, int b);

private:
	CPoint2D* _t = NULL;
	int _n;
};