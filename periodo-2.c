/* Diogo Paris Kraut - GRR20166365 */

#include <stdio.h>
#include <stdlib.h>
#include "lcrandom.h"

#define NUM 1000000000

int main() {
  static int v[NUM];

  int tam, i, j, periodo;
  i = j = periodo = tam =  0;
  // Inicializa gerador
	lcrandom_parms(1103515245, 12345, 1073741824);

  while(i < NUM && !periodo) {
    v[i] = lcrandom();

    j = 0;
    while(j < tam && !periodo) {
      if(v[i] == v[j])
        periodo = i;
      j++;
    }
    tam++;
    i++;
  }
  printf("%i\n", periodo);

  return 0;
}
