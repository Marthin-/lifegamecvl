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

void blit(SDL_Surface * ecran, SDL_Surface * img, int pos, int n, int taille_bmp, int taille_bordure, int taille_separation);

void remplir_grillej(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

void printMapj(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

//------------------------------------------------------

void erase(SDL_Surface * ecran, int taille_bmp, int taille_bordure, int taille_separation, int n);

void seeDir(SDL_Surface * ecran, obj * tab, int posPecheur, int dirtosee, int n, int taille_bmp, int taille_bordure, int taille_separation);

int moveDir(SDL_Surface * ecran, obj * tab, int * posPecheur, int dirtomove, int n, int taille_bmp, int taille_bordure, int taille_separation);

void afficher_donnees(SDL_Surface * ecran, obj * tab, int posPecheur, int taille_bmp, int taille_bordure, int taille_separation, int n);

//---------------------------------------------------

void aff_poisson_peche(SDL_Surface * ecran, obj * tab, int place, int n, int taille_bmp, int taille_bordure, int taille_separation);

void aff_mettre_sac(SDL_Surface * ecran, int n, int taille_bmp, int taille_bordure, int taille_separation);

void aff_lancer(SDL_Surface * ecran, int n, int taille_bmp, int taille_bordure, int taille_separation);

void aff_menu_lancer(SDL_Surface * ecran, int n, int taille_bmp, int taille_bordure, int taille_separation);

void respawn(obj * tab, int * posPecheur, int n);

void effectuer_lancer(obj * tab, int cible, int posPoisson, int n, int * posPecheur);

int lancer_poisson(SDL_Surface * ecran, obj * tab, int * posPecheur, int posPoisson, int taille_canne, int * tour, int tourMax, int n, int taille_bmp, int taille_bordure, int taille_separation);

void aff_rien(SDL_Surface * ecran, int n, int taille_bmp, int taille_bordure, int taille_separation);

void commencer_peche(SDL_Surface * ecran, obj * tab, int * posPecheur, int cible, int taille_bmp, int taille_bordure, int taille_separation, int n, int * tour, int tourMax, int taille_canne);

//---------------------------------------------------

void cibler(SDL_Surface * ecran, obj * tab, int cible, int n, int taille_bmp, int taille_bordure, int taille_separation);

void aff_menu_peche(SDL_Surface * ecran, int taille_bmp, int taille_bordure, int taille_separation, int n);

int pecher(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int * tour, int tourMax, int n, int taille_bmp, int taille_bordure, int taille_separation);

int filet();

int commencer_construction(obj * tab, int posPecheur, int cible);

void aff_construire(SDL_Surface * ecran, int taille_bmp, int taille_bordure, int taille_separation, int n);

int construire(SDL_Surface * ecran, obj * tab, int posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax);

//----------------------------------------------

int moveUp(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);
int moveLeft(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);
int moveRight(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);
int moveDown(SDL_Surface * ecran, obj * tab, int * posPecheur, int n, int taille_bmp, int taille_bordure, int taille_separation);

//-----------------------------------------------

void afficherChoix(SDL_Surface * ecran, int taille_bmp, int taille_bordure, int taille_separation, int n);

void demanderAction(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int * tour, int tourMax, int * isDev, int n, int taille_bmp, int taille_bordure, int taille_separation);

void choixPecheur(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int * tour, int tourMax, int * isDev, int n, int taille_bmp, int taille_bordure, int taille_separation);

void printj(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev);

//---------------------------------------------------

void remplir_grilled(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

void printMapd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation);

void afficher_nombres_texte(int * nb);
void printNb(obj * tab, int n);

void printd(SDL_Surface * ecran, obj * tab, int n, int taille_bmp, int taille_bordure, int taille_separation, int tour);

//-----------------------------------------------------

void printsdl(SDL_Surface * ecran, obj * tab, int * posPecheur, int taille_canne, int n, int taille_bmp, int taille_bordure, int taille_separation, int * tour, int tourMax, int * isDev);

#endif

