#ifndef HALMA_H
#define HALMA_H

typedef struct{
	int i;
	int j;
}
	Type_emplacement;

typedef struct{
	int num;
	char nom[15];
	char sym;
}
	Type_joueur;

void saisir_joueur(Type_joueur*,char);
void symbole_joueur(Type_joueur, char*);
void initialisation_plateau(char[10][10]);
void vider_buffer();
int saisie();
void regles();
void affiche_plateau(char[10][10]);
void change_joueur(Type_joueur* ,Type_joueur, Type_joueur);
void saisie_emplacement(Type_emplacement*);
int verification_selection(Type_emplacement,char[10][10], Type_joueur);
void selection_pion(Type_emplacement*, char[10][10], Type_joueur);
void destination_pion(Type_emplacement*, Type_joueur);
int verification_deplacement(Type_emplacement,Type_emplacement, char[10][10]);
void deplacement(Type_emplacement, Type_emplacement, char[10][10]);
void question_rejouer(int*);
void echange_valeurs(Type_emplacement *p,Type_emplacement *d);
void rejouer(int, Type_emplacement,Type_emplacement, int *, Type_joueur, char[10][10]);
int verification_victoire(char[10][10], Type_joueur);

#endif
