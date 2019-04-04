#pragma once

#include <iostream>
#include <random>

extern int NEXPERIMENTS;

struct TqBIT;
struct TqCPU;

struct TqCPU{
	const char* Name;
	int NqBits;
	TqBIT* cpuWord;
};

struct TqBIT {
	int up;				// state up counter
	int down;			// state down counter
	double upProb;		// probability of state up
	double downProb;	// probability of state down
	int NExp; 			// number of experiments
};

///////////////////////////////////////////////////////////////////////////
void qCPU_alloc(const char* m_Name, int m_NqBit, int m_nExp, TqCPU* m_qCPU);

///////////////////////////////////////////////////////////////////////////
void qCPU_delete(TqCPU* m_qCPU);

///////////////////////////////////////////////////////////////////////////
void qBitsProb_init(TqCPU* m_qCPU, double m_Mean, double m_Sigma);

///////////////////////////////////////////////////////////////////////////
void Evaluate_qCPU_State(TqCPU* m_qCPU);

///////////////////////////////////////////////////////////////////////////
void Print_qBit_State(TqBIT m_qBit);

///////////////////////////////////////////////////////////////////////////
void Print_qCPU_State(TqCPU m_qCPU);