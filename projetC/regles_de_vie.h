#ifndef REGLES_DE_VIE_H
#define REGLES_DE_VIE_H

#include "obj.h"

void killObj(obj *tab, int place);
void survie(obj *tab, int n, int tour);
obj getSameType(obj inc, int tour);
void reproduction_plancton(obj * tab, int pos, int n, int tour);
int isPresent(obj *tab, int place, int n, int nbType);
int deplDir(int pos, int dir, int n);
int returnPlace(int is, int place, int n);
void reproduction(obj *tab, int n, int tour);

void predation_pollution(obj * tab, int pos, int n, int tour);
void predation(obj *tab, int n, int tour);
int getDirection(int pos, int nvpos, int n);
int continuerDir(obj * tab, int pos, int nvpos, int dir, int n);
void deplacement_pollution(obj * tab, int pos, int n, int tour);
void deplacement(obj *tab, int n, int tour);
void augTour(obj *tab, int n);
int max(int a, int b);

void checkDeath(obj *tab, int n, int tour, int *death, int *deathLength, int *deathDate);
void deathHistory(int *death, int deathLength, int *deathDate);

#endif
