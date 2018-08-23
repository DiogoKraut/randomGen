#include "lcrandom.h"

// Parametros goblais (default)
unsigned long Ag = 40692;
unsigned long Cg = 127;
unsigned long Mg = 10000000;

unsigned long seed = 0;

void lcrandom_seed (unsigned long s) {
	seed = s;
}

unsigned long lcrandom() {
	unsigned long x = 0;

	x = (Ag * seed + Cg) % Mg; // Xi+1 = (A x Xi + C) mod M
	lcrandom_seed(x); // Valor atual eh semente da proxima iteracao
	
	return x;
}

void lcrandom_parms(unsigned long A, unsigned long C, unsigned long M) {
	Ag = A;
	Cg = C;
	Mg = M;
}

unsigned long lcrandom_max() {
	return (Mg - 1);
}