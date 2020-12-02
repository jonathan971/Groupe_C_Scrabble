#include <stdio.h>
#include "Regle.h"
#include "Bienvenue.h"
#include "laPioche.h"
#include "Verification_chevalet.h"
#define MAX_DECK 7
#define MAX 15

void placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]){ //pour le tout premier mot du jeu
    char sensMot = '0';
    int nombreLettres = 0;
    nombreLettres = nombreDeLettres();
    sensMot = sensDuMot();
    placementPremiereLettrePremierMot(nombreLettres, plateau_de_jeu, chevalet_joueur);
    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            placementVertical(nombreLettres, plateau_de_jeu, chevalet_joueur);
        case 'h':
            placementHorizontal(nombreLettres, plateau_de_jeu, chevalet_joueur);
            break;
    }
}

void placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]){ //pous tous les autres mots du jeu
    char sensMot = '0';
    int nombreLettres = 0;
    nombreLettres = nombreDeLettres();
    sensMot = sensDuMot();
    placementPremiereLettre(plateau_de_jeu);
    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            placementVertical(nombreLettres, plateau_de_jeu, chevalet_joueur);
        case 'h':
            placementHorizontal(nombreLettres, plateau_de_jeu, chevalet_joueur);
            break;
    }
}

int main() {
    unsigned int choix,jeu=1;

    int i,j;
    srand(time(NULL));
    int modiftaillephysique=0,occurrence_point[LIGNES][COLONNES];
    char alphabet[LIGNES], lapioche[LIGNES+1];
    char tableau[MAX_DECK];
    leSac( alphabet, lapioche, occurrence_point);
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
                    placementPremierMot(plateau_de_jeu, tableau);
                    //il va falloir une boucle pour tous les mots des joueurs pour la partie
                    placementMot(plateau_de_jeu, tableau);
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
