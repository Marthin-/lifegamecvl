#ifndef REGLES_DE_VIE_H
#define REGLES_DE_VIE_H

#include "obj.h"

void killObj(obj *tab, int place);
void survie(obj *tab, int n, int tour);
int apte(obj *tab, int place, int tour);
int isPresent(obj *tab, int place, int n, int nbType);
int isPresent2(obj *tab, int place, int n, int nbType);
int returnPlace(int is, int place, int n);
obj getSameType(obj inc, int tour);
void reproduction(obj *tab, int n, int tour);
void reproduction2(obj *tab, int n, int tour);

void predation(obj *tab, int n, int tour);
void deplacement(obj *tab, int n, int tour);
void augTour(obj *tab, int n);
int max(int a, int b);

void checkDeath(obj *tab, int n, int tour, int *death, int *deathLength, int *deathDate);
void deathHistory(int *death, int deathLength, int *deathDate);

#endif
