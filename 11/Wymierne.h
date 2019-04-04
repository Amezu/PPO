#pragma once
#include "Zespolone.h"

//klasa reprezentująca liczby wymierne
class CWymierne
{
public:
	//konstruktor
	CWymierne(int l, int m) : _licznik(l), _mianownik(m) {}
	//konstruktor konwertujący
	CWymierne(int l) : _licznik(l), _mianownik(1) {}
	//funkcja konwertująca na double
	operator double() const {return (double)_licznik/(double)_mianownik;}
	//funkcja konwertująca na liczbę zespoloną
	operator CZespolone() const {return (double)_licznik/(double)_mianownik;}

	//wypisuje liczbę wymierną
	void Print();

	friend CWymierne Pomnoz(CWymierne a, CWymierne b);

private:
	int _licznik;
	int _mianownik;
};

//mnoży liczby wymierne
CWymierne Pomnoz(CWymierne a, CWymierne b);