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
		if ((tab+k)->type>1 && (tab+k)->type<10 && (tab+k)->type!=5){
			if ((tab+k)->satiete==0 && tour-((tab+k)->dernier_repas)>((tab+k)->duree_survie)){
				//printf("Type %i est mort en %i\n", (tab+k)->type, k);
				killObj(tab, k);
			}
		}
	}
}

obj getSameType(obj oldObj, int tour){
	obj inc;
	int mys=oldObj.type;
	if (mys==1)
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
		inc=getPont();
	else if (mys==11)
		inc=getSol();
	else if (mys==12)
		inc=getPont_pecheur();
	else if (mys==13)
		inc=getSol_pecheur();
	else if (mys==14)
		inc=getEau_pecheur();
	else
		inc=getEau();
	return inc;
}

void reproduction_plancton(obj * tab, int pos, int n, int tour){
	int is=isPresent(tab, pos, n, 0);
	if (is){
		int nvPlace=returnPlace(is, pos, n);
		//printf("Type %i en %i s'est reproduit en %i\n", (tab+k)->type, k, nvPlace);
		*(tab+nvPlace)=getPlancton(tour);
	}
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

void reproduction(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type>0 && (tab+k)->type<10 && (tab+k)->type!=5){
			if ((tab+k)->type==1)
				reproduction_plancton(tab, k, n, tour);
			else if ((tab+k)->satiete>=(tab+k)->gestation*(tab+k)->metabolisme && (tab+k)->derniere_reproduction+(tab+k)->frequence_reproduction<=tour){
				int is=isPresent(tab, k, n, 0);
				if (is){
					int nvPlace=returnPlace(is, k, n);
					//printf("Type %i en %i s'est reproduit en %i\n", (tab+k)->type, k, nvPlace);
					(tab+k)->satiete -= (tab+k)->gestation*(tab+k)->metabolisme;
					*(tab+nvPlace)=getSameType(*(tab+k), tour);
				}
			}
		}
	}
}

void predation_pollution(obj * tab, int pos, int n, int tour){
	if ((tab+pos)->dernier_repas<tour){
		int proie=isPresent(tab, pos, n, 2);
		if (proie){
			proie=returnPlace(proie, pos, n);
			(tab+pos)->dernier_repas=tour;
			//printf("Type %i en %i mange type %i en %i\n", (tab+k)->type, k, (tab+proie)->type, proie);
			*(tab+proie)=*(tab+pos);
			*(tab+pos)=getEau();
		}
	}

}

void predation(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type>1 && (tab+k)->type<10){// && (tab+k)->type!=5){
			if ((tab+k)->type==5)
				predation_pollution(tab, k, n, tour);
			else {
				int i=0;
				while (i<6 && (tab+k)->mange[i]!=-1){
					if ((tab+k)->dernier_repas<tour){
						int proie=isPresent(tab, k, n, (tab+k)->mange[i]);
						if (proie){
							proie=returnPlace(proie, k, n);
							if ((tab+proie)->taille+(tab+k)->satiete<=(tab+k)->taille_du_bide){
								(tab+k)->dernier_repas=tour;
								(tab+k)->satiete+=(tab+proie)->taille;
								//printf("Type %i en %i mange type %i en %i\n", (tab+k)->type, k, (tab+proie)->type, proie);
								*(tab+proie)=*(tab+k);
								*(tab+k)=getEau();
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

void deplacement_pollution(obj * tab, int pos, int n, int tour){
	if ((tab+pos)->dernier_deplacement!=tour){
		int is=isPresent(tab, pos, n, 0);
		if (is){
			int nvpos=returnPlace(is, pos, n);
			//printf("Type %i en %i bouge en %i\n", (tab+k)->type, k, fin);
			(tab+pos)->dernier_deplacement=tour;
			*(tab+nvpos)=*(tab+pos);
			*(tab+pos)=getEau();
		}
	}	
}

void deplacement(obj *tab, int n, int tour){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type>2 && (tab+k)->type<10){
			if ((tab+k)->type==5)
				deplacement_pollution(tab, k, n, tour);
			else if ((tab+k)->satiete>0 && (tab+k)->dernier_deplacement!=tour){
				int is=isPresent(tab, k, n, 0);
				if (is){
					int nvpos=returnPlace(is, k, n);
					(tab+k)->satiete--;
					int dir=getDirection(k, nvpos, n);
					int fin=continuerDir(tab, k, nvpos, dir, n);
					//printf("Type %i en %i bouge en %i\n", (tab+k)->type, k, fin);
					(tab+k)->dernier_deplacement=tour;
					*(tab+fin)=*(tab+k);
					*(tab+k)=getEau();
				}
			}
		}
	}
}

void augTour(obj *tab, int n){
	int k;
	for (k=0;k<n*n;k++){
		if ((tab+k)->type>1 && (tab+k)->type<10 && (tab+k)->type!=5)
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

