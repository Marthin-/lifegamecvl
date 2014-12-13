#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "obj.h"

int main(int argc, char **argv){
	printf("Combien de tours voulez-vous ?\n");
	int tourMax;
	scanf("%i", &tourMax);
	int n=20;
	srand(time(NULL));
	obj * tab=malloc(n*n*sizeof(obj));
	remplir(tab, n);
	int * death=calloc(9, sizeof(int));
	int * deathDate=calloc(9, sizeof(int));
	int deathLength=0;
	int tour;
	for (tour=0;tour<tourMax;tour++){
//		printf("---------------Tour %i---------------\n", tour);
//		afficher(tab, n);
//		printf("vvvvv Survie vvvvv\n");
		survie(tab, n, tour);
		checkDeath(tab, n, tour, death, &deathLength, deathDate);
//		afficher(tab, n);
//		printf("vvvvv Reproduction vvvvv\n");
		reproduction(tab, n, tour);
//		afficher(tab, n);
//		printf("vvvvv Predation vvvvv\n");
		predation(tab, n, tour);
//		afficher(tab, n);
//		printf("vvvvv Deplacement vvvvv\n");
		deplacement(tab, n, tour);
		augTour(tab, n);
	}
	afficher(tab, n);
	deathHistory(death, deathLength, deathDate);
	free(death);
	free(tab);
	return EXIT_SUCCESS;
}
