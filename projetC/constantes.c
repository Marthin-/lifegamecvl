#include <stdio.h>//gets
#include <stdlib.h>//malloc
#include "constantes.h"
#include <string.h>

obj getEau(){
	obj * pt=malloc(sizeof(obj));
	pt->type=0;
	int k;
	for (k=0;k<6;k++)
		pt->mange[k]=-1;//ne mange personne
	strcpy(pt->name,"eau");
	pt->dernier_repas=-1;//pas défini
	pt->satiete=-1;
	pt->derniere_reproduction=-1;
	pt->duree_survie=-1;
	pt->taille=-1;
	pt->taille_du_bide=-1;
	pt->saut_max=-1;
	pt->dernier_deplacement=-1;
	pt->metabolisme=-1;
	pt->gestation=-1;
	pt->frequence_reproduction=-1;
	return *pt;
}

obj getPlancton(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=1;
	int k;
	for (k=0;k<6;k++)
		pt->mange[k]=-1;//ne mange personne
	pt->derniere_reproduction=tour;
	pt->taille=3;
	pt->frequence_reproduction=1;
	return *pt;
}

obj getCorail(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=2;
	pt->mange[0]=1;//corail mange plancton
	int k;
	for (k=1;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=3;
	pt->derniere_reproduction=tour;
	pt->duree_survie=5;
	pt->taille=1;
	pt->taille_du_bide=5;
	pt->saut_max=0;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=10;
	return *pt;
}

obj getBar(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=3;
	pt->mange[0]=1;
	pt->mange[1]=10;
	pt->mange[2]=12;
	int k;
	for (k=3;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=3;
	pt->derniere_reproduction=tour;
	pt->duree_survie=5;
	pt->taille=3;
	pt->taille_du_bide=5;
	pt->saut_max=1;
	pt->dernier_deplacement=tour;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=7;
	return *pt;
}

obj getThon(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=4;
	pt->mange[0]=1;
	int k;
	for (k=1;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=3;
	pt->derniere_reproduction=tour;
	pt->duree_survie=5;
	pt->taille=3;
	pt->taille_du_bide=5;
	pt->saut_max=1;
	pt->dernier_deplacement=tour;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=10;
	return *pt;
}

obj getPollution(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=5;
	pt->mange[0]=2;
	int k;
	for (k=1;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->saut_max=1;
	pt->dernier_deplacement=tour;
	return *pt;
}

obj getPyranha(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=6;
	pt->mange[0]=3;
	pt->mange[1]=4;
	pt->mange[2]=14;
	int k;
	for (k=3;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=5;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=2;
	pt->taille_du_bide=5;
	pt->saut_max=1;
	pt->dernier_deplacement=tour;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=3;
	return *pt;
}

obj getRequin(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=7;
	pt->mange[0]=3;
	pt->mange[1]=14;
	int k;
	for (k=2;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=4;
	pt->taille_du_bide=3;
	pt->saut_max=2;
	pt->dernier_deplacement=tour;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=5;
	return *pt;
}

obj getOrque(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=8;
	pt->mange[0]=7;
	pt->mange[1]=14;
	int k;
	for (k=2;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=6;
	pt->taille_du_bide=5;
	pt->saut_max=2;
	pt->dernier_deplacement=tour;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=5;
	return *pt;
}

obj getBaleine(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=9;
	pt->mange[0]=1;
	pt->mange[1]=10;
	pt->mange[2]=12;
	int k;
	for (k=3;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=7;
	pt->taille=7;
	pt->taille_du_bide=6;
	pt->saut_max=3;
	pt->dernier_deplacement=tour;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=10;
	return *pt;
}

obj getPont(){
	obj * pt=malloc(sizeof(obj));
	pt->type=10;
	return *pt;
}

obj getSol(){
	obj * pt=malloc(sizeof(obj));
	pt->type=11;
	return *pt;
}

obj getPont_pecheur(){
	obj * pt=malloc(sizeof(obj));
	pt->type=12;
	pt->mange[0]=3;
	pt->mange[1]=4;
	pt->mange[2]=6;
	pt->mange[3]=7;
	pt->mange[4]=8;
	pt->mange[5]=9;
	pt->sac=0;//sac vide
	return *pt;
}

obj getSol_pecheur(){
	obj * pt=malloc(sizeof(obj));
	pt->type=13;
	pt->mange[0]=3;
	pt->mange[1]=4;
	pt->mange[2]=6;
	pt->mange[3]=7;
	pt->mange[4]=8;
	pt->mange[5]=9;
	pt->sac=0;//sac vide
	return *pt;
}

obj getEau_pecheur(){
	obj * pt=malloc(sizeof(obj));
	pt->type=14;
	pt->mange[0]=3;
	pt->mange[1]=4;
	pt->mange[2]=6;
	pt->mange[3]=7;
	pt->mange[4]=8;
	pt->mange[5]=9;
	pt->sac=0;//sac vide
	return *pt;
}

