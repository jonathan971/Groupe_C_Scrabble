#include "joueur_initializer.h"
//initialisation du joueur
void intialisation_joueur(Joueur Player[],unsigned int *nb_joueur, char tableau[]) {
    int i;
    do {
        printf("Combien il y a t-il de joueur ? (Le maximum est de 4 joueurs)\n");
        scanf("%d", nb_joueur);
        printf("\n");
        printf("\n");
    }while(*nb_joueur>4);
    for(i=0;i<*nb_joueur;i++){
        printf("Information Joueur %d :\n",i+1);
        printf("Veuillez saisir votre pseudo :\n");
        scanf(" %s",Player[i].nom);
        Player[i].score=0;
        Player[i].temps=1;
        creationchevalet(tableau, MAX_DECK);
        printf("Merci\n");
        printf("\n");
        printf("\n");
    }
}


