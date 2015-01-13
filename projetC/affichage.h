#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "obj.h"
#include "constantes.h"//getEau
#include "regles_de_vie.h"//deplDir
#include "./usr/include/SDL/SDL.h"

void clearScreen();
void afficher(obj *tab, int n, int tour);
void afficher2(obj *tab, int n, int tour);

void afficher_bordure(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);
void afficher_separation(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);
void afficher_grille(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);

void remplir_grillej(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void printMapj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void afficherChoix();

void moveUp();
void moveDown();
void moveRight();
void moveLeft();

int getPos(int pos, int dir, int taille_canne, int n);
void afficher_poisson(obj * tab, int place);
void commencer_peche(obj * tab, int pos, int dir, int taille_canne, int n);
void afficherDest();
int pecher(obj * tab, int pos, int * dir, int taille_canne, int * tour, int tourMax, int n);
int filet();
int construire();
int lancer();

void demanderAction(obj * tab, int * pos, int * dir, int taille_canne, int * tour, int tourMax, int * isDev, int n);
void choixPecheur(obj * tab, int * pos, int * dir, int taille_canne, int * tour, int tourMax, int * isDev, int n);
void printj(SDL_Surface * ecran, obj * tab, int * pos, int * dir, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev);

void remplir_grilled(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void printMapd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void afficher_nombres_texte();
void printNb(obj * tab, int n);
void printd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int tour);

void printsdl(SDL_Surface * ecran, obj * tab, int * pos, int * dir, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev);

#endif
