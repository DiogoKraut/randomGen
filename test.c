#include "lcrandom.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	unsigned long t;
	for(int i = 0; i < 1; i++) {
		t = lcrandom();
		printf("%lu\n", t);
	}

	printf("%lu", lcrandom_max());
	return 0;
}

