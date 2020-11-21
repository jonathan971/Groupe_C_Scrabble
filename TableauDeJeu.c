#include "TableauDeJeu.h"
#include "pickJetons.h"


void affichage_tableau_2D(char tab[MAX][MAX], int taille_logique){// Affichage lignes et colonnes
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

void creationchevalet(char tableau[], int taille_logique_deck,char lapioche[], int * modiftaillephysique) { // affichage chevalet
    int i;
    for (i = 0; i < taille_logique_deck-1; i++) {
        tableau[i]=pickJetons(lapioche, modiftaillephysique);
    }
}

void affichagechevalet(char tableau[], int taille_logique_deck, int occurrence_point[LIGNES][COLONNES]){
    int i;
    printf("\t\t");
    for(i=0;i<taille_logique_deck-1;i++) {
            printf("\t");
            printf("|");
            printf("%4c%d", tableau[i], occurrence_point[i][1]);
    }
    printf("\t");
    printf("|");
    printf("\n");
}