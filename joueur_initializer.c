#include "joueur_initializer.h"

//initialisation du joueur
void intialisation_joueur(Joueur Player[], int*modiftaillephysique,char lapioche[]) {
    int i, nb_joueur=0;
    do {
        printf("Combien il y a t-il de joueur ? (Entre 2 et 4 joueurs)\n");
        scanf(" %d", &nb_joueur);
        printf("\n");
    }while(nb_joueur<2 || nb_joueur>4);
    for(i=0;i<nb_joueur;i++){
        printf("Information Joueur %d :\n",i+1);
        printf("Veuillez saisir votre pseudo :\n");
        scanf(" %s",Player[i].nom);
        Player[i].score=0;
        for(int j=0;j<MAX_DECK-1;j++) {
            Player[i].chevalet_joueur[j]=pickJetons(lapioche, modiftaillephysique);
        }
        printf("Merci\n");
        printf("\n");
    }
}


