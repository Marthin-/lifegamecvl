#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "obj.h"
#include "constantes.h"//getEau
#include "regles_de_vie.h"//getPos
#include "./usr/include/SDL/SDL.h"

void clearScreen();
void afficher(obj *tab, int n, int tour);
void afficher2(obj *tab, int n, int tour);

//-----------------------------------------------------

void afficher_bordure(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);

void afficher_separation(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);

void afficher_grille(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);

//------------------------------------------------------

void remplir_grillej(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

void printMapj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

//------------------------------------------------------

void blit(SDL_Surface * ecran, SDL_Surface * img, int pos, int n, int taille_bmp, int taille_bordure, int taille_separation);

void seeDir(SDL_Surface * ecran, obj * tab, int posPecheur, int * dirPecheur, int dirtosee, int n, int taille_bmp, int taille_bordure, int taille_separation);

int moveDir(SDL_Surface * ecran, obj * tab, int * posPecheur, int * dirPecheur, int dirtomove, int n, int taille_bmp, int taille_bordure, int taille_separation);

void afficher_poisson(obj * tab, int place);

void commencer_peche(obj * tab, int posPecheur, int cible);

void afficherDest(int cible);

int pecher(SDL_Surface * ecran, obj * tab, int posPecheur, int * dirPecheur, int taille_canne, int * tour, int tourMax, int n, int taille_bmp, int taille_bordure, int taille_separation);

int filet();
int construire();
int lancer();

int moveUp(SDL_Surface * ecran, obj * tab, int * posPecheur, int * dirPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);
int moveLeft(SDL_Surface * ecran, obj * tab, int * posPecheur, int * dirPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);
int moveRight(SDL_Surface * ecran, obj * tab, int * posPecheur, int * dirPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);
int moveDown(SDL_Surface * ecran, obj * tab, int * posPecheur, int * dirPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);

void demanderAction(SDL_Surface * ecran, obj * tab, int * pos, int * dir, int taille_canne, int * tour, int tourMax, int * isDev, int n, int taille_bmp, int taille_bordure, int taille_separation);

void afficherChoix();

void choixPecheur(SDL_Surface * ecran, obj * tab, int * pos, int * dir, int taille_canne, int * tour, int tourMax, int * isDev, int n, int taille_bmp, int taille_bordure, int taille_separation);

void afficher_donnees(obj * tab, int pos);

void printj(SDL_Surface * ecran, obj * tab, int * posPecheur, int * dirPecheur, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev);

//---------------------------------------------------

void remplir_grilled(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

void printMapd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

void afficher_nombres_texte();
void printNb(obj * tab, int n);

void printd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int tour);

//-----------------------------------------------------

void printsdl(SDL_Surface * ecran, obj * tab, int * posPecheur, int * dirPecheur, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev);

#endif

