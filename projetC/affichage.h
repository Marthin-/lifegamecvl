#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "obj.h"
#include "./usr/include/SDL/SDL.h"

void clearScreen();
void afficher(obj *tab, int n, int tour);
void afficher2(obj *tab, int n, int tour);

void afficher_bordure(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);
void afficher_separation(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);
void afficher_grille(SDL_Surface * ecran, int taille_bordure, int taille_bmp, int taille_separation, int n);

void remplir_grillej(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void printMapj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void choixPecheur();
void printj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

void remplir_grilled(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void printMapd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);
void afficher_nombres_texte();
void printNb(obj * tab, int n);
void printd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int tour);

void printsdl(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev);

#endif
