#pragma once

#include "Grade.h"

class GradeBook
{
public:
	//Konstruktor
	GradeBook() {}
	//Konstruktor kopiujący
	GradeBook(const GradeBook& gb);
	//Destruktor
	~GradeBook();

	//Dodaje ocenę
	void insert(const Grade* g);
	//Dodaje ocenę
	void addGrade(double g);
	//Usuwa ocenę
	void remove(int i);
	//Wypisuje oceny
	void print() const;

private:
	const Grade** _book;
	int _count = 0;
};