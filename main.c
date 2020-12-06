#include <stdio.h>
#include "Bienvenue.h"
#include "laPioche.h"
#include "Verification_chevalet.h"

int main() {
    unsigned int choix,jeu=1,nbr_lettre=0;
    int i=0,j=0,nb_player=0;
    srand(time(NULL));
    int modiftaillephysique=0,occurrence_point[LIGNES][COLONNES];
    char alphabet[LIGNES+1], lapioche[JETONS];

    leSac(alphabet,lapioche,occurrence_point); //fichier : laPioche
    Joueur Player[4]={0};
    char plateau_de_jeu[MAX][MAX]={{36,32,32,38,32,32,32,36,32,32,32,38,32,32,36},
                                   {32,64,32,32,32,37,32,32,32,37,32,32,32,64,32},
                                   {32,32,64,32,32,32,38,32,38,32,32,32,64,32,32},
                                   {38,32,32,64,32,32,32,38,32,32,32,64,32,32,38},
                                   {32,32,32,32,64,32,32,32,32,32,64,32,32,32,32},
                                   {32,37,32,32,32,37,32,32,32,37,32,32,32,37,32},
                                   {32,32,38,32,32,32,38,32,38,32,32,32,38,32,32},
                                   {36,32,32,38,32,32,32,35,32,32,32,32,32,32,36},
                                   {32,32,38,32,32,32,38,32,38,32,32,32,38,32,32},
                                   {32,37,32,32,32,37,32,32,32,37,32,32,32,37,32},
                                   {32,32,32,32,64,32,32,32,32,32,64,32,32,32,32},
                                   {38,32,32,64,32,32,32,38,32,32,32,64,32,32,38},
                                   {32,32,64,32,32,32,38,32,38,32,32,32,64,32,32},
                                   {32,64,32,32,32,37,32,32,32,37,32,32,32,64,32},
                                   {36,32,32,38,32,32,32,36,32,32,32,38,32,32,36}};
    bienvenue_jeu(&choix);//fichier : Bienvenue
    switch (choix) {
        case 1:
            intialisation_joueur(Player, &modiftaillephysique, lapioche,&nb_player);//fichier :joueur_initializer
            printf("\t\t\t\t\t\t\t\t\t    DEBUT DE LA PARTIE\n");
            do {
                affichage_tableau_2D(plateau_de_jeu, MAX);//fichier : TableauDeJeu
                printf("\n");
                for(i=0; i<nb_player;i++) {
                    if (i >= 1) {
                        affichage_tableau_2D(plateau_de_jeu, MAX);//fichier : TableauDeJeu
                        printf("\n");
                    }
                    printf("%s, a vous :\n", Player[i].nom);
                    affichagechevalet(Player[i].chevalet_joueur, MAX_DECK, occurrence_point, alphabet);//fichier : TableauDeJeu
                    printf("\n");
                    choix=0;
                    afficherMenuPendantPartie(&choix, &i, Player, &modiftaillephysique, lapioche, MAX_DECK,
                                              Player[i].chevalet_joueur, occurrence_point, alphabet,plateau_de_jeu, &nb_player, &i);//fichier : Bienvenue
                    while (choix == 7) {
                        if (j == 0) {
                            Player[i].score+=placementPremierMot(plateau_de_jeu, Player[i].chevalet_joueur, &nbr_lettre, alphabet, occurrence_point);//fichier :Verification_chevalet
                        }
                        if (j == 1) {
                            Player[i].score+=placementMot(plateau_de_jeu, Player[i].chevalet_joueur, &nbr_lettre, alphabet, occurrence_point);//fichier : Verification_chevalet
                        }
                        j=1;
                        printf("Score : %d\n\n",Player[i].score);
                        recharge_chevalet(Player, &modiftaillephysique, lapioche,&i);//fichier : joueur_initializer
                        choix=0;
                    }
                }

                printf("Fin jeu : tapper 0\n"
                       "Continuer jeu : tapper 1\n"),
                        scanf("%d", &jeu);
            }while (jeu!=0);
            break;
        case 2:
            choix=0;
            regle_jeu(&choix);
            break;
        case 3:
            credits(&choix);
        case 4:
        default:break;
    }
    return 0;
}