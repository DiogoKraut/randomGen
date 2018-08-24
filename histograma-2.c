#include <stdio.h>
#include <math.h>
#include "lcrandom.h"

#define TO_GEN 1000000
#define NUM 100

int main() {
	int i, j, max, min, cont[NUM];

	// Inicializa gerador
	lcrandom_parms(1103515245, 12345, 1073741824);

	// Zera vetor
	for(i = 0; i < NUM; i++)
		cont[i] = 0;

	for(i = 0; i < TO_GEN; i++)
		cont[lcrandom() % 100]++;

	// Econtrar min e max de cont para normalizar
	max = min = cont[0];
	for(i = 1; i < NUM; i++) {
		if(max < cont[i])
		max = cont[i];
		if(min > cont[i])
		min = cont[i];
	}

	// Normaliza ( X' = a + ((X - Xmin)(b - a)) / (Xmax - Xmin) )
	// https://en.wikipedia.org/wiki/Feature_scaling
	int dif = max - min;
	for(i = 0; i < NUM; i++)
		cont[i] = round(((cont[i] - min) * 100) / dif);

	// Gera histograma
	printf("   0   10   20   30   40   50   60   70   80   90   100\n");
	printf("   +----+----+----+----+----+----+----+----+----+----+\n");

	for(i = 0; i < NUM; i++) {
		printf("%02i |", i);
		for(j = cont[i]; j > 1; j--)
			if(j % 2) // Cada * vale 2
				printf("*");
		printf("\n");
	}

	printf("   +----+----+----+----+----+----+----+----+----+----+\n");
}
