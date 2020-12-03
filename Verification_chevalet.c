#include "Verification_chevalet.h"

void placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],
                         unsigned int *pnombreLettres) { //pour le tout premier mot du jeu
    char sensMot = 0;
    *pnombreLettres = nombreDeLettres();
    sensMot = sensDuMot();
    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            do {
                placementPremiereLettrePremierMot(pnombreLettres, plateau_de_jeu, chevalet_joueur, MAX_DECK);
                placementVertical(pnombreLettres, plateau_de_jeu, chevalet_joueur);
                pnombreLettres--;
            } while (*pnombreLettres != 0);
        case 'h':
            do {
                placementPremiereLettrePremierMot(pnombreLettres, plateau_de_jeu, chevalet_joueur, MAX_DECK);
                placementHorizontal(pnombreLettres, plateau_de_jeu, chevalet_joueur);
                pnombreLettres--;
            } while (*pnombreLettres != 0);
            break;
        default:
            break;
    }
}

void placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],
                  unsigned int *pnombreLettres) { //pous tous les autres mots du jeu
    char sensMot = '0';
    *pnombreLettres = nombreDeLettres();
    sensMot = sensDuMot();

    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            do {
                placementPremiereLettre(plateau_de_jeu);
                placementVertical(pnombreLettres, plateau_de_jeu, chevalet_joueur);
                pnombreLettres--;
            } while (*pnombreLettres != 0);
        case 'h':
            do {
                placementPremiereLettre(plateau_de_jeu);
                placementHorizontal(pnombreLettres, plateau_de_jeu, chevalet_joueur);
                pnombreLettres--;
            } while (*pnombreLettres != 0);
            break;
        default:
            break;
    }
}

int nombreDeLettres() {
    int nombreLettres = 0;
    do {
        printf("Combien de lettres souhaitez-vous placer?\n");
        scanf("%d", &nombreLettres);
    } while (nombreLettres < 0 || nombreLettres > 7);
    return nombreLettres;
}

char sensDuMot() {
    char sensMot = '0';
    do {
        printf("Saisissez \"v\" pour placer votre mot a la verticale et \"h\" pour l'horizontale.\n");
        scanf(" %c", &sensMot);
    } while (sensMot != 'v' && sensMot != 'h');
    return sensMot;
}

void placementPremiereLettrePremierMot(unsigned int *pnombreLettres, char plateau_de_jeu[MAX][MAX],
                                       char chevalet_joueur[MAX_DECK], int taille_logique_chevalet) {
    char lettreAPlacer = 0;
    int k = 0, f = 0, valide = 0;
    do {  //verification que le caractere est bien une lettre
        printf("Vous commencez la partie.\n");
        do {
            printf("Saisissez la lettre que vous souhaitez poser sur la case du milieu (P.S :(Ligne = 7; Colonne = 7)):\n");
            scanf(" %c", &lettreAPlacer);
            while (f != 100) {
                f += 20;
                printf("Recherche du mot : %d %c \n", f, 37);
            }
            for (k = 0; k < taille_logique_chevalet; k++) {
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    plateau_de_jeu[7][7] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = 0;//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois
                    valide = 1;
                    k = taille_logique_chevalet + 1;
                }
                if (lettreAPlacer != chevalet_joueur[k] && k == taille_logique_chevalet) {
                    if (lettreAPlacer != chevalet_joueur[k]) {
                        printf("Le caractere saisi ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
                        valide = 0;
                    }
                }
            }
        } while (valide != 1);

        if (islower(lettreAPlacer == 0) && isupper(lettreAPlacer == 0)) {
            printf("Le caractere saisi ne correspond pas a une lettre. Veuillez recommencer:\n");
        }
    } while (islower(lettreAPlacer) == 0 && isupper(lettreAPlacer == 0));
}

void placementPremiereLettre(char plateau_de_jeu[MAX][MAX]) {
    int i = 0, j = 0;
    char e = 65, b = 90; //J'ai pas compter le jocker
    do {
        printf("Saisissez la case dans laquelle vous souhaitez commencer votre mot:\n");
        scanf("%d %d", &i, &j);
        if (plateau_de_jeu[i][j] > e && plateau_de_jeu[i][j] < b) {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }
    } while (plateau_de_jeu[i][j] > e && plateau_de_jeu[i][j] < b);
}

void placementVertical(unsigned int *pnombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]) {
    int i = 0, j = 0;
    char e = 65, b = 90; //J'ai pas compter le jocker
    printf("Prochaine lettre\n"
           "Saisissez le numero de la colonne (A=0 B=1...)\n");
    scanf("%d", &j);
    do {
        printf("Saisissez le numero de la case suivante (deuxieme composant de la case)\n");
        scanf("%d", &i); //[i] pour que le mot soit ecrit vers le bas comme [j] ne change pas
        i -= 1;
        if (plateau_de_jeu[i][j] > e && plateau_de_jeu[i][j] < b) {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }

        placementAutreLettre(pnombreLettres, i, j, plateau_de_jeu, chevalet_joueur, MAX_DECK);
    } while (plateau_de_jeu[i][j] > e && plateau_de_jeu[i][j] < b);
}

void placementAutreLettre(unsigned int *pnombreLettres, int i, int j, char plateau_de_jeu[MAX][MAX],
                          char chevalet_joueur[MAX_DECK], int taille_logique_chevalet) {
    int k, f = 0, valide = 0;
    char lettreAPlacer = 0;
    do {
        do { //verification que le caractere est bien une lettre
            printf("Saisissez la lettre que vous souhaitez placer:\n");
            scanf(" %c", &lettreAPlacer);
            while (f != 100) {
                f += 20;
                printf("Recherche du mot : %d %c \n", f, 37);
            }
            for (k = 0; k < taille_logique_chevalet; k++) {
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    plateau_de_jeu[i][j] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = 0;//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois/ remplacement par 0
                    valide = 1;
                    k = taille_logique_chevalet + 1;
                }
                if (lettreAPlacer != chevalet_joueur[k] && k == taille_logique_chevalet) {
                    valide = 0;
                    printf("Le caractere saisi ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
                }
            }
        } while (valide != 1);
        if (islower(lettreAPlacer == 0) && isupper(lettreAPlacer == 0)) {
            printf("Le caractere saisi ne correspond pas a une lettre. Veuillez recommencer:\n");
        }
    } while (islower(lettreAPlacer) == 0 && isupper(lettreAPlacer == 0));
}

void placementHorizontal(unsigned int *pnombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]) {
    int i = 0, j = 0;
    char e = 65, b = 90; //J'ai pas compter le jocker
    printf("\nProchaine lettre\n"
           "Saisissez le numero de la colonne (A=0 B=1...)\n");
    scanf("%d", &i);
    do {
        printf("Saisissez le numero de la case suivante (deuxieme composant de la case)\n");
        scanf("%d", &j); //[j] pour que le mot soit ecrit vers le bas comme [i] ne change pas
        j -= 1;
        if (plateau_de_jeu[i][j] > e && plateau_de_jeu[i][j] < b) {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }

        placementAutreLettre(pnombreLettres, i, j, plateau_de_jeu, chevalet_joueur, MAX_DECK);
    } while (plateau_de_jeu[i][j] > e && plateau_de_jeu[i][j] < b);
}


