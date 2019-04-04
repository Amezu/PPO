// Nazwa pliku wykonywalnego: StudentGrades

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy CWymierne, CZespolone, CZespoloneTab reprezentujace 
// odpowiednio liczby wymierne (licznik/mianownik) oraz zespolone (Re, Im).
// Klasa CZespolone przchowojue tablice liczb CZespolone, ktorej konstruktor
// alokuje odpowienia ilosc pamieci. Uwaga, nalezy tutaj przeladowac operator []

// UWAGA!!!
// W zadaniu trzeba wykorzystac zarowno konstruktory jak i operotory
// konwertujace

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Liczby. Program nalezy kompilowac z flagami -Wall -g.

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
#include <cmath>
#include "Wymierne.h"
#include "Zespolone.h"

int main() {

  std::cout << "*** WYMIERNE ***"<< std::endl;
  
  CWymierne Raz(1, 2), Dwa(2, 3);
  Raz.Print();
  Dwa.Print();

  CWymierne Wynik1 = Pomnoz(Raz, Dwa);
  Wynik1.Print();


  CWymierne Wynik2 = Pomnoz(Raz, 5);
  Wynik2.Print();

  CWymierne Wynik3 = Pomnoz(10, 5);
  Wynik3.Print();

  float Wynik8 = std::sqrt(Wynik3);
  std::cout<< Wynik8 << std::endl;

  std::cout << "*** ZESPOLONE ***"<< std::endl;
  CZespoloneTab zTab(4);

  zTab[0] = Dodaj(CZespolone(1, 5), 4);                
  zTab[0].Print();

  zTab[1] = Dodaj(CZespolone(1, 5), Dwa);              
  zTab[1].Print();

  zTab[2] = Dodaj(CWymierne(10, 3), CWymierne(1, 3));  
  zTab[2].Print();
  
  zTab[3] = Dodaj(1, 2);                               
  zTab[3].Print();

  



  return 0;
}
/** Wynik dzialania programu:

*** WYMIERNE ***
1/2
2/3
2/6
5/2
50
7.07107
*** ZESPOLONE ***
(5,5)
(1.66667,5)
(3.66667,0)
(3,0)

*/
