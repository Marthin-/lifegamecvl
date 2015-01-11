#include <stdio.h>
#include "affichage.h"

#define esc 27
void clearScreen (){
        printf("%c[2J%c[H" , esc , esc);
}

void afficher(obj *tab, int n, int tour){
        int k;
        clearScreen();
        for (k=0;k<n*n;k++){
		char sym;
		if ((tab+k)->type==0)
			sym='~';
		else if ((tab+k)->type==1)
			sym='.';
		else if ((tab+k)->type==2)
			sym='%';
		else if ((tab+k)->type==3)
			sym='b';
		else if ((tab+k)->type==4)
			sym='T';
		else if ((tab+k)->type==5)
			sym='&';
		else if ((tab+k)->type==6)
			sym='p';
		else if ((tab+k)->type==7)
			sym='R';
		else if ((tab+k)->type==8)
			sym='O';
		else if ((tab+k)->type==9)
			sym='B';
		else if ((tab+k)->type==10)
			sym='@';
		else if ((tab+k)->type==11)
			sym='H';
		else if ((tab+k)->type==12)
			sym='X';
		else
			sym='?';//erreur
                printf("%c ", sym);
		if (k==n*n-1)
                        printf("  Tour %i", tour);
                if (k%n==n-1)
                        printf("\n");
        }
        printf("\n");
}

void afficher2(obj *tab, int n, int tour){
        int k;
	clearScreen();
        for (k=0;k<n*n;k++){
                printf("%i ", (tab+k)->type);
		if (k==n*n-1)
			printf("  Tour %i", tour);
                if (k%n==n-1)
                        printf("\n");
        }
        printf("\n");
}

void afficher_bordure(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n){
	SDL_Rect position;
        position.x=0;
        position.y=0;
	int bord=2*taille_bordure+n*taille_bmp+(n-1)*taille_separation;
	SDL_Surface *bordure_verticale=SDL_CreateRGBSurface(SDL_HWSURFACE, taille_bordure, bord, 32, 0, 0, 0, 0);
        SDL_FillRect(bordure_verticale, NULL, SDL_MapRGB(bordure_verticale->format, 0, 0, 0));
	SDL_Surface *bordure_horizontale=SDL_CreateRGBSurface(SDL_HWSURFACE, bord, taille_bordure, 32, 0, 0, 0, 0);
        SDL_FillRect(bordure_horizontale, NULL, SDL_MapRGB(bordure_horizontale->format, 0, 0, 0));
	SDL_BlitSurface(bordure_verticale, NULL, ecran, &position);
	SDL_BlitSurface(bordure_horizontale, NULL, ecran, &position);
	position.x=bord-2*taille_bordure;
	SDL_BlitSurface(bordure_verticale, NULL, ecran, &position);
        position.y=position.x;
        position.x=0;
	SDL_BlitSurface(bordure_horizontale, NULL, ecran, &position);
}

void afficher_separation(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n){
        SDL_Rect position;
        position.x=taille_bordure+taille_bmp;
        position.y=taille_bordure;
	int bord=n*taille_bmp+(n-1)*taille_separation;
	SDL_Surface *separation_verticale=SDL_CreateRGBSurface(SDL_HWSURFACE, taille_separation, bord, 32, 0, 0, 0, 0);
        SDL_FillRect(separation_verticale, NULL, SDL_MapRGB(separation_verticale->format, 0, 0, 0));
	SDL_Surface *separation_horizontale=SDL_CreateRGBSurface(SDL_HWSURFACE, bord, taille_separation, 32, 0, 0, 0, 0);
        SDL_FillRect(separation_horizontale, NULL, SDL_MapRGB(separation_horizontale->format, 0, 0, 0));
	int k;
	for (k=0;k<n-1;k++){
		SDL_BlitSurface(separation_verticale, NULL, ecran, &position);
		position.x+=taille_bmp;
	}
	position.x=taille_bordure;
	position.y=taille_bordure+taille_bmp;
	for (k=0;k<n-1;k++){
		SDL_BlitSurface(separation_horizontale, NULL, ecran, &position);
                position.y+=taille_bmp;
	}
}

void afficher_grille(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n){
	afficher_bordure(ecran, taille_bordure, taille_bmp, taille_separation, n);
	afficher_separation(ecran, taille_bordure, taille_bmp, taille_separation, n);
}

void remplir_grillej(){
/*	int k;
	for (k=0;k<n*n;k++){
		
	}*/
}

void printMapj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
	afficher_grille(ecran, taille_bordure, taille_bmp, taille_separation, n);
	remplir_grillej();
}

void choixPecheur(){

}

void printj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
	printMapj(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
	choixPecheur();
}

void remplir_grilled(){

}

void printMapd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
        afficher_grille(ecran, taille_bordure, taille_bmp, taille_separation, n);
        remplir_grilled();
}

void printNb(){

}

void printd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int tour){
	printMapd(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
	printNb();
}

void printsdl(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev){
	if (*isDev==0)//joueur
		printj(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);//afficher l'écran du joueur
	else
		printd(ecran, tab, n, taille_bmp, taille_bordure, taille_separation, *tour);//afficher l'écran du développeur
	SDL_Event event;
	int continuer=1;
	while (continuer){
		SDL_Flip(ecran);
                SDL_WaitEvent(&event);
                if (event.type==SDL_QUIT){
                        continuer=0;
			*tour=tourMax;
		}
                else if (event.type==SDL_KEYDOWN){
			if (*isDev==0){//joueur
				if (event.key.keysym.sym==SDLK_d){
					while (continuer){
						SDL_WaitEvent(&event);
						if (event.type==SDL_QUIT){
							continuer=0;
							*tour=tourMax;
						}
						else if (event.type==SDL_KEYDOWN){
							if (event.key.keysym.sym==SDLK_e){
								while (continuer){
									SDL_WaitEvent(&event);
									if (event.type==SDL_QUIT){
										continuer=0;
										*tour=tourMax;
									}
									else if (event.type==SDL_KEYDOWN){
										if (event.key.keysym.sym==SDLK_v)
											*isDev=1;
										continuer=0;
									}
								}
							}
							else
								continuer=0;
						}
					}
				}
				else
					continuer=0;
			}
			else {//développeur
				if (event.key.keysym.sym==SDLK_j)
					*isDev=0;
				continuer=0;
			}
		}
	}
}

