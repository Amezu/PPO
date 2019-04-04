#include "qCPUinterface.h"
#include "qCPUcore.h"
#include "qGlobals.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method, const char* m_qName, int m_NqBit, int m_nExp){
	
	if ( !strcmp(m_Method,"Add") )     	  PARAMETER = 1;
	if ( !strcmp(m_Method,"Redefine") )   PARAMETER = 2;

	// Pseudokod:
	// W zaleznosci od wybranej, metody wykonaj operacje:
	// m_Method = "Add" : dodaj kolejny qCPU do obiektu (TqCPU*)MACHINE:
	//						 jesli pierwsze qCPU : wywolaj : qCPU_alloc()
	//                       kolejne : wywolaj : AddCPU()
	// m_Method = "Redefine" : wydrukuj tylko komunikat

	// Wydrukuj komunikat dla nieznanej m_Method

	// Uwaga: wykorzystaj: switch, new, cout, endl
	std::cout<<std::endl;
	switch (PARAMETER)
	{
		case 1:
			if(NCPU==0)
			{
				std::cout<<">>> qInterface:: adding first qCPU\n";
				MACHINE = new TqCPU[1];
				qCPU_alloc(m_qName, m_NqBit, m_nExp, MACHINE);
			}
			else
			{
				std::cout<<">>> qInterface:: adding new qCPU\n";
				AddCPU(m_qName, m_NqBit, m_nExp);
			}
			NCPU++;
			break;
		default:
			std::cout<<">>> qInterface::Unknown method, use one of the following:\n> 'Add' add new CPU to the Machine\n> 'Redefine' redefine the existing CPU in the Machine";
			std::cout<<std::endl;
			break;
	}
}

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method){

	PARAMETER = 0;
	if ( !strcmp(m_Method,"Release") ) PARAMETER = 1;
	if ( !strcmp(m_Method,"Evaluate") ) PARAMETER = 2;
	if ( !strcmp(m_Method,"Print") )   PARAMETER = 3;

	// Pseudokod:
	// W zaleznosci od wybranej metody wykonaj operacje:
	// m_Method = "Release" : zwolnij wczesniej zaalokowana pamiec na kazdy qCPU
	// m_Method = "Evaluate" : wykonaj Evaluate_qCPU_State() dla calej MACHINE
	// m_Method = "Print" : wykonaj Print_qCPU_State() dla calej MACHINE

	// Wydrukuj komunikat dla nieznanej m_Method		

	std::cout<<std::endl;
	switch (PARAMETER)
	{
		case 1:
			for(int x=0; x<NCPU; x++)
				delete[] MACHINE[x].cpuWord;
			delete[] MACHINE;
			NCPU=0;
			break;
		case 2:
			for(int x=0; x<NCPU; x++)
				Evaluate_qCPU_State(MACHINE+x);
			break;
		case 3:
			for(int x=0; x<NCPU; x++)
				Print_qCPU_State(MACHINE[x]);
			break;
		default:
			std::cout<<"qInterface::Unknown method, use one of the following:\n>'Evaluate' evaluate the Machine state\n>'Print' printing the Machine state\n>'Release' destroy the Machine";
			std::cout<<std::endl;
			break;
	}}

///////////////////////////////////////////////////////////////////////////
void AddCPU(const char* m_qName, int m_NqBit, int m_nExp){

	// Pseudokod:
	// Zwieksz dynamicznie tablice MACHINE, dodajac koleny qCPU
	// Wskazowka: dla nowego qCPU wykonaj qCPU_alloc()
	
	TqCPU* temp = new TqCPU[NCPU];
	memcpy(temp, MACHINE, NCPU*sizeof(TqCPU));
	delete[] MACHINE;	
	MACHINE = new TqCPU[NCPU+1];
	memcpy(MACHINE, temp, NCPU*sizeof(TqCPU));
	delete[] temp;
	temp=NULL;

	qCPU_alloc(m_qName, m_NqBit, m_nExp, MACHINE+NCPU);
}
