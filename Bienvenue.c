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

void afficherMenuPendantPartie(unsigned int *choix){
    do {
        printf("1-Pause\n"
               "2-Continuer la partie\n"
               "0-Quitter\n"
               "Saisir votre choix\n");
        scanf("%d", choix);
    }while (*choix>2);
    switch (*choix) {
        case 1:
            //arreter le chronometre
            *choix=0;
            do{
                printf("1-Reprendre la partie\n"
                       "2-Afficher les regles\n"
                       "0-Quitter la partie\n");
                scanf("%d", choix);}while (*choix>2);
            printf("\n");
            switch (*choix) {
                case 1:
                    *choix=7;
                case 2:
                    regle_jeu(choix);
                    do{
                        printf("Revenir au sommaire?\n");
                        printf("1-Oui\n");
                        printf("2-Non\n");
                        scanf("%d",choix);
                        if(*choix==1){
                            choix=0;
                            regle_jeu(choix);
                        }
                        else if (*choix==2){
                            //reviens au jeu
                        }}while (*choix==2);
                case 0:
                    //terminer le programme --> return 0
                    break;
            }
            break;
        case 2:
            *choix=2;
            break;
        case 0:
            //terminer le programme --> return 0
            break;
    }
}

