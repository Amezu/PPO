#include "Grade.h"
#include <iostream>

using namespace std;

int id=0;

Grade::Grade(double g)
{
	_value = g;
	_id = ++id;
}

void Grade::print() const
{
	cout<<"Grade ID="<<_id<<" value="<<_value<<endl;
}