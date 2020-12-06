#include "joueur_initializer.h"

//initialisation du joueur
void intialisation_joueur(Joueur Player[], int *modiftaillephysique, char lapioche[], int *nb_joueur) {
    int i;
    do {
        printf("Combien il y a t-il de joueur ? (Entre 2 et 4 joueurs)\n");
        scanf(" %d", nb_joueur);
        printf("\n");
    } while (*nb_joueur < 2 || *nb_joueur > 4);
    for (i = 0; i < *nb_joueur; i++) {
        printf("Information Joueur %d :\n", i + 1);
        printf("Veuillez saisir votre pseudo :\n");
        scanf(" %s", Player[i].nom);
        Player[i].score = 0;
        for (int j = 0; j < MAX_DECK - 1; j++) {
            Player[i].chevalet_joueur[j] = pickJetons(lapioche, modiftaillephysique);
        }
        printf("Merci\n");
        printf("\n");
    }
}

//Lorsque le joueur aposé ses lettres, il doit re-remplir son chevalet et donc combler les lettres utilisés remplacer par "0" par de nouvelles lettres
void recharge_chevalet(Joueur Player[], int *modiftaillephysique, char lapioche[JETONS],const int *pi) {
    int k;
    for (k = 0; k < JETONS; k++) {
        for (int j = 0; j < MAX_DECK - 1; j++) {
            while ((Player[*pi].chevalet_joueur[j] == '0' ||
                    Player[*pi].chevalet_joueur[j] == 0) ||
                   (lapioche[k] < (char) 65 && lapioche[k] > (char) 90 && lapioche[k] != (char) JOKER)) {
                if (Player[*pi].chevalet_joueur[j] == '0' || Player[*pi].chevalet_joueur[j] == 0) {
                    Player[*pi].chevalet_joueur[j] = pickJetons(lapioche, modiftaillephysique);
                }
                if (lapioche[k] < (char) 65 && lapioche[k] > (char) 90 && lapioche[k] != (char) JOKER) {
                    printf("La pioche est vide !! Il n'y a plus de rechargement possible !!\n");
                }
            }
        }
    }
}

//Lorsque le joueur a un chevalet qui ne correspond pas à ses attentes, il peut changer les lettres de son chevalet
void echange_chevalet_pioche(Joueur Player[], int *modiftaillephysique, char lapioche[], int taille_logique_chevalet,
                             const char chevalet_joueur[MAX_DECK], const char *alphabet, const int *pi,char pchoixx[MAX_CHOIX],char pchoix1[MAX_CHOIX] , char pchoix2[MAX_CHOIX]) {
    char lettre1 = 0, lettre2 = 0;
    int k = 0, f = 0, valide = 0;
    char chaine_changement[2] = "0";
    do {
            if (strcmp( pchoixx, pchoix1) == 0) {
                printf("Quelle lettre voulez-vous echanger ? (en majuscule)\n");
                scanf(" %c", &lettre1);
                for (k = 0; k < taille_logique_chevalet; k++) {
                    while (f <= 100) {
                        printf("Recherche de la lettre : %d %c \n", f, 37);
                        f += 20;
                    }
                    if (lettre1 == chevalet_joueur[k] && lapioche!=0) {//verification que la lettre est presente sur le chevalet
                        printf("Le caractere saisi a été trouvé !!\n");
                        lettre2 = pickJetons(lapioche, modiftaillephysique);
                        chaine_changement[1] = lettre1;
                        lettre1 = lettre2;
                        lettre2 = chaine_changement[1];
                        Player[*pi].chevalet_joueur[k] = lettre1;
                        lapioche[FIN_PIOCHE+1]=lettre2;
                        printf("Changement réalisé avec succès\n"
                               "Vous verrez votre nouveau chevalet au tour prochain\n\n");
                        k = taille_logique_chevalet;
                        valide = 1;
                    }
                }
            }
            if (lettre1 != chevalet_joueur[k] && valide == 0) {
                valide = 0;
                if (k == taille_logique_chevalet - 1) {
                    f = 0;
                    printf("Le caractere saisi ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
                } else if (strcmp(pchoixx, pchoix2) == 0) {
                    //reprendre jeu
                } else {
                    printf("Reponse invalide, recommencez\n");
                    valide = 0;
                }
            }
    } while (valide != 1);
}