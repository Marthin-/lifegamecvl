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
	for (tour=0;tour<50;tour++){
		printf("---------------Tour %i---------------\n", tour);
		afficher(tab, n);
		printf("vvvvv Survie vvvvv\n");
		survie(tab, n, tour);
		afficher(tab, n);
		printf("vvvvv Reproduction vvvvv\n");
		reproduction(tab, n, tour);
		afficher(tab, n);
		printf("vvvvv Predation vvvvv\n");
		predation(tab, n, tour);
		afficher(tab, n);
		printf("vvvvv Deplacement vvvvv\n");
		deplacement(tab, n, tour);
		augTour(tab, n);
	}
	afficher(tab, n);
	free(tab);
	return 0;
}
