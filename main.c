#include <stdio.h>
#include "Regle.h"
#include "Bienvenue.h"
#include "laPioche.h"
#include "Verification_chevalet.h"

int main() {
    unsigned int choix,jeu=1;
    int i,j;
    srand(time(NULL));
    int modiftaillephysique=0,occurrence_point[LIGNES][COLONNES];
    char alphabet[LIGNES+1], lapioche[JETONS];

    leSac(alphabet,lapioche,occurrence_point);
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
                for(i=0; i<1;i++) {
                    printf("%s, a vous :\n", Player.nom);
                    affichagechevalet(Player.chevalet_joueur, MAX_DECK, occurrence_point,alphabet);
                    printf("\n");
                    placementPremierMot(plateau_de_jeu, Player.chevalet_joueur);
                    //il va falloir une boucle pour tous les mots des joueurs pour la partie
                    placementMot(plateau_de_jeu, Player.chevalet_joueur);
                    //verification de l'existence de(s) nouveau(x) mot(s) cree(s) peut-etre en faisant une boucle do while et en demandant a la fin
                    //a un autre joueur (le suivant ou quoi) de confirmer le(s) mot(s) sinon il doit tout refaire
                    //ca reste toujours plus simple que d'ecrire tout le dictionnaire dans notre programme vu que ya pas de fonction <dico.h> ou quoi
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