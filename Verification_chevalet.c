#include "Verification_chevalet.h"

int placementAutreLettre( int i, int j, char plateau_de_jeu[MAX][MAX],
                           char chevalet_joueur[MAX_DECK], int taille_logique_chevalet, char* alphabet,int occurrence_point[][COLONNES]) {
    int k, f = 0, valide = 0,score;
    char lettreAPlacer = 0;
    do {
        do { //verification que le caractere est bien une lettre
            printf("Saisissez la lettre que vous souhaitez placer:\n");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < taille_logique_chevalet; k++) {
                /*while (f <= 100) {
                    printf("Recherche du mot : %d %c \n", f, 37);
                    f += 20;
                }*/
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    score=bonusPlateau(7,7, plateau_de_jeu, lettreAPlacer, alphabet, occurrence_point);
                    plateau_de_jeu[i][j] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = '0';//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois/ remplacement par 0
                    valide = 1;
                    k = taille_logique_chevalet;
                }
                if ( lettreAPlacer != chevalet_joueur[k] && valide==0) {
                    valide = 0;
                    if (k == taille_logique_chevalet-1 ) {
                        f=0;
                        printf("Le caractere saisi ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
                    }
                }
            }
        } while (valide == 0);
        if (islower(lettreAPlacer == 0) && isupper(lettreAPlacer == 0)) {
            printf("Le caractere saisi ne correspond pas a une lettre. Veuillez recommencer:\n");
        }
    } while (islower(lettreAPlacer) == 0 && isupper(lettreAPlacer == 0));
    return score;
}

void nombreDeLettres(unsigned int *pnombreLettres) {
    do {
        printf("Combien de lettres souhaitez-vous placer?\n");
        scanf("%d", pnombreLettres);
        if(*pnombreLettres < 2){
            printf("Vous ne pouvez pas placer une lettre. Réésayez !\n");
        }
        if(*pnombreLettres > 7){
            printf("Votre chevalet est composé de sept jetons. Comment voulez-vous placer plus de sept jetons !! Réésayez !\n");
        }
    } while (*pnombreLettres < 2 || *pnombreLettres > 7);
}

char sensDuMot() {
    char sensMot = '0';
    do {
        printf("Saisissez \"v\" pour placer votre mot a la verticale et \"h\" pour l'horizontale.\n");
        scanf(" %c", &sensMot);
    } while (sensMot != 'v' && sensMot != 'h');
    return sensMot;
}

int placementPremiereLettrePremierMot(char plateau_de_jeu[MAX][MAX],
                                       char chevalet_joueur[MAX_DECK], int taille_logique_chevalet,
                                       char* alphabet, int occurrence_point[][COLONNES]) {
    char lettreAPlacer = 0;
    int k = 0, f = 0, valide = 0,score;
    do {  //verification que le caractere est bien une lettre
        printf("Vous commencez la partie.\n");
        do {
            printf("Saisissez la lettre que vous souhaitez poser sur la case du milieu (P.S :(Ligne = 8; Colonne = 7)):\n");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < taille_logique_chevalet; k++) {
                /*while (f <= 100) {
                    printf("Recherche du mot : %d %c \n", f, 37);
                    f += 20;
                }*/
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    score=bonusPlateau(7,7, plateau_de_jeu, lettreAPlacer, alphabet, occurrence_point);
                    plateau_de_jeu[7][7] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = 0;//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois
                    valide = 1;
                    k = taille_logique_chevalet;
                }
                if (lettreAPlacer != chevalet_joueur[k] && valide==0) {
                    valide = 0;
                    if (k == taille_logique_chevalet-1) {
                        f=0;
                        printf("Le caractere saisi ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
                    }
                }
            }
        } while (valide != 1);

        if (islower(lettreAPlacer == 0) && isupper(lettreAPlacer == 0)) {
            printf("Le caractere saisi ne correspond pas a une lettre. Veuillez recommencer:\n");
        }
    } while (islower(lettreAPlacer) == 0 && isupper(lettreAPlacer == 0));
    return score;
}

int placementPremiereLettre(char plateau_de_jeu[MAX][MAX],int taille_logique_chevalet,
                            char chevalet_joueur[MAX_DECK], char*alphabet, int occurrence_point[][COLONNES]) {
    char lettreAPlacer = 0;
    int k = 0, f = 0, valide = 0,i=0,j=0,score;
    char e = 65, b = 90; //J'ai pas compter le jocker
    do {  //verification que le caractere est bien une lettre
        do {
            do {
                printf("Saisissez la case dans laquelle vous souhaitez commencer votre mot: (ORDRE : colonne/ligne)\n");
                scanf("%d %d", &i, &j);
                if(plateau_de_jeu[i][j] < e && plateau_de_jeu[i][j] > b){
                    printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
                }
            }while(plateau_de_jeu[i][j] < e && plateau_de_jeu[i][j] > b);
            printf("Saisissez la lettre que vous souhaitez poser sur la case du milieu (P.S :(Ligne = 8; Colonne = 7)):\n");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < taille_logique_chevalet; k++) {
                /*while (f <= 100) {
                    printf("Recherche de la lettre : %d %c \n", f, 37);
                    f += 20;
                }*/
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    score=bonusPlateau(7,7, plateau_de_jeu, lettreAPlacer, alphabet, occurrence_point);
                    plateau_de_jeu[7][7] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = 0;//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois
                    valide = 1;
                    k = taille_logique_chevalet;
                }
                if (lettreAPlacer != chevalet_joueur[k] && valide==0) {
                    valide = 0;
                    if (k == taille_logique_chevalet-1) {
                        f=0;
                        printf("Le caractere saisi ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
                    }
                }
            }
        } while (valide != 1);

        if (islower(lettreAPlacer == 0) && isupper(lettreAPlacer == 0)) {
            printf("Le caractere saisi ne correspond pas a une lettre. Veuillez recommencer:\n");
        }
    } while (islower(lettreAPlacer) == 0 && isupper(lettreAPlacer == 0));
    return score;
}

int placementVertical( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],char* alphabet,int occurrence_point[][COLONNES]) {
    int i = 0, j = 0,score;
    char e = 65, b = 90; //J'ai pas compter le jocker
    printf("\nProchaine lettre\n"
           "Saisissez le numero de la colonne (A=0 B=1...)\n");
    scanf("%d", &j);
    do {
        printf("Saisissez le numero de la ligne\n");
        scanf("%d", &i); //[i] pour que le mot soit ecrit vers le bas comme [j] ne change pas
        i -= 1;
        if (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b) {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }
        score=placementAutreLettre(i, j, plateau_de_jeu, chevalet_joueur, MAX_DECK, alphabet, occurrence_point);
    } while (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b);
    return score;
}


int placementHorizontal( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],char* alphabet,int occurrence_point[][COLONNES]) {
    int i = 0, j = 0,score;
    char e = 65, b = 90; //J'ai pas compter le jocker
    printf("\nProchaine lettre\n"
           "Saisissez le numero de la colonne (A=0 B=1...)\n");
    scanf("%d", &i);
    do {
        printf("Saisissez le numero de la case suivante (l'abscisse)\n");
        scanf("%d", &j); //[j] pour que le mot soit ecrit vers le bas comme [i] ne change pas
        j -= 1;
        if (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b) {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }
        score=placementAutreLettre(i, j, plateau_de_jeu, chevalet_joueur, MAX_DECK,alphabet,occurrence_point);
    } while (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b);
    return score;
}

int placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],
                         unsigned int *pnombreLettres, char* alphabet, int occurrence_point[][COLONNES]) { //pour le tout premier mot du jeu
    char sensMot = 0;
    nombreDeLettres(pnombreLettres);
    sensMot = sensDuMot();
    int score=0;
    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            score+=placementPremiereLettrePremierMot(plateau_de_jeu,chevalet_joueur,MAX_DECK, alphabet, occurrence_point);
            *pnombreLettres-=1;
            do {
                score+=placementVertical( plateau_de_jeu, chevalet_joueur,alphabet, occurrence_point);
                *pnombreLettres-=1;
                if(*pnombreLettres==0){
                    printf("Le tour est terminé !\n");
                }
            } while (*pnombreLettres != 0);

            break;
        case 'h':
            score+=placementPremiereLettrePremierMot( plateau_de_jeu, chevalet_joueur, MAX_DECK,alphabet,occurrence_point);
            *pnombreLettres-=1;
            do {
                score+=placementHorizontal( plateau_de_jeu, chevalet_joueur,alphabet,occurrence_point);
                *pnombreLettres-=1;
                if(*pnombreLettres==0){
                    printf("Le tour est terminé !\n");
                }
            } while (*pnombreLettres != 0);

            break;
        default:
            break;
    }
    return score;
}

int placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],unsigned int *pnombreLettres, char*alphabet, int occurrence_point[][COLONNES]) { //pous tous les autres mots du jeu
    char sensMot = '0';
    int score=0;
    nombreDeLettres(pnombreLettres);
    sensMot = sensDuMot();

    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            score+=placementPremiereLettre(plateau_de_jeu,MAX_DECK,chevalet_joueur, alphabet, occurrence_point);
            *pnombreLettres-=1;
            do {
                score+=placementVertical(plateau_de_jeu, chevalet_joueur,alphabet,occurrence_point);
                *pnombreLettres-=1;
                if(*pnombreLettres==0){
                    printf("Le tour est terminé !\n");
                }
            } while (*pnombreLettres != 0);
            break;
        case 'h':
            score+=placementPremiereLettre(plateau_de_jeu,MAX_DECK,chevalet_joueur, alphabet, occurrence_point);
            *pnombreLettres-=1;
            do {
                score+=placementHorizontal( plateau_de_jeu, chevalet_joueur,alphabet,occurrence_point);
                *pnombreLettres-=1;
                if(*pnombreLettres==0){
                    printf("Le tour est terminé !\n");
                }
            } while (*pnombreLettres != 0);
            break;
        default:
            break;
    }
    return score;
}
