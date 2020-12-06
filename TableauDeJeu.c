#include "TableauDeJeu.h"


void affichage_tableau_2D(char tab[MAX][MAX], int taille_logique){// Affichage lignes et colonnes
    int i,j;
    puts("\n      A     B     C     D     E     F     G     H     I     J     K     L     M     N     O");
    for(i=0;i<taille_logique;i++){
        printf("%2d ",i+1);
        printf("|");
        for(j=0;j<taille_logique;j++){
            if(tab[i][j]==(char)36){
                printf("  ");
                printf(ANSI_COLOR_BLUE"%c"ANSI_COLOR_RESET, tab[i][j]);
                printf("  ");
                printf("|");
            }
            else if (tab[i][j]==(char)38) {
                printf("  ");
                printf(ANSI_COLOR_MAGENTA"%c"ANSI_COLOR_RESET, tab[i][j]);
                printf("  ");
                printf("|");
            }
            else if(tab[i][j]==(char)37){
                printf("  ");
                printf(ANSI_COLOR_GREEN"%c"ANSI_COLOR_RESET, tab[i][j]);
                printf("  ");
                printf("|");
            }
            else if (tab[i][j]==(char)64) {
                printf("  ");
                printf(ANSI_COLOR_RED"%c"ANSI_COLOR_RESET, tab[i][j]);
                printf("  ");
                printf("|");

            }
            else if (tab[i][j]==(char)35) {
                printf("  ");
                printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET, tab[i][j]);
                printf("  ");
                printf("|");

            }
            else {
                printf("  ");
                printf("%c", tab[i][j]);
                printf("  ");
                printf("|");

            }
        }
        printf("\n");
    }
}

void affichagechevalet(char tableau[], int taille_logique_deck, int occurence_point[LIGNES][COLONNES], const char* alphabet){
    int i,j,scorelettre=0;
    printf("\t\t");
    for(i=0;i<taille_logique_deck-1;i++) {
        for(j=0;j<LIGNES;j++){
            if(tableau[i]==alphabet[j]){
                scorelettre=occurence_point[j][1];
            }
        }
        printf("\t");
        printf("|");
        printf("%3c %d", tableau[i], scorelettre);
    }
    printf("\t");
    printf("|");
    printf("\n");
}