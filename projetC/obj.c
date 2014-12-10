#include <stdio.h>
#include <stdlib.h>
#include "obj.h"
#define esc 27

void clrscreen ()         {printf ("%c[2J%c[H" , esc , esc) ;}

obj getEau(){
	obj * pt=malloc(sizeof(obj));
	pt->type=0;
	int k;
	for (k=0;k<6;k++)
		pt->mange[k]=-1;//ne mange personne
	pt->dernier_repas=-1;//pas défini
	pt->satiete=-1;
	pt->derniere_reproduction=-1;
	pt->duree_survie=-1;
	pt->taille=-1;
	pt->taille_du_bide=-1;
	pt->saut_max=-1;
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
	pt->dernier_repas=-1;//le plancton ne mange pas
	pt->satiete=-1;//infini
	pt->derniere_reproduction=tour;
	pt->duree_survie=-1;//infini
	pt->taille=1;
	pt->taille_du_bide=-1;//pas de bide
	pt->saut_max=0;
	pt->metabolisme=0;
	pt->gestation=0;
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
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=1;
	pt->taille_du_bide=1;
	pt->saut_max=0;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=5;
	return *pt;
}

obj getBar(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=3;
	pt->mange[0]=1;
	pt->mange[1]=11;
	int k;
	for (k=2;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=3;
	pt->taille_du_bide=2;
	pt->saut_max=1;
	pt->metabolisme=1;
	pt->gestation=4;
	pt->frequence_reproduction=3;
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
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=3;
	pt->taille_du_bide=2;
	pt->saut_max=1;
	pt->metabolisme=1;
	pt->gestation=4;
	pt->frequence_reproduction=3;
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
	pt->satiete=-1;
	pt->derniere_reproduction=-1;
	pt->duree_survie=-1;//infini
	pt->taille=0;
	pt->taille_du_bide=1;//taille corail
	pt->saut_max=1;
	pt->metabolisme=-1;
	pt->gestation=-1;
	pt->frequence_reproduction=-1;
	return *pt;
}

obj getPyranha(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=6;
	pt->mange[0]=3;
	pt->mange[1]=4;
	pt->mange[2]=10;
	int k;
	for (k=3;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=2;
	pt->taille_du_bide=1;
	pt->saut_max=1;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=3;
	return *pt;
}

obj getRequin(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=7;
	pt->mange[0]=3;
	pt->mange[1]=10;
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
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=5;
	return *pt;
}

obj getOrque(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=8;
	pt->mange[0]=7;
	pt->mange[1]=10;
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
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=5;
	return *pt;
}

obj getBaleine(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=9;
	pt->mange[0]=1;
	pt->mange[1]=11;
	int k;
	for (k=2;k<6;k++)
		pt->mange[k]=-1;
	pt->dernier_repas=tour;
	pt->satiete=10;
	pt->derniere_reproduction=tour;
	pt->duree_survie=10;
	pt->taille=7;
	pt->taille_du_bide=6;
	pt->saut_max=3;
	pt->metabolisme=1;
	pt->gestation=3;
	pt->frequence_reproduction=6;
	return *pt;
}

obj getPecheur(int tour){
	obj * pt=malloc(sizeof(obj));
	pt->type=10;
	pt->mange[0]=3;
	pt->mange[1]=4;
	pt->mange[2]=6;
	pt->mange[3]=7;
	pt->mange[4]=8;
	pt->mange[5]=9;
	pt->dernier_repas=tour;
	pt->satiete=10;
	pt->derniere_reproduction=-1;//ne se reproduit pas
	pt->duree_survie=3;
	pt->taille=3;
	pt->taille_du_bide=10;
	pt->saut_max=1;
	pt->metabolisme=1;
	pt->gestation=-1;//ne se reproduit pas
	pt->frequence_reproduction=-1;//ne se reproduit pas
	return *pt;
}

obj getPont(){
	obj * pt=malloc(sizeof(obj));
	pt->type=11;
	int k;
	for (k=0;k<6;k++)
		pt->mange[k]=-1;//ne mange personne
	pt->dernier_repas=-1;//pas défini
	pt->satiete=-1;
	pt->derniere_reproduction=-1;
	pt->duree_survie=-1;//infini
	pt->taille=2;
	pt->taille_du_bide=-1;
	pt->saut_max=-1;
	pt->metabolisme=-1;
	pt->gestation=-1;
	pt->frequence_reproduction=-1;
	return *pt;
}

void remplir(obj *tab, int n){
	int k;
	for (k=0;k<n*n;k++){
		int aleatEau=rand()%100;
		obj inc;
		if (aleatEau<30)
			inc=getEau();
		else {
			int mys=rand()%9+1;
			if (mys==1)
				inc=getPlancton(0);
			else if (mys==2)
				inc=getCorail(0);
			else if (mys==3)
				inc=getBar(0);
			else if (mys==4)
				inc=getThon(0);
			else if (mys==5)
				inc=getPollution(0);
			else if (mys==6)
				inc=getPyranha(0);
			else if (mys==7)
				inc=getRequin(0);
			else if (mys==8)
				inc=getOrque(0);
			else
				inc=getBaleine(0);
		}
		*(tab+k)=inc;
	}
}

void afficher(obj *tab, int n){
	int k;
	clrscreen();
	for (k=0;k<n*n;k++){
		printf("%i ", (tab+k)->type);
		if (k%n==n-1)
			printf("\n");
	}
	printf("\n");
}

void survie(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->satiete!=-1 && (tab+k)->dernier_repas!=-1 && (tab+k)->duree_survie!=-1){
			if ((tab+k)->satiete==0 && tour-((tab+k)->dernier_repas)>((tab+k)->duree_survie)){
				killObj(tab, k);
			}
		}
	}
}

void killObj(obj *tab, int place){
	*(tab+place)=getEau();
}

void reproduction(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if (apte(tab, k, tour)){
			int nvPlace=isPresent(tab, k, n, 0);
			if (nvPlace!=-1){
				(tab+k)->satiete -= (tab+k)->gestation*(tab+k)->metabolisme;
				*(tab+nvPlace)=getSameType(*(tab+k), tour);
			}
		}
	}
}

int apte(obj *tab, int place, int tour){
	int can=0;//ne peut pas se reproduire
	if ((tab+place)->frequence_reproduction!=-1){
		if ((tab+place)->derniere_reproduction+(tab+place)->frequence_reproduction<=tour){
			can=1;//peut se reproduire
			if ((tab+place)->type!=1){
				if ((tab+place)->satiete<(tab+place)->gestation*(tab+place)->metabolisme)
					can=0;
			}
		}
	}
	return can;
}

int isPresent(obj *tab, int place, int n, int nbType){
	int nvPlace=-1;
	if (place==0){
		if ((tab+1)->type==nbType)
			nvPlace=1;
		else if ((tab+n)->type==nbType)
			nvPlace=n;
		else if ((tab+n+1)->type==nbType)
			nvPlace=n+1;
	}
	else if (place==n-1){
		if ((tab+n-2)->type==nbType)
			nvPlace=n-2;
		else if ((tab+2*n-2)->type==nbType)
			nvPlace=2*n-2;
		else if ((tab+2*n-1)->type==nbType)
			nvPlace=2*n-1;
	}
	else if (place==n*n-n){
		if ((tab+n*n-2*n)->type==nbType)
			nvPlace=n*n-2*n;
		else if ((tab+n*n-2*n+1)->type==nbType)
			nvPlace=n*n-2*n+1;
		else if ((tab+n*n-n+1)->type==nbType)
			nvPlace=n*n-n+1;
	}
	else if (place==n*n-1){
		if ((tab+n*n-2)->type==nbType)
			nvPlace=n*n-2;
		else if ((tab+n*n-2-n)->type==nbType)
			nvPlace=n*n-2-n;
		else if ((tab+n*n-n-1)->type==nbType)
			nvPlace=n*n-n-1;
	}
	else if (place<n){
		if ((tab+place-1)->type==nbType)
			nvPlace=place-1;
		else if ((tab+place+1)->type==nbType)
			nvPlace=place+1;
		else if ((tab+place+n)->type==nbType)
			nvPlace=place+n;
		else if ((tab+place+n-1)->type==nbType)
			nvPlace=place+n-1;
		else if ((tab+place+n+1)->type==nbType)
			nvPlace=place+n+1;
	}
	else if (place>n*n-n){
		if ((tab+place-1)->type==nbType)
			nvPlace=place-1;
		else if ((tab+place+1)->type==nbType)
			nvPlace=place+1;
		else if ((tab+place-n)->type==nbType)
			nvPlace=place-n;
		else if ((tab+place-n-1)->type==nbType)
			nvPlace=place+n-1;
		else if ((tab+place-n+1)->type==nbType)
			nvPlace=place+n+1;
	}
	else if (place%n==0){
		if ((tab+place-n)->type==nbType)
			nvPlace=place-n;
		else if ((tab+place+n)->type==nbType)
			nvPlace=place+n;
		else if ((tab+place-n+1)->type==nbType)
			nvPlace=place-n+1;
		else if ((tab+place+n+1)->type==nbType)
			nvPlace=place+n+1;
		else if ((tab+place+1)->type==nbType)
			nvPlace=place+1;
	}
	else if (place%n==n-1){
		if ((tab+place-n)->type==nbType)
			nvPlace=place-n;
		else if ((tab+place+n)->type==nbType)
			nvPlace=place+n;
		else if ((tab+place-n-1)->type==nbType)
			nvPlace=place-n-1;
		else if ((tab+place+n-1)->type==nbType)
			nvPlace=place+n-1;
		else if ((tab+place-1)->type==nbType)
			nvPlace=place-1;
	}
	else {
		if ((tab+place-n)->type==nbType)
			nvPlace=place-n;
		else if ((tab+place+n)->type==nbType)
			nvPlace=place+n;
		else if ((tab+place-n-1)->type==nbType)
			nvPlace=place-n-1;
		else if ((tab+place+n-1)->type==nbType)
			nvPlace=place+n-1;
		else if ((tab+place-1)->type==nbType)
			nvPlace=place-1;
		else if ((tab+place-n+1)->type==nbType)
			nvPlace=place-n+1;
		else if ((tab+place+1)->type==nbType)
			nvPlace=place+1;
		else if ((tab+place+n+1)->type==nbType)
			nvPlace=place+n+1;
	}
	return nvPlace;
}

obj getSameType(obj oldObj, int tour){
	obj inc;
	int mys=oldObj.type;
	if (mys==0)
		inc=getEau();
	else if (mys==1)
		inc=getPlancton(tour);
	else if (mys==2)
		inc=getCorail(tour);
	else if (mys==3)
		inc=getBar(tour);
	else if (mys==4)
		inc=getThon(tour);
	else if (mys==5)
		inc=getPollution(tour);
	else if (mys==6)
		inc=getPyranha(tour);
	else if (mys==7)
		inc=getRequin(tour);
	else if (mys==8)
		inc=getOrque(tour);
	else if (mys==9)
		inc=getBaleine(tour);
	else if (mys==10)
		inc=getPecheur(tour);
	else
		inc=getPont();
	return inc;
}

void predation(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		int i=0;
		while (i<6 && (tab+k)->mange[i]!=-1){
			if ((tab+k)->dernier_repas<tour){
				int proie=isPresent(tab, k, n, (tab+k)->mange[i]);
				if (proie!=-1 && (tab+k)->satiete+(tab+proie)->taille<(tab+k)->taille_du_bide){
					(tab+k)->dernier_repas=tour;
					(tab+k)->satiete+=(tab+proie)->taille;
					*(tab+proie)=*(tab+k);
					*(tab+k)=getEau();
					i=6;
				}
			}
			else
				i=6;
			i++;
		}
	}
}

void deplacement(obj *tab, int n){
	int k;
	for (k=0;k<n*n;k++){
		int sm=(tab+k)->saut_max;
		if (sm>0 && isPresent(tab, k, n, 0)!=-1){
			//choisir une case aléatoirement
			int aleat=rand()%8+1;
			int caseLibre=0;
			if (aleat==1 && k-n-1>=0 && k%n>0 && (tab+k-n-1)->type==0)
				caseLibre=1;
			if (aleat==2)
				caseLibre=2;
			//se déplacer d'une case dans une certaine direction
			//mémoriser direction
			//pos=nouvelle position
			sm--;
			while (sm>0){
				//se déplacer dans la direction mémorisée si possible
				sm--;
			}
		}
	}
}
