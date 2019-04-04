#pragma once

//klasa reprezentująca liczby zespolone
class CZespolone
{
public:
	//konstruktor domyślny
	CZespolone() : _Re(0), _Im(0) {}
	//konstruktor
	CZespolone(double r, double i) : _Re(r), _Im(i) {}
	//konstruktor konwertujący
	CZespolone(double r) : _Re(r), _Im(0) {}

	//wypisuje liczbę zespoloną
	void Print();

	friend CZespolone Dodaj(CZespolone a, CZespolone b);

private:
	double _Re;
	double _Im;
};

//dodaje do siebie liczby zespolone
CZespolone Dodaj(CZespolone a, CZespolone b);


///////////////////////////////////////////////////////////


//klasa przechowująca tablicę liczb zespolonych
class CZespoloneTab
{
public:
	//konstruktor
	CZespoloneTab(int n);
	//destruktor
	~CZespoloneTab();
	
	CZespolone& operator[] (int x) {return _tab[x];}

private:
	CZespolone* _tab;
	int _n;
};