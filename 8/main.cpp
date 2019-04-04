// Nazwa pliku wykonywalnego: qCPU

// Prosze dopisac kod, dopisac nowe funkcje, tak aby program wykonywal
// sie, a wynik jego dzialania byl abalogiczny jak podany na końcu tego
// pliku.
//
// !!! UWAGA !!!
//    W ostatecznej wersji, funkcja main nie powinna byc zmodyfikowana
//
//    Prosze dopisac do qCPUinterface odpowiednie funkcje (tak jak to
//    wynika z funkcji main), ktorych dzialanie jest nastepujace:
//
//    GetPointers() - wypelnianie tablicy, odpowiednimi wartosciami
//                    (tablica wskaznikow na obiekt TqCPU).
//                    Uwaga: wartosci do jej wypelnienia prosze wziac
//                           z globalnej tablicy MACHINE
//
//    SwapCPU() - zamiana miejscami dwoch wskaznikow
//
//	  PrintNames() - drukuje nazwy wszystkich qCPU trzymanych w tablicy		
//
//    PrintCPUName() - drukowanie na ekran wartosci Name obiektu TqCPU
//
//    GenerateNRandExp() - przypisanie nowej wartosci dla zmiennej NExp 
//						   zerowego qBitu: TqCPU.cpuWord[0].NExp
//						   Uwaga: nowa wartosc powinna byc losowana z przedzialu
//                      od 1 do 1000; szkielet tej funkcji jest juz
//                      zawarty w qCPUinterface.h(cpp)
//
// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie qCPU. Program nalezy kompilowac z flagami -Wall -g.
//
// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)
//
// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.
//
// Rozwiazanie (czyli spakowane archiwum plikow programu) nalezy wgrac
// do UPEL

#include "qCPUinterface.h"

// Main function
int main ()
{
  std::cout<< ">>> (pseudo)Quantum Computing <<< " << std::endl;


  qInterface("Define", "qCPU16_1", 16, 1);
  qInterface("Define", "qCPU16_2", 16, 1);
  qInterface("Define", "qCPU16_3", 16, 1);


  void (*qOperation)(TqCPU **m_MACHINE);
  int (*qPrint)(TqCPU *m_MACHINE[]);

  TqCPU *MyAllCPU[NCPU];

  qOperation = GetPointers;
  qOperation(MyAllCPU);
  
  qPrint = PrintNames;

  std::cout << "The CPU names before swapping:" << std::endl;
  
  if(qPrint(&MyAllCPU[0]))
    SwapCPU(MyAllCPU[0],MyAllCPU[2]);
  
  std::cout << "The CPU names after swapping:" << std::endl;
  qPrint(MyAllCPU);

  PrintCPUName( &MACHINE[2]-1 );
  PrintCPUName( MACHINE+1 );

  qOperation = GenerateNRandExp;
  qOperation(MyAllCPU);

  qInterface("Compute");
  qInterface("Print");

  qInterface("Release");

  return 0;
}

/* Wynik dzialania programu */
/*
brachwal@local$ ./qCPU
>>> (pseudo)Quantum Computing <<< 
The CPU names before swapping:
0 qCPU16_1
1 qCPU16_2
2 qCPU16_3
The CPU names after swapping:
0 qCPU16_3
1 qCPU16_2
2 qCPU16_1
CPU Name :: qCPU16_2
CPU Name :: qCPU16_2
qCPU16_1 CPU word (41 experiments) :      \ \ \ \ \ \ / \ \ \ \ \ \ \ \ \ 
qCPU16_2 CPU word (218 experiments) :     \ \ \ \ \ \ \ \ / \ \ \ \ \ \ \ 
qCPU16_3 CPU word (969 experiments) :     \ \ \ \ \ \ / \ / \ \ \ \ \ \ \
*/
