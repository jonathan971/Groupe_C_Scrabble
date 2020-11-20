#include <stdio.h>
#include "Regle.h"
#include "Bienvenue.h"
#include "laPioche.h"


int main() {
    unsigned int choix, nb_player=0, valide=0, jeu=1;
    char lettre;
    Joueur Player;
    int occurrence_point[LIGNES][COLONNES];
    char chevalet_joueur[MAX_DECK]={36};
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
            intialisation_joueur(&Player,&nb_player,chevalet_joueur);
            printf("\t\t\t\t\t\t\t\t\t    DEBUT DE LA PARTIE\n");
            do {
                affichage_tableau_2D(plateau_de_jeu, MAX);
                printf("\n");
                /*for(int i=0; i<1;i++) {
                    printf("%s a vous\n", Player[i].nom);
                }//Utiliser le nom du joueur (pointeur sur nom joeur)*/
                affichagechevalet(chevalet_joueur,MAX_DECK,occurrence_point);
                printf("\n");
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
