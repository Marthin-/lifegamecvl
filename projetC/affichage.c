#include <stdio.h>
#include "affichage.h"

#define esc 27
void clearScreen (){
        printf("%c[2J%c[H" , esc , esc);
}

void afficher(obj *tab, int n, int tour){
        int k;
        clearScreen();
        for (k=0;k<n*n;k++){
		char sym;
		if ((tab+k)->type==0)
			sym='~';
		else if ((tab+k)->type==1)
			sym='.';
		else if ((tab+k)->type==2)
			sym='%';
		else if ((tab+k)->type==3)
			sym='b';
		else if ((tab+k)->type==4)
			sym='T';
		else if ((tab+k)->type==5)
			sym='&';
		else if ((tab+k)->type==6)
			sym='p';
		else if ((tab+k)->type==7)
			sym='R';
		else if ((tab+k)->type==8)
			sym='O';
		else if ((tab+k)->type==9)
			sym='B';
		else if ((tab+k)->type==10)
			sym='@';
		else if ((tab+k)->type==11)
			sym='H';
		else if ((tab+k)->type==12)
			sym='X';
		else
			sym='?';//erreur
                printf("%c ", sym);
		if (k==n*n-1)
                        printf("  Tour %i", tour);
                if (k%n==n-1)
                        printf("\n");
        }
        printf("\n");
}

void afficher2(obj *tab, int n, int tour){
        int k;
	clearScreen();
        for (k=0;k<n*n;k++){
                printf("%i ", (tab+k)->type);
		if (k==n*n-1)
			printf("  Tour %i", tour);
                if (k%n==n-1)
                        printf("\n");
        }
        printf("\n");
}

void printsdl(obj *tab, int n, int tour){
	
}

