#include <stdio.h>
#include "affichage.h"

void clearScreen (){
	int esc=27;
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
			sym='H';
		else if ((tab+k)->type==11)
			sym='X';
		else if ((tab+k)->type==12)
			sym='@';
		else if ((tab+k)->type==13)
			sym='@';
		else if ((tab+k)->type==14)
			sym='@';
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
                printf("%i ", (tab+k)->type+70);
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
	SDL_Surface *bordure_verticale=SDL_CreateRGBSurface(SDL_HWSURFACE, taille_bordure, 2*taille_bordure+n*taille_bmp+(n-1)*taille_separation, 32, 0, 0, 0, 0);
        SDL_FillRect(bordure_verticale, NULL, SDL_MapRGB(bordure_verticale->format, 0, 0, 0));
	SDL_Surface *bordure_horizontale=SDL_CreateRGBSurface(SDL_HWSURFACE, bord, taille_bordure, 32, 0, 0, 0, 0);
        SDL_FillRect(bordure_horizontale, NULL, SDL_MapRGB(bordure_horizontale->format, 0, 0, 0));
	SDL_BlitSurface(bordure_verticale, NULL, ecran, &position);
	SDL_BlitSurface(bordure_horizontale, NULL, ecran, &position);
	position.x=bord-taille_bordure;
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
		position.x+=taille_bmp+taille_separation;
	}
	position.x=taille_bordure;
	position.y=taille_bordure+taille_bmp;
	for (k=0;k<n-1;k++){
		SDL_BlitSurface(separation_horizontale, NULL, ecran, &position);
                position.y+=taille_bmp+taille_separation;
	}
}

void afficher_grille(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n){
	afficher_bordure(ecran, taille_bordure, taille_bmp, taille_separation, n);
	afficher_separation(ecran, taille_bordure, taille_bmp, taille_separation, n);
}

void remplir_grillej(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
	SDL_Surface * eau=SDL_LoadBMP("./img/eau.bmp");
	SDL_Surface * ombre=SDL_LoadBMP("./img/ombre.bmp");
	SDL_Surface * pont=SDL_LoadBMP("./img/pont.bmp");
	SDL_Surface * sol=SDL_LoadBMP("./img/sol.bmp");
	SDL_Surface * pont_pecheur=SDL_LoadBMP("./img/pont_pecheur.bmp");
	SDL_Surface * sol_pecheur=SDL_LoadBMP("./img/sol_pecheur.bmp");
	SDL_Rect position;
	position.x=taille_bordure;
	position.y=taille_bordure;
	int bord=taille_bordure+n*taille_bmp+n*taille_separation;
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type==0)
			SDL_BlitSurface(eau, NULL, ecran, &position);
		else if ((tab+k)->type==10)
			SDL_BlitSurface(pont, NULL, ecran, &position);
		else if ((tab+k)->type==11)
			SDL_BlitSurface(sol, NULL, ecran, &position);
		else if ((tab+k)->type==12)
			SDL_BlitSurface(pont_pecheur, NULL, ecran, &position);
		else if ((tab+k)->type==13)
			SDL_BlitSurface(sol_pecheur, NULL, ecran, &position);
		else
			SDL_BlitSurface(ombre, NULL, ecran, &position);
		position.x+=taille_bmp+taille_separation;
		if (position.x==bord){
			position.x=taille_bordure;
			position.y+=taille_bmp+taille_separation;
		}
	}
}

void printMapj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
	afficher_grille(ecran, taille_bordure, taille_bmp, taille_separation, n);
	remplir_grillej(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
}

void choixPecheur(){

}

void printj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
	printMapj(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
	choixPecheur();
}

void remplir_grilled(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
	SDL_Surface * eau=SDL_LoadBMP("./img/eau.bmp");
	SDL_Surface * plancton=SDL_LoadBMP("./img/plancton.bmp");
	SDL_Surface * corail=SDL_LoadBMP("./img/corail.bmp");
	SDL_Surface * bar=SDL_LoadBMP("./img/bar.bmp");
	SDL_Surface * thon=SDL_LoadBMP("./img/thon.bmp");
	SDL_Surface * pollution=SDL_LoadBMP("./img/pollution.bmp");
	SDL_Surface * pyranha=SDL_LoadBMP("./img/pyranha.bmp");
	SDL_Surface * requin=SDL_LoadBMP("./img/requin.bmp");
	SDL_Surface * orque=SDL_LoadBMP("./img/orque.bmp");
	SDL_Surface * baleine=SDL_LoadBMP("./img/baleine.bmp");
	SDL_Surface * pont=SDL_LoadBMP("./img/pont.bmp");
	SDL_Surface * sol=SDL_LoadBMP("./img/sol.bmp");
	SDL_Surface * pont_pecheur=SDL_LoadBMP("./img/pont_pecheur.bmp");
	SDL_Surface * sol_pecheur=SDL_LoadBMP("./img/sol_pecheur.bmp");
	SDL_Surface * ombre=SDL_LoadBMP("./img/ombre.bmp");
	SDL_Rect position;
	position.x=taille_bordure;
	position.y=taille_bordure;
	int bord=taille_bordure+n*taille_bmp+n*taille_separation;
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type==0)
			SDL_BlitSurface(eau, NULL, ecran, &position);
		else if ((tab+k)->type==1)
			SDL_BlitSurface(plancton, NULL, ecran, &position);
		else if ((tab+k)->type==2)
			SDL_BlitSurface(corail, NULL, ecran, &position);
		else if ((tab+k)->type==3)
			SDL_BlitSurface(bar, NULL, ecran, &position);
		else if ((tab+k)->type==4)
			SDL_BlitSurface(thon, NULL, ecran, &position);
		else if ((tab+k)->type==5)
			SDL_BlitSurface(pollution, NULL, ecran, &position);
		else if ((tab+k)->type==6)
			SDL_BlitSurface(pyranha, NULL, ecran, &position);
		else if ((tab+k)->type==7)
			SDL_BlitSurface(requin, NULL, ecran, &position);
		else if ((tab+k)->type==8)
			SDL_BlitSurface(orque, NULL, ecran, &position);
		else if ((tab+k)->type==9)
			SDL_BlitSurface(baleine, NULL, ecran, &position);
		else if ((tab+k)->type==10)
			SDL_BlitSurface(pont, NULL, ecran, &position);
		else if ((tab+k)->type==11)
			SDL_BlitSurface(sol, NULL, ecran, &position);
		else if ((tab+k)->type==12)
			SDL_BlitSurface(pont_pecheur, NULL, ecran, &position);
		else if ((tab+k)->type==13)
			SDL_BlitSurface(sol_pecheur, NULL, ecran, &position);
		else
			SDL_BlitSurface(ombre, NULL, ecran, &position);
		position.x+=taille_bmp+taille_separation;
		if (position.x==bord){
			position.x=taille_bordure;
			position.y+=taille_bmp+taille_separation;
		}
	}
}

void printMapd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
        afficher_grille(ecran, taille_bordure, taille_bmp, taille_separation, n);
        remplir_grilled(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
}

void printNb(){//affiche le nombre d'animaux par especes

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
	SDL_Flip(ecran);
	SDL_Event event;
	int continuer=1;
	while (continuer){
                SDL_PollEvent(&event);
                if (event.type==SDL_QUIT){
                        continuer=0;
			*tour=tourMax;
		}
                else if (event.type==SDL_KEYDOWN){
			if (*isDev==0){//joueur
				if (event.key.keysym.sym==SDLK_d)
					*isDev=1;
			}
			else {//développeur
				if (event.key.keysym.sym==SDLK_j)
					*isDev=0;
			}
			continuer=0;
		}
	}
}

