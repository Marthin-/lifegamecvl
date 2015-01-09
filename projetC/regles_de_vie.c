#include <math.h>
#include <stdio.h>
#include <stdlib.h>//rand
#include <time.h>
#include "regles_de_vie.h"
#include "constantes.h"//getEau...

void killObj(obj *tab, int place){
	*(tab+place)=getEau();
}

void survie(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->satiete!=-1 && (tab+k)->dernier_repas!=-1 && (tab+k)->duree_survie!=-1){
			if ((tab+k)->satiete==0 && tour-((tab+k)->dernier_repas)>((tab+k)->duree_survie)){
				//printf("Type %i est mort en %i\n", (tab+k)->type, k);
				killObj(tab, k);
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

int isPresent(obj *tab, int place, int n, int nbType){//retourne les positions du type recherché en base 2
	/*
	   1  2  4
	   8     16
	   32 64 128
	 */
	int nvPlace=0;//retourne 0 si rien trouvé
	if (place>n && place%n!=0 && (tab+place-n-1)->type==nbType)
		nvPlace+=1;
	if (place>n-1 && (tab+place-n)->type==nbType)
		nvPlace+=2;
	if (place>n-1 && place%n!=n-1 && (tab+place-n+1)->type==nbType)
		nvPlace+=4;
	if (place%n!=0 && (tab+place-1)->type==nbType)
		nvPlace+=8;
	if (place%n!=n-1 && (tab+place+1)->type==nbType)
		nvPlace+=16;
	if (place<n*n-n && place%n!=0 && (tab+place+n-1)->type==nbType)
		nvPlace+=32;
	if (place<n*n-n && (tab+place+n)->type==nbType)
		nvPlace+=64;
	if (place<n*n-n && place%n!=n-1 && (tab+place+n+1)->type==nbType)
		nvPlace+=128;
	return nvPlace;
}

int deplDir(int pos, int dir, int n){//se déplacer à partir de la position pos dans la direction dir
	int nvpos=pos;
	if (dir==1)
		nvpos=pos-n-1;
	else if (dir==2)
		nvpos=pos-n;
	else if (dir==4)
                nvpos=pos-n+1;
	else if (dir==8)
                nvpos=pos-1;
	else if (dir==16)
                nvpos=pos+1;
	else if (dir==32)
                nvpos=pos+n-1;
	else if (dir==64)
                nvpos=pos+n;
	else if (dir==128)
                nvpos=pos+n+1;
	return nvpos;
}

int returnPlace(int is, int place, int n){//retourne une place aléatoire après la fonction isPresent2
	int nbcase=0;
	int bin=is;
	int k;
	for (k=0;k<8;k++){
		if (bin&1)
			nbcase++;
		bin=bin>>1;
	}
	if (!nbcase)
		return place;
	int aleat=rand()%nbcase+1;
	int nvPlace;
	int caseVue=0;
	bin=is;
	for (k=0;k<8; k++){
		if (bin&1)
			caseVue++;
		if (caseVue==aleat){
			nvPlace=pow(2, k);
			k=8;
		}
		bin=bin>>1;
	}
	nvPlace=deplDir(place, nvPlace, n);
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

void reproduction(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if (apte(tab, k, tour)){
			int is=isPresent(tab, k, n, 0);
			if (is!=0){
				int nvPlace=returnPlace(is, k, n);
//				printf("Type %i en %i s'est reproduit en %i\n", (tab+k)->type, k, nvPlace);
				(tab+k)->satiete -= (tab+k)->gestation*(tab+k)->metabolisme;
				*(tab+nvPlace)=getSameType(*(tab+k), tour);
			}
		}
	}
}

void predation(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		int i=0;
		while (i<6 && (tab+k)->mange[i]!=-1){
			if ((tab+k)->dernier_repas<tour){
				int proie=isPresent(tab, k, n, (tab+k)->mange[i]);
				if (proie!=0){
					proie=returnPlace(proie, k, n);
					if ((tab+proie)->taille+(tab+k)->satiete<=(tab+k)->taille_du_bide){
						(tab+k)->dernier_repas=tour;
						if ((tab+k)->type!=5)
							(tab+k)->satiete+=(tab+proie)->taille;
//						printf("Type %i en %i mange type %i en %i\n", (tab+k)->type, k, (tab+proie)->type, proie);
						/*if ((tab+k)->type==2)
							*(tab+proie)=getEau();
						else{*/
							*(tab+proie)=*(tab+k);
							*(tab+k)=getEau();
						//}
						i=6;
					}
				}
			}
			else
				i=6;
			i++;
		}
	}
}

int getDirection(int pos, int nvpos, int n){//retourne la direction déterminée par les deux positions données
	/*
	   1  2  4
	   8     16
	   32 64 128
	 */
	int dir;
	if (nvpos==pos-n-1)
		dir=1;
	else if (nvpos==pos-n)
		dir=2;
	else if (nvpos==pos-n+1)
		dir=4;
	else if (nvpos==pos-1)
		dir=8;
	else if (nvpos==pos+1)
		dir=16;
	else if (nvpos==pos+n-1)
		dir=32;
	else if (nvpos==pos+n)
		dir=64;
	else if (nvpos==pos+n+1)
		dir=128;
	else
		dir=0;//erreur
	return dir;
}

int continuerDir(obj * tab, int pos, int nvpos, int dir, int n){
	int sautRestant=(tab+pos)->saut_max-1;
	int next=nvpos;
	while (sautRestant>0){
		if ((tab+pos)->satiete>0 && dir&isPresent(tab, next, n, 0)){
			next=deplDir(next, dir, n);
			(tab+pos)->satiete--;
			sautRestant--;
		}
		else
			sautRestant=0;
	}
	return next;
}

void deplacement(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->saut_max>0 && ((tab+k)->satiete>0 || (tab+k)->type==5) && (tab+k)->dernier_deplacement!=tour){
			int is=isPresent(tab, k, n, 0);
			if (is){
				int nvpos=returnPlace(is, k, n);
				if ((tab+k)->type!=5)
					(tab+k)->satiete--;
				int dir=getDirection(k, nvpos, n);
				int fin=continuerDir(tab, k, nvpos, dir, n);
//				printf("Type %i en %i bouge en %i\n", (tab+k)->type, k, fin);
				(tab+k)->dernier_deplacement=tour;
                                *(tab+fin)=*(tab+k);
                                *(tab+k)=getEau();
			}
		}
	}
}

void augTour(obj *tab, int n){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->satiete!=-1 && (tab+k)->metabolisme!=-1)
			(tab+k)->satiete=max((tab+k)->satiete-(tab+k)->metabolisme, 0);
	}
}

int max(int a, int b){
	if (b>a)
		a=b;
	return a;
}

void checkDeath(obj *tab, int n, int tour, int *death, int *deathLength, int *deathDate){
	int k;
	int temp[9]={0,0,0,0,0,0,0,0,0};
	for (k=0;k<n*n;k++){
		if ((tab+k)->type>0 && (tab+k)->type<10)
			temp[(tab+k)->type-1]=1;
	}
	for (k=0;k<9;k++){
		if (temp[k]==0){
			int trouv=0;
			int i;
			for (i=0;i<*deathLength && !trouv;i++){
				if (*(death+i)==k+1)
					trouv=1;
			}
			if (!trouv){
				*(death+(*deathLength))=k+1;
				*(deathDate+(*deathLength))=tour;
				(*deathLength)++;
			}
		}
	}
}

void deathHistory(int *death, int deathLength, int *deathDate){
	int k;
	for (k=0;k<deathLength;k++){
		printf("L'espece %i a disparu au tour %i\n", *(death+k), *(deathDate+k));
	}
}

