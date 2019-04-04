#include "qCPUinterface.h"

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method, const char* m_qName, int m_NqBit, int m_nExp){
	
	if ( !strcmp(m_Method,"Define") )     PARAMETER = 1;

	// Uwaga: wykorzystaj: switch, new, cout, endl

	switch (PARAMETER){
		case 1:
			if(MACHINE){
				AddCPU(m_qName, m_NqBit, m_nExp);
			}
			else{
				++NCPU;
				MACHINE = new TqCPU [NCPU];
				qCPU_alloc(m_qName, m_NqBit, m_nExp, &MACHINE[0]);
			}
			break;

		default:
			std::cout << std::endl << ">>> qInterface::Unknown method, use one of the following:";
			std::cout << "\n> 'Define' add new CPU to the Machine" << std::endl;
			break;
	}
}

///////////////////////////////////////////////////////////////////////////
void qInterface(const char* m_Method){

	PARAMETER = 0;
	if ( !strcmp(m_Method,"Release") ) PARAMETER = 1;
	if ( !strcmp(m_Method,"Compute") ) PARAMETER = 2;
	if ( !strcmp(m_Method,"Print") )   PARAMETER = 3;

	switch (PARAMETER){
		case 1:
			for(int i=0; i<NCPU; ++i){
				qCPU_delete(&MACHINE[i]);
			}
			delete [] MACHINE;
			break;
		case 2:
			// std::cout << std::endl << ">>> qInterface::Machine state evaluation "<< std::endl;
			for(int i=0; i<NCPU; ++i)
				Evaluate_qCPU_State(&MACHINE[i]);
			break;
		case 3:
			// std::cout << std::endl << ">>> qInterface:: Printing the Machine state "<< std::endl;
			for(int i=0; i<NCPU; ++i)
				Print_qCPU_State(MACHINE[i]);
			break;

		default:
			std::cout << std::endl << "qInterface::Unknown method, use one of the following:";
			std::cout << "\n>'Compute' evaluate the Machine state";
			std::cout << "\n>'Print' printing the Machine state";
			std::cout << "\n>'Release' destroy the Machine" << std::endl << std::endl;
			break;
		}
			

}

///////////////////////////////////////////////////////////////////////////
void AddCPU(const char* m_qName, int m_NqBit, int m_nExp){

	
	TqCPU* qCPUtemp = MACHINE;
	MACHINE = new TqCPU [++NCPU];

	for(int i=0; i<NCPU-1; ++i){
		MACHINE[i] = qCPUtemp[i];
	}

	qCPU_alloc(m_qName, m_NqBit, m_nExp, &MACHINE[NCPU-1]);
	delete [] qCPUtemp;
}


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void GenerateNRandExp(TqCPU **m_Cpu){
	srand (time(NULL));

	for(int x=0; x<NCPU; x++)
		//podstawia pod NExp liczbę 1-1000
		m_Cpu[x]->cpuWord[0].NExp=rand()%1000 + 1;
}

void GetPointers(TqCPU** m_AllCPU)
{
	for(int x=0; x<NCPU; x++)
		//podstawia adres elementu MACHINE pod odpowiedni element tablicy wskąźników
		m_AllCPU[x]=&MACHINE[x];
}

int PrintNames(TqCPU* m_AllCPU[])
{
	for(int x=0; x<NCPU; x++)
	{
		//drukuje indeks tablicy
		std::cout<<x<<" ";
		//drukuje nazwę qCPU pod tym indeksem
		std::cout<<m_AllCPU[x]->Name<<std::endl;
	}

	return 1;
}

void PrintCPUName(TqCPU* m_qCPU)
{
	//drukuje nazwę qCPU
	std::cout<<"CPU Name :: "<<m_qCPU->Name<<std::endl;
}

void SwapCPU(TqCPU* &m_qCPU1, TqCPU* &m_qCPU2)
{
	//tworzy TqCPU tymczasowy
	TqCPU* temp = m_qCPU1;

	//zamienia wartości obiektów pod wskaźnikami
	m_qCPU1=m_qCPU2;
	m_qCPU2=temp;
}