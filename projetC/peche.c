#include <stdio.h>
#include <stdlib.h>
#include "obj.h"

/*TODO deplacement pecheur
pecher
lancer poisson
construire pont
*/

//choisir l'action du pecheur via un menu
int menu_choix(){
	int fin=0;;
	int deplacer=0;
	int pecher=0;
	int lancer=0;
	int construire=0;

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

return choix;	
}


//tour du pecheur
void tour_pecheur(obj* joueur){
	int action;
	action=menu_choix();
	switch(action){
		case(1):
			deplacement_pecheur(tab, joueur);
