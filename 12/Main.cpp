// Nazwa pliku wykonywalnego: Geometria

// Uwaga ogolna:
// Przeciążenia przewidziane w zadaniu nie są tylko sztuką dla samej sztuki.
// Zaproponowane obiekty są np niezbędne w programowaniu grafiki przy użyciu DirectX.
// Tutaj przy okazji ilustrują tę ciekawą technikę programistyczną, jaką jest przeciążanie operatorów.

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy CPoint2D i CPoint2DArray, reprezentujace odpowiednio
// punkt na plaszczyznie (x,y) oraz tablice punktow, z odpowiednią funkcjonalnością
// którą należy wywnioskować z poniższezgo kodu (w niektórych przypadkach znajduje sie
// wyjaśniający komentarz)

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Geometria. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL

#include <iostream>
#include <math.h>
#include "Point2D.h"
#include "Point2DArray.h"
#include <time.h>

int main() {

  srand(time(NULL));

  std::cout << "*** POINTS ON THE PLANE ***"<< std::endl;

  CPoint2D point1(1.2, 0.5), point2(0.8, 0.5), point3;
  
  point3 = 0.5 + point1 + point2;
  point3.Print();
  
  std::cout << "*** ARRAY OF THE POINTS ***"<< std::endl;
  CPoint2DArray pointV1(5);
  CPoint2DArray pointV2(5);
  CPoint2DArray pointV3; // argument: wielkosc wektora
  CPoint2DArray pointV4(point3,5);               // argument: obiekt inicjalizacjalizujacy wszystkie wartosci, wielkosc wektora
  CPoint2DArray pointV5 = pointV4;

  pointV4.Print();
  pointV4.FillRand(0,100);                    // Przypisanie wartosci losowych z podanego przedzialu
  pointV4.Print();
  pointV5.Print();
  pointV5[1].Print();

  pointV1.FillRand(0,10);
  pointV2.FillRand(11,100);
  
  pointV1 = pointV1;

  pointV1.Print();
  pointV2.Print();

  pointV3 = pointV2 = pointV1;
  pointV2.Print();
  pointV3.Print();

  return 0;
}
/* Wynik dzialania programu (uwaga, w drugiej czesci zadania sa liczby losowe):

*** POINTS ON THE PLANE ***
Point:: (2.5,1)
*** ARRAY OF THE POINTS ***
Point array:: (2.5,1), (2.5,1), (2.5,1), (2.5,1), (2.5,1)
Point array:: (40,19), (97,78), (14,94), (22,5), (7,53)
Point array:: (2.5,1), (2.5,1), (2.5,1), (2.5,1), (2.5,1)
Point:: (2.5,1)
Point array:: (7,1), (0,1), (2,7), (0,4), (2,1)
Point array:: (61,53), (79,22), (87,35), (84,12), (60,65)
Point array:: (7,1), (0,1), (2,7), (0,4), (2,1)
Point array:: (7,1), (0,1), (2,7), (0,4), (2,1)

*/
