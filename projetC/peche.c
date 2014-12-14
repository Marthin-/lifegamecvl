#include <stdio.h>
#include <stdlib.h>
#include "obj.h"

/*TODO deplacement pecheur
pecher
lancer poisson
construire pont
*/

//choisir l'action du pecheur via un menu
int menu_choix(int* tableau){
	int fin=tableau[4];
	int deplacer=tableau[0];
	int pecher=tableau[1];
	int lancer=tableau[2];
	int construire=tableau[3];
	int choix=5;
		while(fin!=1){
			if(!deplacer){
				printf("\n1 : se deplacer\n");
			}
			if(!pecher){
				printf("2 : pecher\n");
			}
			if(!lancer){
				printf("3 : lancer\n");
			}
			if(!construire){
				printf("4 : construire\n");
			}	
			printf("5 : fin\n");
		}
	scanf("%i", &choix);	
return choix;	
}


//tour du pecheur
void tour_pecheur(obj* joueur){
	int i=0;
	int action;
	int* tableau_menu=malloc(5*sizeof(int));
		for(i=0;i<4;i++){
			tableau_menu[i]=0;
		}	
	action=menu_choix(tableau_menu);
	switch(action){
		case(1):
			deplacement_pecheur(tab, joueur);
			tableau_menu[0]=1;
			action=menu_choix(tableau_menu);
		break;

		case(2):
			pecher(tab, joueur);
			tableau_menu[0]=1;
			action=menu(tableau_menu);
		break;
	}
}
