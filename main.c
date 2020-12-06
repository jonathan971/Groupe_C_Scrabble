#include <stdio.h>
#include "Bienvenue.h"
#include "laPioche.h"
#include "Verification_chevalet.h"

int main() {
    unsigned int choix, jeu = 1, nbr_lettre = 0, nb_player = 0;
    int i = 0, j = 0;
    srand(time(NULL));
    int modiftaillephysique = 0, occurrence_point[LIGNES][COLONNES];
    char alphabet[LIGNES + 1], lapioche[JETONS];

    leSac(alphabet, lapioche, occurrence_point);
    Joueur Player[4] = {0};
    char plateau_de_jeu[MAX][MAX] = {{36, 32, 32, 38, 32, 32, 32, 36, 32, 32, 32, 38, 32, 32, 36},
                                     {32, 64, 32, 32, 32, 37, 32, 32, 32, 37, 32, 32, 32, 64, 32},
                                     {32, 32, 64, 32, 32, 32, 38, 32, 38, 32, 32, 32, 64, 32, 32},
                                     {38, 32, 32, 64, 32, 32, 32, 38, 32, 32, 32, 64, 32, 32, 38},
                                     {32, 32, 32, 32, 64, 32, 32, 32, 32, 32, 64, 32, 32, 32, 32},
                                     {32, 37, 32, 32, 32, 37, 32, 32, 32, 37, 32, 32, 32, 37, 32},
                                     {32, 32, 38, 32, 32, 32, 38, 32, 38, 32, 32, 32, 38, 32, 32},
                                     {36, 32, 32, 38, 32, 32, 32, 35, 32, 32, 32, 32, 32, 32, 36},
                                     {32, 32, 38, 32, 32, 32, 38, 32, 38, 32, 32, 32, 38, 32, 32},
                                     {32, 37, 32, 32, 32, 37, 32, 32, 32, 37, 32, 32, 32, 37, 32},
                                     {32, 32, 32, 32, 64, 32, 32, 32, 32, 32, 64, 32, 32, 32, 32},
                                     {38, 32, 32, 64, 32, 32, 32, 38, 32, 32, 32, 64, 32, 32, 38},
                                     {32, 32, 64, 32, 32, 32, 38, 32, 38, 32, 32, 32, 64, 32, 32},
                                     {32, 64, 32, 32, 32, 37, 32, 32, 32, 37, 32, 32, 32, 64, 32},
                                     {36, 32, 32, 38, 32, 32, 32, 36, 32, 32, 32, 38, 32, 32, 36}};
    bienvenue_jeu(&choix);
    switch (choix) {
        case 1:
            choix = 0;
            for ( i = 0; i < 20; ++i) {
                printf("_");
            }
            printf("\n");
            printf("                   1. COMMENCER UNE NOUVELLE PARTIE \n");
            printf("                   2. ACCEDER A UNE SAUVEGARDE \n");
            for ( i = 0; i < 20; ++i) {
                printf("_");
            }
            scanf("%d", &choix);
            switch (choix) {
                case 1:
                    intialisation_joueur(Player, &modiftaillephysique, lapioche, &nb_player);
                    printf("\t\t\t\t\t\t\t\t\t    DEBUT DE LA PARTIE\n");
                    do {
                        affichage_tableau_2D(plateau_de_jeu, MAX);
                        printf("\n");
                        for (i = 0; i < nb_player; i++) {
                            if (i >= 1) {
                                affichage_tableau_2D(plateau_de_jeu, MAX);
                                printf("\n");
                            }
                            printf("%s, a vous :\n", Player[i].nom);
                            affichagechevalet(Player[i].chevalet_joueur, MAX_DECK, occurrence_point, alphabet);
                            printf("\n");
                            choix = 0;
                            afficherMenuPendantPartie(&choix, &i, Player, &modiftaillephysique, lapioche, MAX_DECK,
                                                      Player[i].chevalet_joueur, occurrence_point, alphabet);
                            while (choix == 7) {
                                if (j == 0) {
                                    Player[i].score += placementPremierMot(plateau_de_jeu, Player[i].chevalet_joueur,
                                                                           &nbr_lettre, alphabet, occurrence_point);
                                }
                                if (j == 1) {
                                    Player[i].score += placementMot(plateau_de_jeu, Player[i].chevalet_joueur,
                                                                    &nbr_lettre, alphabet, occurrence_point);
                                }
                                j = 1;
                                printf("Score : %d\n\n", Player[i].score);
                                recharge_chevalet(Player, &modiftaillephysique, lapioche, &i);
                                choix = 0;
                            }
                            for (j = 0; j < JETONS; j++) {
                                if (lapioche[j] == 0 || plateau_de_jeu[i][j] != 0) {
                                    for (int k = 0; k < MAX_DECK; k++) {
                                        if (Player[i].chevalet_joueur[k] == 0) {
                                            printf("Fin de la partie\n");
                                            for (int g = 0; g < nb_player; g++) {
                                                if (Player[g].score > Player[g + 1].score) {
                                                    printf("%s TU REMPORTES LA PARTIE AVEC %d points\n", Player[g].nom,
                                                           Player[g].score);
                                                } else {
                                                    printf("%s TU REMPORTES LA PARTIE AVEC %d points\n",
                                                           Player[g + 1].nom, Player[g + 1].score);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        //faudra juste réafficher la pause et mettre continuer
                        //verification de l'existence de(s) nouveau(x) mot(s) cree(s) peut-etre en faisant une boucle do while et en demandant a la fin
                        //ca reste toujours plus simple que d'ecrire tout le dictionnaire dans notre programme vu que ya pas de fonction <dico.h> ou quoi
                    } while (jeu != 1);//jeu fini (il faudra changer la valeur à 0 quand on aura tout fini)
                    break;
                    break;
                case 2:
                    sauvegarde(Player, plateau_de_jeu, lapioche);
                    break;
                default:
                    break;
            }

        case 2:
            choix = 0;
            regle_jeu(&choix);
            break;
        case 3:
            credits(&choix);
        case 4:
        default:
            break;
    }
    return 0;
}

// le timer : on doit prendre la boucle du timer et la mettre dans la fonction saisir le mot pour que ca fonctionne
/*#include <time.h>
#include <stdio.h>
#define TIMER 2 // en minute

void timer(clock_t duree){
    clock_t time_out = clock();
    while((time_out + duree) > clock());
}


int main(){
    int i;
    for(i = 0; i <TIMER*60; i++){
        timer(1000);
        if(i==((TIMER*60)/2)-1){
            printf("Il vous reste %d secondes.\n",(TIMER*60)-(i+1));
        }
        if(i==((TIMER*60)*0.75)-1){
            printf("Il vous reste %d secondes.\n",(TIMER*60)-(i+1));
        }
        if(i==((TIMER*60)*11/12)-1){
            printf("Il vous reste %d secondes.\n",(TIMER*60)-(i+1));
        }
    }
    return 0;
}*/