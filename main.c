#include <stdio.h>
#include "Regle.h"
#include "Bienvenue.h"
#include "laPioche.h"


int main() {
    unsigned int choix,jeu=1;

    int i,j;
    srand(time(NULL));
    int modiftaillephysique=0,occurrence_point[LIGNES][COLONNES];
    char alphabet[LIGNES], lapioche[LIGNES+1];
    char tableau[MAX_DECK];
    laPioche( alphabet, lapioche, occurrence_point);
    for (i = 0; i < LIGNES; i++) {
        printf("%c", alphabet[i]);
        for (j = 0; j < COLONNES; j++) {
            if (j == 0) {
                printf("|%d", occurrence_point[i][j]);
            } else {
                printf("|%d|\n", occurrence_point[i][j]);
            }
        }
    }
    printf("\n");
    affichagechevalet(tableau, MAX_DECK, occurrence_point, alphabet);

    Joueur Player;
    char plateau_de_jeu[MAX][MAX]={{36,32,32,38,32,32,32,36,32,32,32,38,32,32,36},
                                   {32,64,32,32,32,37,32,32,32,37,32,32,32,64,32},
                                   {32,32,64,32,32,32,38,32,38,32,32,32,64,32,32},
                                   {38,32,32,64,32,32,32,38,32,32,32,64,32,32,38},
                                   {32,32,32,32,64,32,32,32,32,32,64,32,32,32,32},
                                   {32,37,32,32,32,37,32,32,32,37,32,32,32,37,32},
                                   {32,32,38,32,32,32,38,32,38,32,32,32,38,32,32},
                                   {36,32,32,38,32,'P','L','A','N','E','T',32,32,32,36},
                                   {32,32,38,32,32,32,38,32,38,32,32,32,38,32,32},
                                   {32,37,32,32,32,37,32,32,32,37,32,32,32,37,32},
                                   {32,32,32,32,64,32,32,32,32,32,64,32,32,32,32},
                                   {38,32,32,64,32,32,32,38,32,32,32,64,32,32,38},
                                   {32,32,64,32,32,32,38,32,38,32,32,32,64,32,32},
                                   {32,64,32,32,32,37,32,32,32,37,32,32,32,64,32},
                                   {36,32,32,38,32,32,32,36,32,32,32,38,32,32,36}};
    bienvenue_jeu(&choix);
    switch (choix) {
        case 1:
            intialisation_joueur(&Player, &modiftaillephysique, lapioche);
            printf("\t\t\t\t\t\t\t\t\t    DEBUT DE LA PARTIE\n");
            do {
                affichage_tableau_2D(plateau_de_jeu, MAX);
                printf("\n");
                for(int i=0; i<1;i++) {
                    printf("%s, a vous :\n", Player.nom);
                    affichagechevalet(Player.chevalet_joueur, MAX_DECK, occurrence_point,alphabet);
                    printf("\n");
                }
                afficherMenuPendantPartie(&choix);
                /*do {
                    if (choix == 2) {
                        do {
                    }while(choix==1 && (compteur_de_lettre>1 && compteur_de_lettre<7));
                        //fonction qui recharge le chevalet
                    }
                }while (choix == 2);*/
            }while (jeu!=1);//jeu fini (il faudra changer la valeur à 0 quand on aura tout fini)
            break;
        case 2:
            choix=0;
            regle_jeu(&choix);
            break;
        case 3:
            credits(&choix);
        case 4:
            break;
        default:break;
    }
    return 0;
}
