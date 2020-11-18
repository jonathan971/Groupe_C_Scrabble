#include "joueur_initializer.h"
//initialisation du joueur
void intialisation_joueur(Joueur Player,unsigned int *nb_joueur) {
    int i;
    do {
        printf("Combien il y a t-il de joueur ? (Le maximum est de 4 joueurs)\n");
        scanf("%d", nb_joueur);
        printf("\n");
        printf("\n");
    }while(*nb_joueur>4);
    for(i=0;i<*nb_joueur;i++){
        printf("Information Joueur %d :\n",i+1);
        printf("Veuillez saisir votre nom :\n");
        scanf(" %s",Player.nom);
        printf("Merci\n");
        printf("\n");
        printf("\n");
    }
    Player.score=0;
}


