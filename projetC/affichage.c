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
	SDL_Flip(ecran);
}

void afficherChoix(){

}

void moveUp(){

}

void moveDown(){

}

void moveRight(){

}

void moveLeft(){

}

int getPos(int pos, int dir, int taille_canne, int n){//retourne la case qui va etre pechee
	int place=pos;
	int k;
	for (k=0;k<taille_canne;k++){
		if ((place<n && dir==2) || (place%n==0 && dir==8) || (place%n==n-1 && dir==16) || (place>=n*n-n && dir==64))
			k=taille_canne;
		else
			place=deplDir(place, dir, n);
	}
	return place;
}

void afficher_poisson(obj * tab, int place){
	printf("Espece %i pechee !\n", (tab+place)->type);
}

void commencer_peche(obj * tab, int pos, int dir, int taille_canne, int n){
	int place=getPos(pos, dir, taille_canne, n);
	if ((tab+place)->type>2 && (tab+place)->type<10 && (tab+place)->type!=5){
		afficher_poisson(tab, place);
		(tab+pos)->sac+=(tab+place)->taille;
		*(tab+place)=getEau();
	}
	else
		printf("Rien peche.\n");
}

void afficherDest(){

}

int pecher(obj * tab, int pos, int * dir, int taille_canne, int * tour, int tourMax, int n){
	SDL_Event event;
	int continuer=1;
	while (continuer){
		afficherDest();//affiche la case de peche de destination
                SDL_WaitEvent(&event);
                if (event.type==SDL_QUIT){
                        continuer=0;
			*tour=tourMax;
		}
                else if (event.type==SDL_KEYDOWN){
			int key=event.key.keysym.sym;
			if (key==SDLK_p){//le joueur choisit de pecher
				commencer_peche(tab, pos, *dir, taille_canne, n);
				continuer=0;
			}
			else if (key==SDLK_UP)
				moveUp();
			else if (key==SDLK_DOWN)
				moveDown();
			else if (key==SDLK_RIGHT)
				moveRight();
			else if (key==SDLK_LEFT)
				moveLeft();
			else if (key==SDLK_a)//le joueur choisit d'annuler son choix
				return -1;
		}
	}
	return 0;
}

int filet(){
	return 0;
}

int construire(){

	return 0;
}

int lancer(){

	return 0;
}

void demanderAction(obj * tab, int * pos, int * dir, int taille_canne, int * tour, int tourMax, int * isDev, int n){
	SDL_Event event;
	int continuer=1;
	printf("Veuillez faire un choix.\n");
	while (continuer){
                SDL_WaitEvent(&event);
                if (event.type==SDL_QUIT){
                        continuer=0;
			*tour=tourMax;
		}
                else if (event.type==SDL_KEYDOWN){
			int key=event.key.keysym.sym;
			if (key==SDLK_w){//passe en mode développeur
				*isDev=1;
				continuer=0;
				printf("dev !\n");
			}
			else if (key==SDLK_p){//le joueur choisit de pecher
				int p=pecher(tab, *pos, dir, taille_canne, tour, tourMax, n);
				if (p!=-1)
					continuer=0;
			}
			else if (key==SDLK_f){//le joueur choisit de lancer le filet
				int f=filet();
				if (f!=-1)
					continuer=0;
			}
			else if (key==SDLK_UP){
				moveUp();
				continuer=0;
			}
			else if (key==SDLK_DOWN){
				moveDown();
				continuer=0;
			}
			else if (key==SDLK_RIGHT){
				moveRight();
				continuer=0;
			}
			else if (key==SDLK_LEFT){
				moveLeft();
				continuer=0;
			}
			else if (key==SDLK_c){//le joueur choisit de construire un pont
				int c=construire();
				if (c!=-1)
					continuer=0;
			}
			else if (key==SDLK_l){//le joueur choisit de lancer un poisson
				int l=lancer();
				if (l!=-1)
					continuer=0;
			}
		}
	}
}

void choixPecheur(obj * tab, int * pos, int * dir, int taille_canne, int * tour, int tourMax, int * isDev, int n){
	afficherChoix();
	demanderAction(tab, pos, dir, taille_canne, tour, tourMax, isDev, n);
}

void printj(SDL_Surface * ecran, obj * tab, int * pos, int * dir, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev){
	printMapj(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
	printf("sac : %i\n", (tab+(*pos))->sac);
	choixPecheur(tab, pos, dir, taille_canne, tour, tourMax, isDev, n);
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

void afficher_nombres_texte(){
	
}

void printNb(obj * tab, int n){//affiche le nombre d'animaux par especes
	int * nb=calloc(9,sizeof(int));
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type==1)
			*nb+=1;
		else if ((tab+k)->type==2)
			*(nb+1)+=1;
		else if ((tab+k)->type==3)
			*(nb+2)+=1;
		else if ((tab+k)->type==4)
			*(nb+3)+=1;
		else if ((tab+k)->type==5)
			*(nb+4)+=1;
		else if ((tab+k)->type==6)
			*(nb+5)+=1;
		else if ((tab+k)->type==7)
			*(nb+6)+=1;
		else if ((tab+k)->type==8)
			*(nb+7)+=1;
		else if ((tab+k)->type==9)
			*(nb+8)+=1;
	}
	afficher_nombres_texte();
	free(nb);
}

void printd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int tour){
	printMapd(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
	printNb(tab, n);
}

void printsdl(SDL_Surface * ecran, obj * tab, int * pos, int * dir, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev){
	if (*isDev==0)//joueur
		printj(ecran, tab, pos, dir, taille_canne, n, taille_bmp, taille_bordure, taille_separation, tour, tourMax, isDev);//afficher l'écran du joueur
	else
		printd(ecran, tab, n, taille_bmp, taille_bordure, taille_separation, *tour);//afficher l'écran du développeur
	SDL_Flip(ecran);
	/*SDL_Event event;
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
	}*/
}

