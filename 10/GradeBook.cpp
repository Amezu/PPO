#include "GradeBook.h"

#include <cstring>
#include <iostream>
using namespace std;

void GradeBook::insert(const Grade* g)
{
	if(_count == 0)
	{
		_book = new const Grade* [1];
		_book[0] = g;
	}
	else
	{
		//Powiększenie tablicy _book
		Grade** temp = new Grade* [_count];
		memcpy(temp, _book, _count*sizeof(Grade*));
		delete [] _book;
		_book = new const Grade* [_count+1];
		memcpy(_book, temp, _count*sizeof(Grade*));
		delete [] temp;

		//Wstawienie nowego elementu
		_book[_count] = g;
	}
	_count++;
}

void GradeBook::addGrade(double g)
{
	insert(new Grade(g));
}

void GradeBook::print() const
{
	cout<<"Grades in the book:\n";
	for(int x=0; x<_count; x++)
		_book[x]->print();
	cout<<endl;
}

void GradeBook::remove(int i)
{
	cout<<"Removing grade with the ID: "<<i<<endl<<endl;
	if(_count == 0)
	{
		delete [] _book;
	}
	else
	{
		const Grade** temp = new const Grade* [_count-1];
		for(int x=0; x<i; x++)
			temp[x] = _book [x];
		for(int x=i; x<_count; x++)
			temp[x-1] = _book [x];
		delete _book[i-1];
		delete [] _book;
		_book = new const Grade* [_count-1];
		memcpy(_book, temp, (_count-1)*sizeof(Grade*));
		delete [] temp;
	}
	--_count;
}

GradeBook::GradeBook (const GradeBook& gb)
{
	_count = gb._count;
	Grade** temp = new Grade* [_count];
	for(int x=0; x<_count; x++)
		temp[x] = new Grade(*(gb._book[x]));
	_book = new const Grade* [_count];
	memcpy(_book, temp, _count*sizeof(Grade*));
	delete [] temp;
}

GradeBook::~GradeBook()
{
	for(int x=0; x<_count; x++)
		delete _book[x];

	delete [] _book;
} 