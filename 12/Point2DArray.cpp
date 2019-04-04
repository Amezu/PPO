#include "Point2DArray.h"
#include <cstring>
using std::cout;

CPoint2DArray::CPoint2DArray(CPoint2D p, int n)
{
	_n = n;
	_t = new CPoint2D[n];

	for(int x=0; x<n; x++)
		_t[x] = p;
}

void CPoint2DArray::Print()
{
	cout<<"Point array:: ";
	if(_n!=0)
	{
		cout<<"("<<_t[0].GetX()<<","<<_t[0].GetY()<<")";
		for(int x=1; x<_n; x++)
		{
			cout<<", ";
			cout<<"("<<_t[x].GetX()<<","<<_t[x].GetY()<<")";
		}
		cout<<"\n";
	}
}

/*CPoint2DArray& CPoint2DArray::operator= (const CPoint2DArray& a)
{
	_n = a._n;
	CPoint2D* temp = new CPoint2D[a._n];

	for(int x=0; x<a._n; x++)
		temp[x] = CPoint2D(a._t[x].GetX(), a._t[x].GetY());

	_t = new CPoint2D[_n];
	memcpy(_t, temp, _n*sizeof(CPoint2D));

	if(&a == this)
		return *this;

	delete[] _t;

	_n = a._n;
	_t = new CPoint2D[_n];

	for(int x=0; x<a._n; x++)
		_t[x] = CPoint2D(a._t[x].GetX(), a._t[x].GetY());

	return *this;
}
*/

CPoint2DArray::CPoint2DArray (const CPoint2DArray& a)
{
	_n = a._n;
	_t = new CPoint2D[_n];

	for(int x=0; x<a._n; x++)
		_t[x] = CPoint2D(a._t[x].GetX(), a._t[x].GetY());
}

void CPoint2DArray::FillRand(int a, int b)
{
	for(int x=0; x<_n; x++)
		_t[x] = CPoint2D(rand()%(a+b+1)+a/1., rand()%(a+b+1)+a/1.);
}