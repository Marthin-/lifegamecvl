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
	int taille_canne=6;
	int taille_filet=4;
	int tourMax=-2;
/*	if (argc==2){
		char *endptr;
		tourMax=(int) strtol(argv[1], &endptr, 10);
	}
	else {
		printf("Combien de tours voulez-vous ?\n");
		scanf("%i", &tourMax);
	}*/
	srand(time(NULL));
	obj * tab=malloc(n*n*sizeof(obj));
	int nbj=0;//nombre de joueurs
	while (nbj<1 || nbj>4){
		printf("combien de joueurs (max. 4) ?\n");
		scanf("%i",&nbj);
	}
	int * posPecheur=malloc(nbj*sizeof(int));
	remplir(tab, n, nbj, posPecheur);
	int * death=calloc(9, sizeof(int));
	int * deathDate=calloc(9, sizeof(int));
	int deathLength=0;

//------------------------------------------------------------------
	SDL_Init(SDL_INIT_VIDEO);
        SDL_WM_SetIcon(SDL_LoadBMP("./img/icone.bmp"), NULL);
	int taille_bmp=16;
	int taille_bordure=3;
	int taille_separation=0;
	int larg=400;//largeur de la colonne de droite
	int haut=0;//hautaur de la colonne du bas
	int width=taille_bmp*n+(n-1)*taille_separation+2*taille_bordure+larg;
	int height=taille_bmp*n+(n-1)*taille_separation+2*taille_bordure+haut;
        SDL_Surface *ecran=SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
        SDL_WM_SetCaption("Jeu de la vie", NULL);
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 60, 160, 208));  
	SDL_Flip(ecran);
	int isDev=0;//est développeur : détermine le type d'affichage (joueur ou développeur)
//--------------------------------------------------------------------

	int tour=0;
	//for (tour=0;tour<tourMax;tour++){
	while (tour!=tourMax+1){
		survie(tab, n, tour);
		checkDeath(tab, n, tour, death, &deathLength, deathDate);
		int i;
		for (i=0;i<nbj;i++){
			printsdl(ecran, tab, posPecheur+i, taille_canne, taille_filet, n, taille_bmp, taille_bordure, taille_separation, &tour, tourMax, &isDev);
			if (*(posPecheur+i)%n==n-1){
				SDL_Surface * victoire=SDL_LoadBMP("./img/menu/victoire.bmp");
				erase(ecran, taille_bmp, taille_bordure, taille_separation, n);
				SDL_Rect position;
				position.x=n*taille_bmp+(n-1)*taille_separation+2*taille_bordure+100;
				position.y=100;
				SDL_BlitSurface(victoire, NULL, ecran, &position);
				SDL_Flip(ecran);
				while (1){
					SDL_Event event;
					SDL_WaitEvent(&event);
					if (event.type==SDL_QUIT || event.type==SDL_KEYDOWN){
						SDL_Quit();
						free(death);
						free(tab);
						return EXIT_SUCCESS;
					}
				}
			}
		}
		reproduction(tab, n, tour);
		predation(tab, n, tour, posPecheur);
		deplacement(tab, n, tour);
		augTour(tab, n);
		tour++;
	}
	SDL_Quit();
	deathHistory(death, deathLength, deathDate);
	free(death);
	free(tab);
	return EXIT_SUCCESS;
}

