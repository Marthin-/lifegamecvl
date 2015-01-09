#include <stdio.h>//printf
#include <stdlib.h>//rand
#include "constantes.h"//getEau...
#include "remplir.h"

void remplir(obj *tab, int n, int nbj){
	int k;
	int pourcentage[9]={30,45,55,60,65,70,77,84,91};
	int check=1;
	for (k=0;k<8;k++){
		if (pourcentage[k]>pourcentage[k+1])
			check=0;
	}
	if (check){
		for (k=0;k<n*n;k++){
			int aleat=rand()%100;
			obj inc;
			if (nbj && k%n==0){
				inc=getPecheur(0);
				nbj--;
			}
			else if (k%n==0 || k%n==n-1)
				inc=getSol();
			else if (aleat<pourcentage[0])
				inc=getEau();
			else if (aleat<pourcentage[1])
				inc=getPlancton(0);
			else if (aleat<pourcentage[2])
				inc=getCorail(0);
			else if (aleat<pourcentage[3])
				inc=getBar(0);
			else if (aleat<pourcentage[4])
				inc=getThon(0);
			else if (aleat<pourcentage[5])
				inc=getPollution(0);
			else if (aleat<pourcentage[6])
				inc=getPyranha(0);
			else if (aleat<pourcentage[7])
				inc=getRequin(0);
			else if (aleat<pourcentage[8])
				inc=getOrque(0);
			else
				inc=getBaleine(0);
			*(tab+k)=inc;
		}
	}
	else {
		printf("Attention ! Especes mal reparties, modifiez le tableau de pourcentage dans la fonction remplir.\n");
		for (k=0;k<n*n;k++){
			*(tab+k)=getEau();
		}
	}
}

