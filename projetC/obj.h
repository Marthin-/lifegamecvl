
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
	int metabolisme;
	int gestation;
	int frequence_reproduction;
}obj;

obj getEau();//0
obj getPlancton(int tour);//1
obj getCorail(int tour);//2
obj getBar(int tour);//3
obj getThon(int tour);//4
obj getPollution(int tour);//5
obj getPyranha(int tour);//6
obj getRequin(int tour);//7
obj getOrque(int tour);//8
obj getBaleine(int tour);//9
obj getPecheur(int tour);//10
obj getPont();//11

void remplir(obj *tab, int n);
void afficher(obj *tab, int n);
void survie(obj *tab, int n, int tour);
void killObj(obj *tab, int place);
void reproduction(obj *tab, int n, int tour);
int apte(obj *tab, int place, int tour);
int isPresent(obj *tab, int place, int n, int nbType);
obj getSameType(obj inc, int tour);

void predation(obj *tab, int n, int tour);
void deplacement(obj *tab, int n);
