#include "Bienvenue.h"
void bienvenue_jeu(unsigned int *choix){//Affichage du Menu avec le style d'affichage
    for (int i = 0; i < 20; ++i) {
        printf("_");
    }
    printf("Bienvenue");
    for (int i = 0; i < 20; ++i) {
        printf("_");
    }
    printf("\n");
    printf("                   1. JOUER \n");
    printf("                   2. REGLES DU JEU \n");
    printf("                   3. CREDITS \n");
    printf("                   4. QUITTER \n") ;
    for (int i = 0; i < 49; ++i) {
        printf("_");
    }
    printf("\n");
    scanf("%d",choix);
}

void afficherMenuPendantPartie(unsigned int *choix,int *pi, Joueur Player[], int *modiftaillephysique,
                               char lapioche[],int taille_logique_chevalet,char chevalet_joueur[MAX_DECK],
                               int occurence_point[LIGNES][COLONNES], const char* alphabet,
                               char plateau_de_jeu[][MAX],int* nb_player, int* i){
    int n_lettre=0;
    char choixx[MAX_CHOIX] = "0",choix1[MAX_CHOIX] = "oui", choix2[MAX_CHOIX] = "non";
    *choix=0;
    do {
        printf("1-Pause\n"
               "2-Continuer la partie\n"
               "3-Changer ses lettres\n"
               "0-Quitter le jeu\n"
               "Saisir votre choix\n");
        scanf("%d", choix);
    }while (*choix>3);
    switch (*choix) {
        case 1:
            //arreter le chronometre
            *choix=0;
            do{
                printf("1-Reprendre la partie\n"
                       "2-Afficher les regles\n"
                       "3-Sauvegarder et Quitter la partie\n"
                       "0-Quitter la partie\n");
                scanf("%d", choix);}while (*choix>2);
            printf("\n");
            switch (*choix) {
                case 1:
                        *choix = 7;
                    break;
                case 2:
                    regle_jeu(choix);
                    do{
                        printf("Revenir au sommaire?\n");
                        printf("1-Oui\n");
                        printf("2-Non\n");
                        scanf("%d",choix);
                        if(*choix==1){
                            *choix=0;
                            regle_jeu(choix);
                        }
                        else if (*choix==2){
                                *choix = 7;
                        }}while (*choix>2);
                    break;
                case 3:
                    //sauvegarder(Player, plateau_de_jeu, lapioche, nb_player, i, (const int *) &modiftaillephysique);
                    break;
                default:break;
            }
            break;
        case 2:
            *choix=0;
            do {
                printf("Etes-vous passez par \"3-Changer ses lettres\" ?\n"
                       "1-oui\n"
                       "2-non\n"
                       "Saisir le chiffre de votre choix\n");
                scanf("%d",choix);
            }while (*choix!=1 && *choix!=2);
            if(*choix==2) {
                *choix = 7;
            }
            else{
                printf("%s c'est la fin de votre tour !\n",Player[*pi].nom);
            }
            break;
        case 3 :
            *choix=0;

            do {
                printf("Voulez-vous changer une lettre avec une de la pioche ?\n"
                       "Tappez \"oui\" si oui sinon tappez \"non\"\n");
                scanf("%s", choixx);
            } while (strcmp(choixx, choix1) != 0 && strcmp(choixx, choix2) != 0);
            do {
                printf("Combien de lettre voulez vous échangez ?\n");
                scanf("%d", &n_lettre);
            }while (n_lettre<0 && n_lettre>7 );
            do {
                echange_chevalet_pioche(Player, modiftaillephysique, lapioche, taille_logique_chevalet, chevalet_joueur, alphabet, pi, choixx,choix1,choix2);
                n_lettre-=1;
            }while (n_lettre!=0);
            afficherMenuPendantPartie(choix,pi,Player, modiftaillephysique, lapioche,MAX_DECK, chevalet_joueur,
                                      occurence_point, alphabet,plateau_de_jeu,nb_player,i);
            break;
        case 0:
            break;
        default:break;
    }
}

