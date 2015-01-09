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
//                              printf("Type %i est mort en %i\n", (tab+k)->type, k);
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

int isPresent(obj *tab, int place, int n, int nbType){
        int nvPlace=-1;
        if (place>n-1 && (tab+place-n)->type==nbType)
                nvPlace=place-n;
        else if (place<n*n-n && (tab+place+n)->type==nbType)
                nvPlace=place+n;
        else if (place>n && place%n!=0 && (tab+place-n-1)->type==nbType)
                nvPlace=place-n-1;
        else if (place<n*n-n && place%n!=0 && (tab+place+n-1)->type==nbType)
                nvPlace=place+n-1;
        else if (place%n!=0 && (tab+place-1)->type==nbType)
                nvPlace=place-1;
        else if (place>n-1 && place%n!=n-1 && (tab+place-n+1)->type==nbType)
                nvPlace=place-n+1;
        else if (place%n!=n-1 && (tab+place+1)->type==nbType)
                nvPlace=place+1;
        else if (place<n*n-n && place%n!=n-1 && (tab+place+n+1)->type==nbType)
                nvPlace=place+n+1;
        return nvPlace;
}

int isPresent2(obj *tab, int place, int n, int nbType){//retourne les positions du type recherché en base 2
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
	printf("caseVue : %i\nnv : %i\n", caseVue, nvPlace);
	if (nvPlace==1)
		nvPlace=place-n-1;
	else if (nvPlace==2)
		nvPlace=place-n;
	else if (nvPlace==4)
		nvPlace=place-n+1;
	else if (nvPlace==8)
		nvPlace=place-1;
	else if (nvPlace==16)
		nvPlace=place+1;
	else if (nvPlace==32)
		nvPlace=place+n-1;
	else if (nvPlace==64)
		nvPlace=place+n;
	else if (nvPlace==128)
		nvPlace=place+n+1;
	printf("place : %i\nnbcase : %i\nnv : %i\n", place, nbcase, nvPlace);
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
                        int nvPlace=isPresent(tab, k, n, 0);
                        if (nvPlace!=-1){
                                (tab+k)->satiete -= (tab+k)->gestation*(tab+k)->metabolisme;
                                *(tab+nvPlace)=getSameType(*(tab+k), tour);
//                              printf("Type %i en %i s'est reproduit en %i\n", (tab+k)->type, k, nvPlace);
                        }
                }
        }
}

void reproduction2(obj *tab, int n, int tour){
        int k;
        for (k=0;k<n*n;k++){
                if (apte(tab, k, tour)){
			int is=isPresent2(tab, k, n, 0);
			if (is!=0){
				int nvPlace=returnPlace(is, k, n);
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
                                if (proie!=-1 && (tab+proie)->taille+(tab+k)->satiete<=(tab+k)->taille_du_bide){
                                        (tab+k)->dernier_repas=tour;
                                        if ((tab+k)->type!=5)
                                                (tab+k)->satiete+=(tab+proie)->taille;
//                                      printf("Type %i en %i mange type %i en %i\n", (tab+k)->type, k, (tab+proie)->type, proie);
                                        if ((tab+k)->type==2)
                                                *(tab+proie)=getEau();
                                        else{
                                                *(tab+proie)=*(tab+k);
                                                *(tab+k)=getEau();
                                        }
                                        i=6;
                                }
                        }
                        else
                                i=6;
                        i++;
                }
        }
}

void deplacement(obj *tab, int n, int tour){
        int k;
        for (k=0;k<n*n;k++){
                int sm=0;
                int nextpos=0;
                while (sm<(tab+k)->saut_max && ((tab+k)->satiete>0 || (tab+k)->type==5) && (tab+k)->dernier_deplacement!=tour && isPresent(tab, k+nextpos, n, 0)!=-1){
                        if (nextpos==0){
                                int pos=0;
                                while(pos==0){
                                        int aleat=rand()%8+1;
                                        if (aleat==1 && k>=n && k%n!=0 && (tab+k-n-1)->type==0)
                                                pos=-n-1;
                                        else if (aleat==2 && k>=n && (tab+k-n)->type==0)
                                                pos=-n;
                                        else if (aleat==3 && k>=n && k%n!=n-1 && (tab+k-n+1)->type==0)
                                                pos=1-n;
                                        else if (aleat==4 && k%n!=0 && (tab+k-1)->type==0)
                                                pos=-1;
                                        else if (aleat==5 && k%n!=n-1 && (tab+k+1)->type==0)
                                                pos=1;
                                        else if (aleat==6 && k%n!=0 && k<n*n-n && (tab+k+n-1)->type==0)
                                                pos=n-1;
                                        else if (aleat==7 && k<n*n-n && (tab+k+n)->type==0)
                                                pos=n;
                                        else if (aleat==8 && k<n*n-n && k%n!=n-1 && (tab+k+n+1)->type==0)
                                                pos=n+1;
                                }
                                nextpos=pos;
                        }
                        else {
                                //bouger dans la meme direction si possible
                                if (nextpos==-(n+1)*sm && k+nextpos>n && (k+nextpos)%n!=0 && (tab+k+nextpos-n-1)->type==0)
                                        nextpos+=-n-1;
                                else if (nextpos==-n*sm && k+nextpos>=n && (tab+k+nextpos-n)->type==0)
                                        nextpos+=-n;
                                else if (nextpos==(1-n)*sm && k+nextpos>=n && (k+nextpos)%n!=n-1 && (tab+k+nextpos-n+1)->type==0)
                                        nextpos+=1-n;
                                else if (nextpos==-sm && (k+nextpos)%n!=0 && (tab+k+nextpos-1)->type==0)
                                        nextpos-=1;
                                else if (nextpos==sm && (k+nextpos)%n!=n-1 && (tab+k+nextpos+1)->type==0)
                                        nextpos+=1;
                                else if (nextpos==(n-1)*sm && (k+nextpos)%n!=0 && (k+nextpos)<n*n-n && (tab+k+nextpos+n-1)->type==0)
                                        nextpos+=n-1;
                                else if (nextpos==n*sm && (k+nextpos)<n*n-n && (tab+k+nextpos+n)->type==0)
                                        nextpos+=n;
                                else if (nextpos==(n+1)*sm && (k+nextpos)%n!=n-1 && (k+nextpos)<n*n-n && (tab+k+nextpos+n+1)->type==0)
                                        nextpos+=n+1;
                                else {
                                        sm=(tab+k)->saut_max-1;
                                        (tab+k)->satiete++;
                                }
                        }
                        if ((tab+k)->type!=5)
                                (tab+k)->satiete--;
                        sm++;
                        if (sm==(tab+k)->saut_max){
//                              printf("Type %i en %i bouge en %i\n", (tab+k)->type, k, k+nextpos);
                                (tab+k)->dernier_deplacement=tour;
                                *(tab+k+nextpos)=*(tab+k);
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

