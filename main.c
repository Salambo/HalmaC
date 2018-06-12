#include <stdio.h>
#include "halma.h"

int main(void){
  	char tableau[10][10];
  	int verification,rejoue=0;
	Type_emplacement p /*position pion*/,d /*position destination*/;
	Type_joueur joueur1,joueur2, joueur /*joueur durant le tour*/;
	char sym=' ';
    	printf("Bienvenue au jeu de l'Halma! \n");
	joueur1.num=1;
	saisir_joueur(&joueur1, sym); /*saisit du profil du joueur dont le numéro est 1*/
	joueur2.num=2;
	saisir_joueur(&joueur2,sym); /*saisit du profil du joueur dont le numéro est 2*/
  	initialisation_plateau(tableau); /*création du tableau nécéssaire a l'affichage et aux changements du plateau*/
  	regles(); /* affichage des règles si l'un des joueurs le souhaite*/
  	joueur=joueur2;
	affiche_plateau(tableau); /*affiche le plateau*/
    do
    {
		change_joueur(&joueur,joueur1,joueur2); /*change de joueur*/
		do
        {
			selection_pion(&p,tableau,joueur); /* séléctionne le pion a déplacer*/
			destination_pion(&d,joueur); /*selectionne la destination souhaitée*/
			verification=verification_deplacement(p,d,tableau); /*vérifie si le déplacement est possible*/
        }
        while(verification<0); /*effectue les saisies temps que le déplacement n'est pas possible*/
        deplacement(p,d,tableau); /*effectue le déplacement*/
		affiche_plateau(tableau); /*affiche le plateau après déplacement*/
		if(verification==3) /*Si le joueur a fait un saut...*/
        {
           rejouer(rejoue, p, d, &verification, joueur, tableau); /*... il peut rejouer*/
        }
    }
	while(verification_victoire(tableau, joueur)!=15); /*vérifie si il y a une victoire et continue temps qu'il n'y en a pas */
	printf("%s a gagne! Felicitations \n", joueur.nom); /*affiche le vainqueur*/

  	return 0;
}
