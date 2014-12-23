#ifndef OBJ_H
#define OBJ_H

typedef struct {
        int type;//0:eau, 1:plancton, 2:corail, 3:bar...
        int mange[6];
        int dernier_repas;
        int satiete;
        int derniere_reproduction;
        int duree_survie;
        int taille;
        int taille_du_bide;
        int saut_max;
        int dernier_deplacement;
        int metabolisme;
        int gestation;
        int frequence_reproduction;
}obj;

#endif
