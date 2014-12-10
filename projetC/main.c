#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "obj.h"

int main(int argc, char **argv){
	int n=5;
	srand(time(NULL));
	obj * tab=malloc(n*n*sizeof(obj));
	remplir(tab, n);
	int tour;
	for (tour=0;tour<100;tour++){
		afficher(tab, n);
		survie(tab, n, tour);
		afficher(tab, n);
		reproduction(tab, n, tour);
		afficher(tab, n);
		predation(tab, n, tour);
//		deplacement(tab, n);
//		tour();
	}
	afficher(tab, n);
	free(tab);
	return 0;
}
