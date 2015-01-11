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
	int choix=0;
	printf("=============================");
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
	printf("=============================");


	scanf("%i", &choix);	
	return choix;	
}


//tour du pecheur
obj* tour_pecheur(obj joueur){
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
			tableau_menu[1]=1;
			action=menu(tableau_menu);
			break;

		case(3):
			lancer_poisson(tab, joueur);
			tableau_menu[2]=1;
			action=menu(tableau_menu);
			break;

		case(4):
			construire_pont(tab, joueur);
			tableau_menu[3]=1;
			action=menu(tableau_menu);
			break;

		case(5):
			fin_tour_pecheur();
			break;	

		default:
			printf("entrez une option existante\n");
			action=menu_choix(tableau_menu);
			break;	
	}
	return (obj)joueur;	
}

deplacement_pecheur(obj* tab, obj joueur){
	printf("utilisez les touches z,q,s,d pour vous deplacer\n");
	char dpct;
	scanf("%c", &dpct);

	if (dpct=='z'){}


	return (obj*) map;
}	
