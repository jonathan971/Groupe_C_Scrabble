#include <stdio.h>
#include "Bienvenue.h"
#include "laPioche.h"
#include "Verification_chevalet.h"

void jeu_complet(Joueur Player[], int *modiftaillephysique, char lapioche[], unsigned int *nb_player, unsigned int *choix,
            int occurrence_point[LIGNES][COLONNES], char alphabet[], char plateau_de_jeu[MAX][MAX], unsigned int *jeu,unsigned int *nbr_lettre) {
    int i=0,j=0;
    switch (*choix) {
        case 1:
            intialisation_joueur(Player, modiftaillephysique, lapioche,nb_player);
            printf("\t\t\t\t\t\t\t\t\t    DEBUT DE LA PARTIE\n");
            do {
                affichage_tableau_2D(plateau_de_jeu, MAX);
                printf("\n");
                for(i=0; i<*nb_player;i++) {
                    if (i >= 1) {
                        affichage_tableau_2D(plateau_de_jeu, MAX);
                        printf("\n");
                    }
                    printf("%s, a vous :\n", Player[i].nom);
                    affichagechevalet(Player[i].chevalet_joueur, MAX_DECK, occurrence_point, alphabet);
                    printf("\n");
                    afficherMenuPendantPartie(choix, &i, Player, modiftaillephysique, lapioche, MAX_DECK,
                                              Player[i].chevalet_joueur, occurrence_point, alphabet);
                    while (*choix == 7) {
                        if (j == 0) {
                            Player[i].score+=placementPremierMot(plateau_de_jeu, Player[i].chevalet_joueur, nbr_lettre, alphabet, occurrence_point);
                        }
                        if (j == 1) {
                            Player[i].score+=placementMot(plateau_de_jeu, Player[i].chevalet_joueur, nbr_lettre, alphabet, occurrence_point);
                        }
                        j=1;
                        printf("Score : %d\n\n",Player[i].score);
                        recharge_chevalet(Player, modiftaillephysique, lapioche,&i);
                        choix=0;
                    }
                }

                printf("Fin jeu : tapper 1\n"
                       "Continuer jeu : tapper 0\n"),
                        scanf("%d", jeu);

                //faudra juste réafficher la pause et mettre continuer
            }while (*jeu!=1);//jeu fini (il faudra changer la valeur à 0 quand on aura tout fini)
            break;
        case 2:
            choix=0;
            regle_jeu(choix);
            break;
        case 3:
            credits(choix);
        case 4:
        default:break;
    }
}
int main() {
    unsigned int choix,jeu=1,nb_player=0,nbr_lettre=0;
    int i=0,j=0;
    srand(time(NULL));
    int modiftaillephysique=0,occurrence_point[LIGNES][COLONNES];
    char alphabet[LIGNES+1], lapioche[JETONS];

    leSac(alphabet,lapioche,occurrence_point);
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
    bienvenue_jeu(&choix);
    jeu_complet(Player, &modiftaillephysique, lapioche, &nb_player,&choix,
    occurrence_point, alphabet, plateau_de_jeu, &jeu, &nbr_lettre);
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