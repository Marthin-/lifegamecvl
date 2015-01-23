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

//-------------------------------------------------------

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

//--------------------------------------------------------

void blit(SDL_Surface * ecran, SDL_Surface * img, int pos, int n, int taille_bmp, int taille_bordure, int taille_separation){
	int col=pos%n;
	int row=(pos-col)/n;
	SDL_Rect position;
	position.x=taille_bordure+col*(taille_bmp+taille_separation);
	position.y=taille_bordure+row*(taille_bmp+taille_separation);
	SDL_BlitSurface(img, NULL, ecran, &position);
}

void remplir_grillej(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation){
	SDL_Surface * eau=SDL_LoadBMP("./img/eau.bmp");
	//SDL_Surface * ombre=SDL_LoadBMP("./img/ombre.bmp");
	SDL_Surface * pont=SDL_LoadBMP("./img/pont.bmp");
	SDL_Surface * sol=SDL_LoadBMP("./img/sol.bmp");
	SDL_Surface * sol2=SDL_LoadBMP("./img/sol2.bmp");
	SDL_Surface * pont_pecheur_haut=SDL_LoadBMP("./img/pont_pecheur_haut.bmp");
	SDL_Surface * pont_pecheur_bas=SDL_LoadBMP("./img/pont_pecheur_bas.bmp");
	SDL_Surface * pont_pecheur_gauche=SDL_LoadBMP("./img/pont_pecheur_gauche.bmp");
	SDL_Surface * pont_pecheur_droite=SDL_LoadBMP("./img/pont_pecheur_droite.bmp");
	SDL_Surface * sol_pecheur_bas=SDL_LoadBMP("./img/sol_pecheur_bas.bmp");
	SDL_Surface * sol_pecheur_haut=SDL_LoadBMP("./img/sol_pecheur_haut.bmp");
	SDL_Surface * sol_pecheur_gauche=SDL_LoadBMP("./img/sol_pecheur_gauche.bmp");
	SDL_Surface * sol_pecheur_droite=SDL_LoadBMP("./img/sol_pecheur_droite.bmp");
	SDL_Surface * sol2_pecheur_bas=SDL_LoadBMP("./img/sol2_pecheur_bas.bmp");
	SDL_Surface * sol2_pecheur_haut=SDL_LoadBMP("./img/sol2_pecheur_haut.bmp");
	SDL_Surface * sol2_pecheur_gauche=SDL_LoadBMP("./img/sol2_pecheur_gauche.bmp");
	SDL_Surface * sol2_pecheur_droite=SDL_LoadBMP("./img/sol2_pecheur_droite.bmp");
	SDL_Surface * eau_pecheur_bas=SDL_LoadBMP("./img/eau_pecheur_bas.bmp");
	SDL_Surface * eau_pecheur_haut=SDL_LoadBMP("./img/eau_pecheur_haut.bmp");
	SDL_Surface * eau_pecheur_gauche=SDL_LoadBMP("./img/eau_pecheur_gauche.bmp");
	SDL_Surface * eau_pecheur_droite=SDL_LoadBMP("./img/eau_pecheur_droite.bmp");
	SDL_Rect position;
	position.x=taille_bordure;
	position.y=taille_bordure;
	int bord=taille_bordure+n*taille_bmp+n*taille_separation;
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type==10)
			SDL_BlitSurface(pont, NULL, ecran, &position);
		else if ((tab+k)->type==11 && k%n==0)
			SDL_BlitSurface(sol, NULL, ecran, &position);
		else if ((tab+k)->type==11 && k%n==n-1)
			SDL_BlitSurface(sol2, NULL, ecran, &position);
		else if ((tab+k)->type==12){
			if ((tab+k)->dirPecheur==2)
				SDL_BlitSurface(pont_pecheur_haut, NULL, ecran, &position);
			else if ((tab+k)->dirPecheur==8)
				SDL_BlitSurface(pont_pecheur_gauche, NULL, ecran, &position);
			else if ((tab+k)->dirPecheur==16)
				SDL_BlitSurface(pont_pecheur_droite, NULL, ecran, &position);
			else if ((tab+k)->dirPecheur==64)
				SDL_BlitSurface(pont_pecheur_bas, NULL, ecran, &position);
		}
		else if ((tab+k)->type==13){
			if ((tab+k)->dirPecheur==2){
				if (k%n==0)
					SDL_BlitSurface(sol_pecheur_haut, NULL, ecran, &position);
				else if (k%n==n-1)
					SDL_BlitSurface(sol2_pecheur_haut, NULL, ecran, &position);
			}
			else if ((tab+k)->dirPecheur==8){
				if (k%n==0)
					SDL_BlitSurface(sol_pecheur_gauche, NULL, ecran, &position);
				else if (k%n==n-1)
					SDL_BlitSurface(sol2_pecheur_gauche, NULL, ecran, &position);
			}
			else if ((tab+k)->dirPecheur==16){
				if (k%n==0)
					SDL_BlitSurface(sol_pecheur_droite, NULL, ecran, &position);
				else if (k%n==n-1)
					SDL_BlitSurface(sol2_pecheur_droite, NULL, ecran, &position);
			}
			else if ((tab+k)->dirPecheur==64){
				if (k%n==0)
					SDL_BlitSurface(sol_pecheur_bas, NULL, ecran, &position);
				else if (k%n==n-1)
					SDL_BlitSurface(sol2_pecheur_bas, NULL, ecran, &position);
			}
		}
		else if ((tab+k)->type==14){
			if ((tab+k)->dirPecheur==2)
				SDL_BlitSurface(eau_pecheur_haut, NULL, ecran, &position);
			else if ((tab+k)->dirPecheur==8)
				SDL_BlitSurface(eau_pecheur_gauche, NULL, ecran, &position);
			else if ((tab+k)->dirPecheur==16)
				SDL_BlitSurface(eau_pecheur_droite, NULL, ecran, &position);
			else if ((tab+k)->dirPecheur==64)
				SDL_BlitSurface(eau_pecheur_bas, NULL, ecran, &position);
		}
		//else if ((tab+k)->type>2 && (tab+k)->type<10 && (tab+k)->type!=5)
			//SDL_BlitSurface(ombre, NULL, ecran, &position);
		else
			SDL_BlitSurface(eau, NULL, ecran, &position);
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

//----------------------------------------------------

void erase(SDL_Surface * ecran, int taille_bmp, int taille_bordure, int taille_separation, int n){
	SDL_Surface * erase=SDL_LoadBMP("./img/menu/erase.bmp");
	SDL_Rect position;
	position.x=n*taille_bmp+(n-1)*taille_separation+2*taille_bordure;
        position.y=0;
        SDL_BlitSurface(erase, NULL, ecran, &position);
	SDL_Flip(ecran);
}

void seeDir(SDL_Surface * ecran, obj * tab, int posPecheur, int dirtosee, int n, int taille_bmp, int taille_bordure, int taille_separation){//blit la bonne image du pecheur dans la bonne direction
	SDL_Surface * img=NULL;
	if (dirtosee==2){
		if ((tab+posPecheur)->type==12)
			img=SDL_LoadBMP("./img/pont_pecheur_haut.bmp");
		else if ((tab+posPecheur)->type==13)
			img=SDL_LoadBMP("./img/sol_pecheur_haut.bmp");
		else if ((tab+posPecheur)->type==14)
			img=SDL_LoadBMP("./img/eau_pecheur_haut.bmp");
	}
	else if (dirtosee==8){
		if ((tab+posPecheur)->type==12)
			img=SDL_LoadBMP("./img/pont_pecheur_gauche.bmp");
		else if ((tab+posPecheur)->type==13)
			img=SDL_LoadBMP("./img/sol_pecheur_gauche.bmp");
		else if ((tab+posPecheur)->type==14)
			img=SDL_LoadBMP("./img/eau_pecheur_gauche.bmp");
	}
	else if (dirtosee==16){
		if ((tab+posPecheur)->type==12)
			img=SDL_LoadBMP("./img/pont_pecheur_droite.bmp");
		else if ((tab+posPecheur)->type==13)
			img=SDL_LoadBMP("./img/sol_pecheur_droite.bmp");
		else if ((tab+posPecheur)->type==14)
			img=SDL_LoadBMP("./img/eau_pecheur_droite.bmp");
	}
	else if (dirtosee==64){
		if ((tab+posPecheur)->type==12)
			img=SDL_LoadBMP("./img/pont_pecheur_bas.bmp");
		else if ((tab+posPecheur)->type==13)
			img=SDL_LoadBMP("./img/sol_pecheur_bas.bmp");
		else if ((tab+posPecheur)->type==14)
			img=SDL_LoadBMP("./img/eau_pecheur_bas.bmp");
	}
	blit(ecran, img, posPecheur, n, taille_bmp, taille_bordure, taille_separation);
	(tab+posPecheur)->dirPecheur=dirtosee;
}

int moveDir(SDL_Surface * ecran, obj * tab, int * posPecheur, int dirtomove, int n, int taille_bmp, int taille_bordure, int taille_separation){
	int nvpos=getPos(*posPecheur, dirtomove, 1, n);
	if (nvpos==(*posPecheur)){
		seeDir(ecran, tab, *posPecheur, dirtomove, n, taille_bmp, taille_bordure, taille_separation);
		return -1;//ne s'est pas déplacé
	}
	if ((tab+nvpos)->type>=0 && (tab+nvpos)->type<12){//se déplacer
		if ((tab+nvpos)->type==10)
			*(tab+nvpos)=getPont_pecheur();
		else if ((tab+nvpos)->type==11)
			*(tab+nvpos)=getSol_pecheur();
		else
			*(tab+nvpos)=getEau_pecheur();
		(tab+nvpos)->sac=(tab+(*posPecheur))->sac;
		if ((tab+(*posPecheur))->type==12){
			*(tab+(*posPecheur))=getPont();
			SDL_Surface * pont=SDL_LoadBMP("./img/pont.bmp");
			blit(ecran, pont, *posPecheur, n, taille_bmp, taille_bordure, taille_separation);
		}
		else if ((tab+(*posPecheur))->type==13){
			*(tab+(*posPecheur))=getSol();
			SDL_Surface * sol=SDL_LoadBMP("./img/sol.bmp");
			blit(ecran, sol, *posPecheur, n, taille_bmp, taille_bordure, taille_separation);
		}
		else if ((tab+(*posPecheur))->type==14){
			*(tab+(*posPecheur))=getEau();
			SDL_Surface * eau=SDL_LoadBMP("./img/eau.bmp");
			blit(ecran, eau, *posPecheur, n, taille_bmp, taille_bordure, taille_separation);
		}
		*posPecheur=nvpos;
		seeDir(ecran, tab, *posPecheur, dirtomove, n, taille_bmp, taille_bordure, taille_separation);
		return 0;//s'est déplacé
	}
	seeDir(ecran, tab, *posPecheur, dirtomove, n, taille_bmp, taille_bordure, taille_separation);
	return -1;
}

//-------------------------------------------------------

void afficher_donnees(SDL_Surface * ecran, obj * tab, int posPecheur, int taille_bmp, int taille_bordure, int taille_separation, int n){
	//printf("Sac : %i\n", (tab+posPecheur)->sac);
	SDL_Surface * sac=SDL_LoadBMP("./img/menu/sac.bmp");
	SDL_Surface * nbsac;
	if((tab+posPecheur)->sac==0)
		nbsac=SDL_LoadBMP("./img/menu/0.bmp");
	else if((tab+posPecheur)->sac==1)
		nbsac=SDL_LoadBMP("./img/menu/1.bmp");
	else if((tab+posPecheur)->sac==2)
		nbsac=SDL_LoadBMP("./img/menu/2.bmp");
	else if((tab+posPecheur)->sac==3)
		nbsac=SDL_LoadBMP("./img/menu/3.bmp");
	else if((tab+posPecheur)->sac==4)
		nbsac=SDL_LoadBMP("./img/menu/4.bmp");
	else if((tab+posPecheur)->sac==5)
		nbsac=SDL_LoadBMP("./img/menu/5.bmp");
	else if((tab+posPecheur)->sac==6)
		nbsac=SDL_LoadBMP("./img/menu/6.bmp");
	else if((tab+posPecheur)->sac==7)
		nbsac=SDL_LoadBMP("./img/menu/7.bmp");
	else if((tab+posPecheur)->sac==8)
		nbsac=SDL_LoadBMP("./img/menu/8.bmp");
	else if((tab+posPecheur)->sac==9)
		nbsac=SDL_LoadBMP("./img/menu/9.bmp");
	SDL_Rect position;
	position.x=n*taille_bmp+(n-1)*taille_separation+2*taille_bordure+50;
	position.y=50;
	SDL_BlitSurface(sac, NULL, ecran, &position);
	position.x+=50;
	SDL_BlitSurface(nbsac, NULL, ecran, &position);
	SDL_Flip(ecran);
}

void aff_poisson_peche(obj * tab, int place){
	printf("Espece %i pechee !\n", (tab+place)->type);
}

void commencer_peche(obj * tab, int posPecheur, int cible){
	if ((tab+cible)->type>2 && (tab+cible)->type<10 && (tab+cible)->type!=5){
		aff_poisson_peche(tab, cible);
		(tab+posPecheur)->sac+=(tab+cible)->taille;
		if ((tab+posPecheur)->sac>9)
			(tab+posPecheur)->sac=9;
		*(tab+cible)=getEau();
	}
	else
		printf("Rien peche.\n");
}

void cibler(/*SDL_Surface * ecran, obj * tab, */int cible/*, int ancienne_cible*/){
	printf("cible : %i\n", cible);
/*	SDL_Surface * cibleimg=SDL_LoadBMP("./img/cible.bmp");
	SDL_Surface * =SDL_LoadBMP("./img/cible.bmp");
	
	blit(ecran, cibleimg, cible, n, taille_bmp, taille_bordure, taille_separation);*/
}

void aff_menu_peche(SDL_Surface * ecran, int taille_bmp, int taille_bordure, int taille_separation, int n){
	SDL_Surface * menu_peche=SDL_LoadBMP("./img/menu/menu_peche.bmp");
	SDL_Rect position;
	position.x=n*taille_bmp+(n-1)*taille_separation+2*taille_bordure+50;
        position.y=100;
        SDL_BlitSurface(menu_peche, NULL, ecran, &position);
	SDL_Flip(ecran);
}

int pecher(SDL_Surface * ecran, obj * tab, int posPecheur, int taille_canne, int * tour, int tourMax, int n, int taille_bmp, int taille_bordure, int taille_separation){
	SDL_Event event;
	int continuer=1;
	int cible=getPos(posPecheur, (tab+posPecheur)->dirPecheur, 1, n);
	while (continuer){
		erase(ecran, taille_bmp, taille_bordure, taille_separation, n);
		afficher_donnees(ecran, tab, posPecheur, taille_bmp, taille_bordure, taille_separation, n);
		aff_menu_peche(ecran, taille_bmp, taille_bordure, taille_separation, n);
		cibler(cible);//affiche la case de peche de destination
                SDL_WaitEvent(&event);
                if (event.type==SDL_QUIT){
                        continuer=0;
			*tour=tourMax;
		}
                else if (event.type==SDL_KEYDOWN){
			int key=event.key.keysym.sym;
			if (key==SDLK_p){//le joueur choisit de pecher
				commencer_peche(tab, posPecheur, cible);
				continuer=0;
			}
			else if (key==SDLK_UP){
				cible=getPos(cible, 2, 1, n);
				seeDir(ecran, tab, posPecheur, 2, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_DOWN){
				cible=getPos(cible, 64, 1, n);
				seeDir(ecran, tab, posPecheur, 64, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_RIGHT){
				cible=getPos(cible, 16, 1, n);
				seeDir(ecran, tab, posPecheur, 16, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_LEFT){
				cible=getPos(cible, 8, 1, n);
				seeDir(ecran, tab, posPecheur, 8, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_a)//le joueur choisit d'annuler son choix
				return -1;
		}
	}
/*
	else if (key==SDLK_l){//le joueur choisit de lancer un poisson
		if (lancer()!=-1)
			continuer=0;
	}
*/
	return 0;
}

int filet(){
	return -1;
}


int commencer_construction(obj * tab, int posPecheur, int cible){
	if ((tab+cible)->type<10 && (tab+posPecheur)->sac>0){
		*(tab+cible)=getPont();
		(tab+posPecheur)->sac--;
		return 0;
	}
	return -1;
}

int construire(SDL_Surface * ecran, obj * tab, int posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax){
	int cible=getPos(posPecheur, (tab+posPecheur)->dirPecheur, 1, n);
	SDL_Event event;
	int continuer=1;
	while (continuer){
		cibler(cible);
                SDL_WaitEvent(&event);
                if (event.type==SDL_QUIT){
                        continuer=0;
			*tour=tourMax;
		}
                else if (event.type==SDL_KEYDOWN){
			int key=event.key.keysym.sym;
			if (key==SDLK_c){
				if (commencer_construction(tab, posPecheur, cible)!=-1)
					continuer=0;
			}
			else if (key==SDLK_UP){
				cible=getPos(posPecheur, 2, 1, n);
				seeDir(ecran, tab, posPecheur, 2, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_DOWN){
				cible=getPos(posPecheur, 64, 1, n);
				seeDir(ecran, tab, posPecheur, 64, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_RIGHT){
				cible=getPos(posPecheur, 16, 1, n);
				seeDir(ecran, tab, posPecheur, 16, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_LEFT){
				cible=getPos(posPecheur, 8, 1, n);
				seeDir(ecran, tab, posPecheur, 8, n, taille_bmp, taille_bordure, taille_separation);
			}
			else if (key==SDLK_a)//le joueur choisit d'annuler son choix
				return -1;
		}
	}
	return 0;
}

int lancer(){

	return -1;
}

//------------------------------------------------------------

int moveUp(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation){
	return moveDir(ecran, tab, posPecheur, 2, n, taille_bmp, taille_bordure, taille_separation);
}

int moveLeft(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation){
        return moveDir(ecran, tab, posPecheur, 8, n, taille_bmp, taille_bordure, taille_separation);
}

int moveRight(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation){
        return moveDir(ecran, tab, posPecheur, 16, n, taille_bmp, taille_bordure, taille_separation);
}

int moveDown(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation){
        return moveDir(ecran, tab, posPecheur, 64, n, taille_bmp, taille_bordure, taille_separation);
}

//------------------------------------------------------------

void afficherChoix(SDL_Surface * ecran, int taille_bmp, int taille_bordure, int taille_separation, int n){
	//printf("p  : pecher\nf : lancer filet\nfleches : se deplacer\nc : construire pont\n");
	SDL_Surface * princ=SDL_LoadBMP("./img/menu/princ.bmp");
	SDL_Rect position;
	position.x=n*taille_bmp+(n-1)*taille_separation+2*taille_bordure+100;
        position.y=100;
        SDL_BlitSurface(princ, NULL, ecran, &position);
	SDL_Flip(ecran);
}

void demanderAction(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int * tour, int tourMax, int * isDev, int n, int taille_bmp, int taille_bordure, int taille_separation){
	SDL_Event event;
	int continuer=1;
	//printf("Veuillez faire un choix.\n");
	while (continuer){
		erase(ecran, taille_bmp, taille_bordure, taille_separation, n);
		afficher_donnees(ecran, tab, *posPecheur, taille_bmp, taille_bordure, taille_separation, n);
		afficherChoix(ecran, taille_bmp, taille_bordure, taille_separation, n);
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
				if (pecher(ecran, tab, *posPecheur, taille_canne, tour, tourMax, n, taille_bmp, taille_bordure, taille_separation)!=-1)
					continuer=0;
			}
			else if (key==SDLK_f){//le joueur choisit de lancer le filet
				if (filet()!=-1)
					continuer=0;
			}
			else if (key==SDLK_UP){
				if (moveUp(ecran, tab, posPecheur, n, taille_bmp, taille_bordure, taille_separation)!=-1)
					continuer=0;
			}
			else if (key==SDLK_DOWN){
				if (moveDown(ecran, tab, posPecheur, n, taille_bmp, taille_bordure, taille_separation)!=-1)
					continuer=0;
			}
			else if (key==SDLK_RIGHT){
				if (moveRight(ecran, tab, posPecheur, n, taille_bmp, taille_bordure, taille_separation)!=-1)
					continuer=0;
			}
			else if (key==SDLK_LEFT){
				if (moveLeft(ecran, tab, posPecheur, n, taille_bmp, taille_bordure, taille_separation)!=-1)
					continuer=0;
			}
			else if (key==SDLK_c){//le joueur choisit de construire un pont
				if (construire(ecran, tab, *posPecheur, n, taille_bmp, taille_bordure, taille_separation, tour, tourMax)!=-1)
					continuer=0;
			}
		}
	}
}

void choixPecheur(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int * tour, int tourMax, int * isDev, int n, int taille_bmp, int taille_bordure, int taille_separation){
	demanderAction(ecran, tab, posPecheur, taille_canne, tour, tourMax, isDev, n, taille_bmp, taille_bordure, taille_separation);
}

void printj(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev){
	printMapj(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
	choixPecheur(ecran, tab, posPecheur, taille_canne, tour, tourMax, isDev, n, taille_bmp, taille_bordure, taille_separation);
}

//-------------------------------------------------------------

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

void afficher_nombres_texte(int * nb){
	int k;
	for (k=0;k<9;k++)
		printf("%i:%i|", k+1, *(nb+k));
	printf("\n");
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
	afficher_nombres_texte(nb);
	free(nb);
}

void printd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int tour){
	printMapd(ecran, tab, n, taille_bmp, taille_bordure, taille_separation);
	printNb(tab, n);
	SDL_Flip(ecran);
}

//-----------------------------------------------------

void printsdl(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev){
	if (*isDev==0)//joueur
		printj(ecran, tab, posPecheur, taille_canne, n, taille_bmp, taille_bordure, taille_separation, tour, tourMax, isDev);//afficher l'écran du joueur
	else
		printd(ecran, tab, n, taille_bmp, taille_bordure, taille_separation, *tour);//afficher l'écran du développeur
}

