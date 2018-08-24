#include "lcrandom.h"

unsigned long Ag = 40692;
unsigned long Cg = 127;
unsigned long Mg = 10000000;

static unsigned long x = 0;

void lcrandom_seed (unsigned long s) {
	x = s;
}

unsigned long lcrandom() {
	x = (Ag * x + Cg) % Mg; // Xi+1 = (A x Xi + C) mod M

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
