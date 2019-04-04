// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac funkcje wykonujace operacje na tablicach
// reprezentujacych liste studentow.

// W tablicy "namesList" przechowywane sa pierwsze i drugie imie
// studenta oddzielone jedna spacja.

// W tablicy "surnamesList" przechowywane sa nazwiska studentow.

// W tablicy "yearsList" przechowywane sa lata na ktorych studiuja
// studenci.

// UWAGA
// Tablice powinny dostosowywac sie do liczby elementow, ktore maja byc w
// nich przechowywane.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

// Pliku Lab06.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab06. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Lab06.cpp) nalezy wgrac
// do UPEL po uprzednim spakowaniu do archiwum: Lab06.tar.gz

#include "Lab06.h"

int main ()
{
  int numberOfStudents = 0;
  char** namesList = NULL;
  char** surnamesList = NULL;
  int* yearsList = NULL;

  AddStudent(&numberOfStudents, &namesList, &surnamesList, &yearsList, "Chuck", "Jozef", "Norris", 7);
  AddStudent(&numberOfStudents, &namesList, &surnamesList, &yearsList, "John", "Wieslaw", "Rambo", 3);
  AddStudent(&numberOfStudents, &namesList, &surnamesList, &yearsList, "Johny", "Eugeniusz", "Bravo", 1);

  std::cout<<"Only names:\n";
  PrintListContent (numberOfStudents, namesList);

  std::cout<<"\nOnly surnames:\n";
  PrintListContent (numberOfStudents, surnamesList);

  std::cout<<"\nOnly years:\n";
  PrintListContent (numberOfStudents, yearsList);

  std::cout<<"\nEverything full:\n";
  PrintListContent (numberOfStudents, namesList, surnamesList, yearsList);

  const int studentToDeleteID = 2;
  DeleteStudent(&numberOfStudents, &namesList, &surnamesList, &yearsList, studentToDeleteID);

  std::cout<<"\nEverything after delete:\n";
  PrintListContent (numberOfStudents, namesList, surnamesList, yearsList);

  const int studentToRenameID = 1;
  RenameStudent(&namesList, "Chuck", "Karol", studentToRenameID);

  std::cout<<"\nEverything after rename:\n";
  PrintListContent (numberOfStudents, namesList, surnamesList, yearsList);

  ClearStudents (&numberOfStudents, &namesList, &surnamesList, &yearsList);

  return 0;
}

/* wynik dzialania programu, ./Lab06
Only names:
Chuck Jozef
John Wieslaw
Johny Eugeniusz

Only surnames:
Norris
Rambo
Bravo

Only years:
7
3
1

Everything full:
Norris, Chuck Jozef - year 7
Rambo, John Wieslaw - year 3
Bravo, Johny Eugeniusz - year 1

Everything after delete:
Norris, Chuck Jozef - year 7
Bravo, Johny Eugeniusz - year 1

Everything after rename:
Norris, Chuck Karol - year 7
Bravo, Johny Eugeniusz - year 1
*/
