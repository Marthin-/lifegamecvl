#ifndef REGLES_DE_VIE_H
#define REGLES_DE_VIE_H

#include "obj.h"

void survie(obj *tab, int n, int tour);
void killObj(obj *tab, int place);
void reproduction(obj *tab, int n, int tour);
int apte(obj *tab, int place, int tour);
int isPresent(obj *tab, int place, int n, int nbType);
obj getSameType(obj inc, int tour);

void predation(obj *tab, int n, int tour);
void deplacement(obj *tab, int n, int tour);
void augTour(obj *tab, int n);
int max(int a, int b);

void checkDeath(obj *tab, int n, int tour, int *death, int *deathLength, int *deathDate);
void deathHistory(int *death, int deathLength, int *deathDate);

#endif
