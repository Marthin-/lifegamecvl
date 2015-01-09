#include <stdio.h>
#include <stdlib.h>//malloc, calloc, strtol
#include <time.h>//rand
//#include <unistd.h>//usleep
#include "affichage.h"
#include "constantes.h"
#include "obj.h"
#include "regles_de_vie.h"
#include "remplir.h"
//#include "./usr/include/SDL/SDL.h"

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
	int n=60;
	srand(time(NULL));
	obj * tab=malloc(n*n*sizeof(obj));
	int nbj=0;//nombre de joueurs
	remplir(tab, n, nbj);
	int * death=calloc(9, sizeof(int));
	int * deathDate=calloc(9, sizeof(int));
	int deathLength=0;
/*
//------------------------------------------------------------------
	SDL_Init(SDL_INIT_VIDEO);
//        SDL_WM_SetIcon(SDL_LoadBMP("ico.bmp"), NULL);
	int taille_bmp=48;
	int taille_bordure=3;
	int taille_separation=1;
	int larg=100;//largeur de la colone de droite
	int haut=50;
        SDL_Surface *ecran=SDL_SetVideoMode(taille_bmp*n+(n-1)*taille_separation+2*taille_bordure+larg, taille_bmp*n+(n-1)*taille_separation+2*taille_bordure+haut, 32, SDL_HWSURFACE);
        SDL_WM_SetCaption("Jeu de la vie", NULL);
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));  
//	SDL_Flip(ecran);
//--------------------------------------------------------------------
*/
	int tour;
	for (tour=0;tour<tourMax;tour++){
		survie(tab, n, tour);
		checkDeath(tab, n, tour, death, &deathLength, deathDate);
		afficher(tab, n, tour);
//		printsdl();
		getchar();
		reproduction(tab, n, tour);
		predation(tab, n, tour);
		deplacement(tab, n, tour);
		augTour(tab, n);
	}
	afficher(tab, n, tour);
	deathHistory(death, deathLength, deathDate);
	free(death);
	free(tab);
	return EXIT_SUCCESS;
}

