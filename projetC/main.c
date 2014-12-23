#include <stdio.h>
#include <stdlib.h>//malloc, calloc, strtol
#include <time.h>//rand
//#include <unistd.h>//usleep
#include "affichage.h"
#include "constantes.h"
#include "obj.h"
#include "regles_de_vie.h"
#include "remplir.h"

int main(int argc, char **argv){
	int tourMax;
	if (argc==2){
		char *endptr;
		tourMax=(int) strtol(argv[1], &endptr, 10);
	}
	else {
		printf("Combien de tours voulez-vous ?\n");
		scanf("%i", &tourMax);
	}
	int n=20;
	srand(time(NULL));
	obj * tab=malloc(n*n*sizeof(obj));
	remplir(tab, n);
	int * death=calloc(9, sizeof(int));
	int * deathDate=calloc(9, sizeof(int));
	int deathLength=0;
	int tour;
	for (tour=0;tour<tourMax;tour++){
		survie(tab, n, tour);
		checkDeath(tab, n, tour, death, &deathLength, deathDate);
//		afficher(tab, n);
		afficher2(tab, n, tour);
//		usleep(200000);
		getchar();
		reproduction(tab, n, tour);
		predation(tab, n, tour);
		deplacement(tab, n, tour);
		augTour(tab, n);
	}
//	afficher(tab, n);
	afficher2(tab, n, tour);
	deathHistory(death, deathLength, deathDate);
	free(death);
	free(tab);
	return EXIT_SUCCESS;
}
