#ifndef QCPUINTERFACE_H
#define QCPUINTERFACE_H

#include <string.h>

#include "qCPUcore.h"
#include "qGlobals.h"
#include <stdlib.h> /* srand, rand */
#include <time.h>	/* time */

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method, const char* m_qName, int m_NqBit, int m_nExp);

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method);

///////////////////////////////////////////////////////////////////////////
void AddCPU(const char* m_qName, int m_NqBit, int m_nExp);

//przypisuje NExp nowe wartości (1-1000) 
void GenerateNRandExp(TqCPU **m_Cpu);

//wypełnianie tablicy wskaźnikami na TqCPU
void GetPointers(TqCPU** m_AllCPU);

//drukuje nazwy wszystkich qCPU trzymanych w tablicy
int PrintNames(TqCPU* m_AllCPU[]);

//drukowanie na ekran wartosci Name obiektu TqCPU
void PrintCPUName(TqCPU* m_qCPU);

//zamiana miejscami 2 komputerów
void SwapCPU(TqCPU* &m_qCPU1, TqCPU* &m_qCPU2);

#endif



