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

void chevalet(char tableau[],pioche *Pioche, int taille_logique_deck){ // affichage chevalet
    int i;
    /*for(i=0;i<taille_logique_deck;i++){
        //faire le random pioche deck ICI
        scanf("%c",&tableau[i]);
    }*/
    for(i=0;i<taille_logique_deck;i++){
        printf("\t      |");
        printf("%4c",32/*tableau[i]*/);
    }
    printf("\n");
    printf("\n");
}


