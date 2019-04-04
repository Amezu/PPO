#include "qCPUcore.h"
#include "qGlobals.h"

///////////////////////////////////////////////////////////////////////////
void qCPU_alloc(const char* m_Name, int m_NqBit, int m_nExp, TqCPU* m_qCPU){

	m_qCPU->Name 	= m_Name;
	m_qCPU->NqBits 	= m_NqBit;
	m_qCPU->cpuWord = new TqBIT [m_NqBit];

	for(int i=0; i<m_NqBit; ++i)
		m_qCPU->cpuWord[i].NExp = m_nExp;

	// Set qBits states probabilities according to Gaussian distribution
	double mean = m_NqBit/2.;
	double sigma = m_NqBit/10.;
	qBitsProb_init(m_qCPU, mean, sigma);

	std::cout<< ">>> qCPU initialized with " << m_qCPU->NqBits << " qBits" << std::endl;
}

///////////////////////////////////////////////////////////////////////////
void qBitsProb_init(TqCPU* m_qCPU, double m_Mean, double m_Sigma){


  	std::random_device generator;
  	std::mt19937 mt(generator());
  	std::normal_distribution<double> distribution(m_Mean, m_Sigma);


  	int* p= (int*) malloc(m_qCPU->NqBits*sizeof(int));
  	int pmax=0;
  	for (int i=0; i<m_qCPU->NqBits; ++i) p[i] = 0;


	for (int i=0; i<NEXPERIMENTS; ++i) {
	    double number = distribution(mt);
	    if ((number>=0.0)&&(number<m_qCPU->NqBits)) ++p[int(number)];
	  }

  	for (int i=0; i<m_qCPU->NqBits; ++i) pmax = pmax > p[i] ? pmax : p[i];

	for (int i=0; i<m_qCPU->NqBits; ++i) {
		m_qCPU->cpuWord[i].upProb = (double)p[i]/pmax;
		m_qCPU->cpuWord[i].downProb = 1. - (double)p[i]/pmax;

	}

	free(p);

}

void Evaluate_qCPU_State(TqCPU* m_qCPU){
	std::cout << ">Evaluating the "<< m_qCPU->Name<<" state"<<std::endl;
  	std::random_device generator;
  	std::mt19937 mt(generator());

	std::uniform_real_distribution<> distribution(0.0, 1.0);

	for (int q=0; q<m_qCPU->NqBits; ++q) {
		m_qCPU->cpuWord[q].up = 0;
		m_qCPU->cpuWord[q].down = 0;
		
		for (int i=0; i<(m_qCPU->cpuWord[q].NExp); ++i) {
		// for (int i=0; i<10; ++i) {
		    double number = distribution(mt);
		    // modyfikacja stanu kubitu:
		    m_qCPU->cpuWord[q].up 	+= number*m_qCPU->cpuWord[q].upProb > 0.5 ? 1 : 0;  
		    m_qCPU->cpuWord[q].down += number*m_qCPU->cpuWord[q].downProb > 0.5 ? 1 : 0;  
	  	}
	}

}

void Print_qBit_State(TqBIT m_qBit){
	std::cout<< (m_qBit.up > m_qBit.down ? "/" : "\\");
}

void Print_qCPU_State(TqCPU m_qCPU){
	std::cout<< m_qCPU.Name << " CPU word ("<<m_qCPU.cpuWord->NExp << " experiments) : \t\t";
	for (int q=0; q<m_qCPU.NqBits; ++q) {
		Print_qBit_State(m_qCPU.cpuWord[q]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

void qCPU_delete(TqCPU* m_qCPU){
	delete [] m_qCPU->cpuWord;
}


