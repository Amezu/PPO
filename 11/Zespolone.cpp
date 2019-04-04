#include "Zespolone.h"
#include <iostream>
using namespace std;

void CZespolone::Print()
{
	cout<<"("<<_Re<<","<<_Im<<")\n";
}

CZespolone Dodaj(CZespolone a, CZespolone b)
{
	return CZespolone(a._Re+b._Re, a._Im+b._Im);
}

////////////////////////////////////////////////////

CZespoloneTab::CZespoloneTab(int n)
{
	_tab = new CZespolone[n];
	_n=n;
}

CZespoloneTab::~CZespoloneTab()
{
	delete[] _tab;
}