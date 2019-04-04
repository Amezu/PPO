#include "Wymierne.h"
#include <iostream>
using namespace std;

void CWymierne::Print()
{
	if(_mianownik!=1)
		cout<<_licznik<<"/"<<_mianownik<<endl;
	else
		cout<<_licznik<<endl;
}

CWymierne Pomnoz(CWymierne a, CWymierne b)
{
	return CWymierne(a._licznik*b._licznik, a._mianownik*b._mianownik);
}