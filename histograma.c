#include "histograma.h"

void conta_rand(int *cont, int range) {
	int i;
	zera_vetor(cont, range);

	for(i = 0; i < range; i++)
		cont[lcrandom() % range]++;
}

void zera_vetor(int *v, int j) {
	int i;
	for(i = 0; i < j; i++)
		v[i] = 0;
}

void imprime_histograma(int *cont, int range) {
	int i, j;

	for(i = 0; i < range; i++) {
		printf("0: ")
	}
}