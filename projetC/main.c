#include <stdio.h>
#include <stdlib.h>//malloc, calloc, strtol
#include <time.h>//rand
#include "affichage.h"
#include "constantes.h"
#include "obj.h"
#include "regles_de_vie.h"
#include "remplir.h"
#include "./usr/include/SDL/SDL.h"

int main(int argc, char **argv){
	int n=50;
	int posPecheur=0;
	int * adrpos=&posPecheur;
	int dir=16;
	int * adrdir=&dir;
	int taille_canne=3;
	int tourMax;
	if (argc==2){
		char *endptr;
		tourMax=(int) strtol(argv[1], &endptr, 10);
	}
	else {
		printf("Combien de tours voulez-vous ?\n");
		scanf("%i", &tourMax);
	}
	srand(time(NULL));
	obj * tab=malloc(n*n*sizeof(obj));
	int nbj=1;//nombre de joueurs
/*	while (nbj<1 || nbj>4){
		printf("combien de joueurs (max. 4) ?\n");
		scanf("%i",&nbj);
	}*/
	remplir(tab, n, nbj);
	int * death=calloc(9, sizeof(int));
	int * deathDate=calloc(9, sizeof(int));
	int deathLength=0;

//------------------------------------------------------------------
	SDL_Init(SDL_INIT_VIDEO);
//        SDL_WM_SetIcon(SDL_LoadBMP("ico.bmp"), NULL);
	int taille_bmp=16;
	int taille_bordure=3;
	int taille_separation=0;
	int larg=100;//largeur de la colonne de droite
	int haut=50;//hautaur de la colonne du bas
	int width=taille_bmp*n+(n-1)*taille_separation+2*taille_bordure+larg;
	int height=taille_bmp*n+(n-1)*taille_separation+2*taille_bordure+haut;
//	printf("width : %i\nheight : %i\n", width, height);//pixels
        SDL_Surface *ecran=SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
        SDL_WM_SetCaption("Jeu de la vie", NULL);
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));  
	SDL_Flip(ecran);
	int isDev=0;//est développeur : détermine le type d'affichage (joueur ou développeur)
//--------------------------------------------------------------------

	int tour;
	for (tour=0;tour<tourMax;tour++){
		survie(tab, n, tour);
		checkDeath(tab, n, tour, death, &deathLength, deathDate);
		printsdl(ecran, tab, adrpos, adrdir, taille_canne, n, taille_bmp, taille_bordure, taille_separation, &tour, tourMax, &isDev);
//		afficher(tab, n, tour);
//		getchar();
		reproduction(tab, n, tour);
		predation(tab, n, tour);
		deplacement(tab, n, tour);
		augTour(tab, n);
	}
//	afficher(tab, n, tour);
	SDL_Quit();
	deathHistory(death, deathLength, deathDate);
	free(death);
	free(tab);
	return EXIT_SUCCESS;
}

