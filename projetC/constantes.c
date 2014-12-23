#include <stdlib.h>//malloc
#include "constantes.h"

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
        pt->dernier_repas=-1;//le plancton ne mange pas
        pt->satiete=-1;//infini
        pt->derniere_reproduction=tour;
        pt->duree_survie=-1;//infini
        pt->taille=3;
        pt->taille_du_bide=-1;//pas de bide
        pt->saut_max=-1;
        pt->dernier_deplacement=-1;
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
        pt->satiete=3;
        pt->derniere_reproduction=tour;
        pt->duree_survie=5;
        pt->taille=1;
        pt->taille_du_bide=5;
        pt->saut_max=0;
        pt->dernier_deplacement=-1;
        pt->metabolisme=1;
        pt->gestation=3;
        pt->frequence_reproduction=10;
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
        pt->frequence_reproduction=7;
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
        pt->dernier_deplacement=tour;
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
        pt->dernier_deplacement=tour;
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
        pt->dernier_deplacement=tour;
        pt->metabolisme=0;
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
        pt->dernier_deplacement=-1;
        pt->metabolisme=-1;
        pt->gestation=-1;
        pt->frequence_reproduction=-1;
        return *pt;
}

