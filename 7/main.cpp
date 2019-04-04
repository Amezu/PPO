// Nazwa pliku wykonywalnego: qCPU

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl abalogiczny jak podany na końcu tego
// pliku.

// !!! UWAGA !!!
// Przy wykonaniu tego zadania prosze wykorzystac
// switch, for, extern, cout
// 1. Prosze utworzyc odpowiednie pliki qGlobals.h(cpp) gdzie beda
//    odpowiednio zdefiniowane zmienne globalne, widoczne dla
//    calego programu, chodzi o zmienne:
//    (int)PARAMETER, (int)NCPU, (TqCPU*)MACHINE
// 2. Prosze naprawic (uzupelnic kod) kwestie kompilacji warunkowej
// 3. Prosze naprawic (uzupelnic kod) kwestie deklaracji wyprzedzajacej
//    w pliku qCPUcore.h przy definicji struct TqCPU
// 4. Prosze uzupenic ciala funkcji zadeklarowanych w pliku 
//    qCPUiterface.h (odpowiedni pseudokod jest umieszczony w kodzie
//    zrodlowym tychze funkcji)

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia, zwlaszcza na
// zwolnienie pamieci na koniec programu.

// Pliku main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie qCPU. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include "qCPUinterface.h"

// Main function
int main ()
{
  std::cout<< ">>> (pseudo)Quantum Computing <<< " << std::endl;

  qInterface("Define", "qCPU4", 4, 100);
  qInterface("Add", "qCPU16_1", 16, 1);
  qInterface("Add", "qCPU16_2", 16, 1000);

  qInterface("Compute");
  qInterface("Evaluate");
  qInterface("Print");
  qInterface("Release");

  return 0;
}
/* wynik dzialania programu:

brachwal@local$ ./qCPU
>>> (pseudo)Quantum Computing <<< 

>>> qInterface::Unknown method, use one of the following:
> 'Add' add new CPU to the Machine
> 'Redefine' redefine the existing CPU in the Machine

>>> qInterface:: adding first qCPU
>>> qCPU initialized with 16 qBits
>>> qInterface:: adding new qCPU
>>> qCPU initialized with 16 qBits

qInterface::Unknown method, use one of the following:
>'Evaluate' evaluate the Machine state
>'Print' printing the Machine state
>'Release' destroy the Machine


>>> qInterface::Machine state evaluation 
>Evaluating the qCPU16_1 state
>Evaluating the qCPU16_2 state

>>> qInterface:: Printing the Machine state 
qCPU16_1 CPU word (1 experiments) :     \ \ \ \ \ \ \ \ / \ \ \ \ \ \ \ 
qCPU16_2 CPU word (1000 experiments) :    \ \ \ \ \ \ / / / / \ \ \ \ \ 

*/
