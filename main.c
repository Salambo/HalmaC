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
	saisir_joueur(&joueur1, sym); /*saisit du profil du joueur dont le num�ro est 1*/
	joueur2.num=2;
	saisir_joueur(&joueur2,sym); /*saisit du profil du joueur dont le num�ro est 2*/
  	initialisation_plateau(tableau); /*cr�ation du tableau n�c�ssaire a l'affichage et aux changements du plateau*/
  	regles(); /* affichage des r�gles si l'un des joueurs le souhaite*/
  	joueur=joueur2;
	affiche_plateau(tableau); /*affiche le plateau*/
    do
    {
		change_joueur(&joueur,joueur1,joueur2); /*change de joueur*/
		do
        {
			selection_pion(&p,tableau,joueur); /* s�l�ctionne le pion a d�placer*/
			destination_pion(&d,joueur); /*selectionne la destination souhait�e*/
			verification=verification_deplacement(p,d,tableau); /*v�rifie si le d�placement est possible*/
        }
        while(verification<0); /*effectue les saisies temps que le d�placement n'est pas possible*/
        deplacement(p,d,tableau); /*effectue le d�placement*/
		affiche_plateau(tableau); /*affiche le plateau apr�s d�placement*/
		if(verification==3) /*Si le joueur a fait un saut...*/
        {
           rejouer(rejoue, p, d, &verification, joueur, tableau); /*... il peut rejouer*/
        }
    }
	while(verification_victoire(tableau, joueur)!=15); /*v�rifie si il y a une victoire et continue temps qu'il n'y en a pas */
	printf("%s a gagne! Felicitations \n", joueur.nom); /*affiche le vainqueur*/

  	return 0;
}
