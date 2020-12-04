#include <stdio.h>
#include "Regle.h"
#include "Bienvenue.h"
#include "laPioche.h"
#include "Verification_chevalet.h"

int main() {
    unsigned int choix,jeu=1,nbr_lettre=0,nb_player=0;
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
            intialisation_joueur(Player, &modiftaillephysique, lapioche,&nb_player);
            printf("\t\t\t\t\t\t\t\t\t    DEBUT DE LA PARTIE\n");
            do {
                affichage_tableau_2D(plateau_de_jeu, MAX);
                printf("\n");
                for(i=0; i<nb_player;i++) {
                    if (i>=1) {
                        affichage_tableau_2D(plateau_de_jeu, MAX);
                        printf("\n");
                    }
                    printf("%s, a vous :\n", Player[i].nom);
                    affichagechevalet(Player[i].chevalet_joueur, MAX_DECK, occurrence_point, alphabet);
                    printf("\n");
                    //afficherMenuPendantPartie(&choix);
                        //while (choix==7){
                        if(i==0) {
                            placementPremierMot(plateau_de_jeu, Player[i].chevalet_joueur, &nbr_lettre);
                        }
                        //mettre une pause
                            //rechargement du chevalet
                        //}
                        if (i>=1){
                            placementMot(plateau_de_jeu, Player[i].chevalet_joueur,&nbr_lettre);
                        }
                    }
                printf("Fin jeu : tapper 1\n"
                       "Continuer jeu : tapper 0\n"),
                       scanf("%d",&jeu);//faudra juste réafficher la pause et mettre continuer
                    //il va falloir une boucle pour tous les mots des joueurs pour la partie

                    //verification de l'existence de(s) nouveau(x) mot(s) cree(s) peut-etre en faisant une boucle do while et en demandant a la fin
                    //a un autre joueur (le suivant ou quoi) de confirmer le(s) mot(s) sinon il doit tout refaire
                    //ca reste toujours plus simple que d'ecrire tout le dictionnaire dans notre programme vu que ya pas de fonction <dico.h> ou quoi
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