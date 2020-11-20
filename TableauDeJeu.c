#include "TableauDeJeu.h"

void affichage_tableau_2D(char tab[MAX][MAX],int taille_logique){// Affichage lignes et colonnes
    int i,j;
    puts("\n      A     B     C     D     E     F     G     H     I     J     K     L     M     N     O");
    for(i=0;i<taille_logique;i++){
        printf("%2d ",i+1);
        printf("|");
        for(j=0;j<taille_logique;j++){
            printf(" %4c", tab[i][j]);
            printf("|");
        }

        printf("\n");
    }
}

void creationchevalet(char tableau[], int taille_logique_deck) { // affichage chevalet
    int i;
    int occurrence_point[LIGNES][COLONNES] = {{0}};
    char alphabet[LIGNES], lapioche[JETONS];
    for (i = 0; i < taille_logique_deck; i++) {
        tableau[i]=laPioche(alphabet, lapioche, occurrence_point);

    }
}

void affichagechevalet(char tableau[], int taille_logique_deck){
    int i;
    for(i=0;i<taille_logique_deck;i++){
        printf("\t      |");
        printf("%4c",tableau[i]);
    }
    printf("\n");
    printf("\n");
}


