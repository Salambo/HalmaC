#include "halma.h"
#include <stdio.h>

/**
 *Initialise un joueur
 *@param Type_joueur  Données d'un joueur
 *@param char le symbole
**/
void saisir_joueur(Type_joueur* joueur, char sym)
{
    printf("Choisissez un nom joueur %d :", joueur->num);
	scanf("%s", joueur->nom);
	symbole_joueur(*joueur, &sym);
	printf(" Votre symbole est le: %c\n",sym);
	joueur->sym=sym;
}


/**
 *Attribue un symbole à un joueur
 *@param Type_joueur  Données d'un joueur
 *@param char* le symbole
**/
void symbole_joueur(Type_joueur joueur, char *sym)
{
    if(joueur.num==1)
    {
		*sym='O';
	}
	else
	{
		*sym='X';
    }
}



/**
 * Initialise le plateau de jeu
 * @param char[][] le plateau
**/
void initialisation_plateau(char tableau[10][10])
{
    int i, j, n;
    for(j=0; j<10; j++)
    {
        for(i=0;i<10;i++)
        {
            tableau[i][j]=' ';
        }
    }
   	for(j=0,n=4; j<5; j++,n--)
    {
        for(i=n; i>=0; i--)
        {
            tableau[9-i][9-j]='X';
            tableau[i][j]='O';
       	}
   	}
}


/**
 *Vide le buffer
**/
void vider_buffer()

{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


/**
 Permet de faire un saisie de chiffre
**/
int saisie()
{
    int a;
    scanf("%i", &a);
    vider_buffer();
    return a;
}


/**
 *Permet d'afficher ou non les regles du jeu
**/
void regles()
{
    int a;
    printf("Voulez-vous lire les regles? 1:Oui 2:Non \n");
    a=saisie();
    if(a==1)
    {
        printf("Chaque joueur deplace un pion a tour de role. Lors de son tour de jeu, un joueur doit deplacer un de ses pions de deux facons : \n -se deplacer sur une case voisine libre, dans toutes les directions \n -sauter par-dessus un autre pion, adverse ou non.\nPour pouvoir sauter, le pion doit se trouver sur une case contigue a une case occupee par un autre pion. \nIl peut sauter la piece, verticalement, horizontalement ou en diagonale, a condition que la case suivante soit vide. \nOn peut enchainer plusieurs sauts au cours du meme tour, meme en changeant de direction. \nToutefois, il est interdit de cumuler dans un meme coup un saut et un deplacement simple.\nLe joueur qui reussit a placer tous ses pions dans le camp de son adversaire gagne la partie. \n");
    }
}


/**
 *Affiche le plateau de jeu
 *@param char[][] le plateau
 **/
void affiche_plateau(char tableau[10][10]){
  int i, j;
   printf("      0   1   2   3   4   5   6   7   8   9   \n");
    printf("    +---+---+---+---+---+---+---+---+---+---+\n");
for(j=0; j<10; j++)
  {printf("  %d ",j);
printf("|");
    for(i=0;i<10;i++)

    	{
      printf (" %c |", tableau[i][j]);
	}
 printf(" %d",j);
printf("\n    +---+---+---+---+---+---+---+---+---+---+\n");

    }
    printf("      0   1   2   3   4   5   6   7   8   9  \n");
}


/**
 *Changement de joueur
 *@param Type_joueur  Données du joueur qui joue durant ce tour
 *@param Type_joueur  Données du joueur1
 *@param Type_joueur  Données du joueur2
**/
void change_joueur(Type_joueur *joueur, Type_joueur joueur1, Type_joueur joueur2)
{
	if(joueur->num==joueur1.num)
    {
		*joueur=joueur2;
	}
	else
	{
		*joueur=joueur1;
	}
    printf("A votre tour %s! \n", joueur->nom);
}


/**
 *Permet de sélectionner une case du plateau
 *@param Type_emplacement* coordonnées d'une case du tableau
**/
void saisie_emplacement(Type_emplacement *d)
{
    do
    {
        printf("Quel est le numero de la colonne? \n");
        (d->i)=saisie();
    }
    while((d->i)!=0 && (d->i)!=1 && (d->i)!=2 && (d->i)!=3 && (d->i)!=4 && (d->i)!=5 && (d->i)!=6 && (d->i)!=7 && (d->i)!=8 && (d->i)!=9);
    do
    {
        printf("Quel est le numero de la ligne? \n");
        (d->j)=saisie();
    }
    while((d->j)!=0 && (d->j)!=1 && (d->j)!=2 && (d->j)!=3 && (d->j)!=4 && (d->j)!=5 && (d->j)!=6 && (d->j)!=7 && (d->j)!=8 && (d->j)!=9);
}


/**
 *Verifie la sélection du pion, retourne -1 si le contenu choisit par le joueur n'est pas l'un de ses pions, 1 si c'est un de ses pions
 *@param Type_emplacement coordonnées de la case du tableau où se situe le pion sélectionné
 *@param char[][] le plateau
 *@param Type_joueur  Données du joueur qui joue durant ce tour
**/
int verification_selection(Type_emplacement p,char tableau[10][10],Type_joueur joueur)
{

	if (tableau[p.i][p.j]!=joueur.sym)
	{
		printf ("Vous n'avez pas selectionne un de vos pions. Vos pions sont les %c\n", joueur.sym);
		return -1;
	}
	else return 1;
}


/**
 *Le joueur selectionne une case jusqu'à ce que l'un de ses pions soit dessus
 *@param Type_emplacement* coordonnées de la case du tableau où se situe le pion sélectionné
 *@param char[][] le plateau
 *@param Type_joueur  Données du joueur qui joue durant ce tour
**/
void selection_pion(Type_emplacement *p, char tableau[10][10], Type_joueur joueur)
 {
    do
    {
        printf("Selectionnez votre pion %s : %c \n", joueur.nom, joueur.sym);
        saisie_emplacement(&(*p));
    }
    while(verification_selection(*p,tableau,joueur)<0);
}


/**
 *Le joueur selectionne la case sur laquelle il souhaite déplacer son pion
 *@param Type_emplacement* coordonnées de la case du tableau de la destination souhaitée du pion
 *@param Type_joueur  Données du joueur qui joue durant ce tour
**/
void destination_pion(Type_emplacement *d, Type_joueur joueur)
 {
     printf("Selectionnez l'endroit ou votre pion ira %s : %c \n", joueur.nom, joueur.sym);
     saisie_emplacement(&(*d));
}


/**
 *Verifie si le déplacement souhaité est conforme aux règles du jeu, retourne un chiffre négatif si il y a une erreur dans le choix de la destination et positif si il n'y en a pas
 *@param Type_emplacement coordonnées de la case du tableau où se situe le pion sélectionné
 *@param Type_emplacement coordonnées de la case du tableau de la destination souhaitée du pion
 *@param char[][] le plateau
**/

int verification_deplacement(Type_emplacement p,Type_emplacement d, char tableau[10][10])
{
    if (tableau[d.i][d.j]!=' ')
    {
        printf ("Le deplacement est impossible car la case ou vous souhaitez aller n'est pas vide \n");
        return -2;
    }
    else
	{
		if ((p.i-d.i)*(p.i-d.i)<=1 && (p.j-d.j)*(p.j-d.j)<=1)
		{
			printf ("C'est un deplacement simple\n");
            return 2;
		}

		else if ((p.i-d.i)*(p.i-d.i)+(p.j-d.j)*(p.j-d.j)==4 || (p.i-d.i)*(p.i-d.i)+(p.j-d.j)*(p.j-d.j)==8 )
		{
            if (tableau[(p.i+d.i)/2][(p.j+d.j)/2]!='-')
            {
                printf ("C'est un deplacement saut \n");
                return 3;
            }
            if (tableau[(p.i+d.i)/2][(p.j+d.j)/2]=='-')
            {
                printf ("Ce saut est impossible car un saut necessite un pion entre votre pion et votre destination \n");
                return -3;
            }
		}
		else
		{
            printf ("Ce deplacement est impossible ce n'est ni un saut ni un deplacement simple \n");
            return -4;
		}
	}
	return 0;
}


/**
 *Echange le contenu des deux cases choisies
 *@param Type_emplacement coordonnées de la case du tableau où se situe le pion sélectionné
 *@param Type_emplacement coordonnées de la case du tableau de la destination souhaitée du pion
 *@param char[][] le plateau
**/
void deplacement(Type_emplacement p,Type_emplacement d, char tableau[10][10])
{
    tableau[d.i][d.j]=tableau[p.i][p.j];
    tableau[p.i][p.j]=' ';
}

/**
 *Demande au joueur si il désire rejouer
 *@param int* reponse du joueur
**/
void question_rejouer(int *rejoue)
{

        do
        {
            printf("Voulez-vous rejouer? 1:Oui 2:Non \n");
            *rejoue=saisie();
        }
        while(*rejoue!=1 && *rejoue!=2);
}


/**
 *Le Type_emplacement p prend la valeur du Type_emplacement d
 *@param Type_emplacement coordonnées de la case du tableau où se situait le pion
 *@param Type_emplacement coordonnées de la case du tableau où se situe le pion actuellement
**/
void echange_valeurs(Type_emplacement *p,Type_emplacement *d)
{
    p->i=d->i;
    p->j=d->j;
}


/**
 *Permet de faire rejouer jusqu'à ce qui reponde non à la question rejouer
 *@param int reponse du joueur
 *@param Type_emplacement coordonnées de la case du tableau où se situait le pion
 *@param Type_emplacement coordonnées de la case du tableau où se situe le pion actuellement
 *@param int* resultat de la vérification du déplacement, permet de savoir si le déplacement choisi est un saut
 *@param Type_joueur  Données du joueur qui joue durant ce tour
 *@param char[][] le plateau
**/
void rejouer(int rejoue, Type_emplacement p,Type_emplacement d, int *verification, Type_joueur joueur, char tableau[10][10])
{
    question_rejouer(&rejoue);
    echange_valeurs(&p, &d);
    while(rejoue!=2)
    {

        printf ("Votre pion est le [%d][%d]\n", p.i,p.j);
        destination_pion(&d,joueur);
        if(verification_deplacement(p,d,tableau)!=3)
        {
            printf("Ce saut n'est pas possible.\n");
        }
        else
        {
            deplacement(p,d,tableau);
            affiche_plateau(tableau);
            echange_valeurs(&p, &d);
        }
        question_rejouer(&rejoue);
    }
}


/**
 *Verifie si le joueur a gagné
 *@param char[][] le plateau
 *@param Type_joueur  Données du joueur qui joue durant ce tour
**/
int verification_victoire(char tableau[10][10],  Type_joueur joueur)
{
    int n=4, i, j;
    int victoire=0;
    for(j=0; j<5; j++)
    {
        for(i=n; i>=0; i--)
        {
            if (joueur.num==1)
            {
                if(tableau[9-i][9-j]==joueur.sym)
                {
                   victoire=victoire+1;
                }
            }
            else
            {
                if(tableau[i][j]==joueur.sym)
                {
                    victoire=victoire+1;
                }
            }

        }
        n--;
   	}
    return victoire;
}
