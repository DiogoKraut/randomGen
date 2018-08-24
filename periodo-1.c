/* Diogo Paris Kraut - GRR20166365 */

#include <stdio.h>
#include "lcrandom.h"

#define NUM 100000

int v[NUM];

int main() {
  int tam, i, j, periodo;
  i = j = periodo = tam =  0;
  // Inicializa gerador
	lcrandom_parms(40692, 127, 10000000);

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


}
