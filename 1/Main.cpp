#include<iostream>
#include"Suma2.h"
#include"PolozeniePoczatkowe.h"
#include"Czas.h"
#include"Przyspieszenie.h"
#include"Predkosc.h"

int main ()
{
  using namespace std;
  
  cout<<"a = "<<Przyspieszenie()<<"\n";
  cout<<"v = "<<Predkosc()<<"\n";
  cout<<"r_0 = "<<PolozeniePoczatkowe()<<"\n";
  cout<<"t = "<<Czas()<<"\n";

  cout<<"r = a*t^2/2 + v*t + r_0 = "<<Suma2()<<"\n";

  return 0;
}
