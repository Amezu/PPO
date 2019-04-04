#pragma once

class Grade
{
public:
	//Konstruktor
	Grade(double g);
	//Wypisuje ocenę
	void print() const;

private:
	double _value;
	int _id;
};