#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "obj.h"
void clearScreen();
void afficher(obj *tab, int n);
void afficher2(obj *tab, int n, int tour);
void print_sdl(obj *tab, int n, int tour);

#endif
