#include "Verification_chevalet.h"

//On réalise la sélection des lettres à placer en général
int placementAutreLettre( int i, int j, char plateau_de_jeu[MAX][MAX],
                           char chevalet_joueur[MAX_DECK], int taille_logique_chevalet, char* alphabet,int occurrence_point[][COLONNES]) {
    int k, valide = 0,score;
    char lettreAPlacer = 0;
    do {
        do { //verification que le caractere est bien une lettre
            printf("Saisissez la lettre que vous souhaitez placer:\n");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < taille_logique_chevalet; k++) {
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    score=bonusPlateau(i,j, plateau_de_jeu, lettreAPlacer, alphabet, occurrence_point);
                    plateau_de_jeu[i][j] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = '0';//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois/ remplacement par 0
                    valide = 1;
                    k = taille_logique_chevalet;
                }
                if ((chevalet_joueur[k] == (char) JOKER && plateau_de_jeu[i][j] == (char)32) && lettreAPlacer != chevalet_joueur[k] ){
                    printf("La saisie ne correspond pas aux lettres sur votre chevalet.\n"
                           "Utilisation du joker.\n");
                    printf("Saisissez la lettre que vous souhaitez placer:\n");
                    scanf(" %c", &lettreAPlacer);
                    plateau_de_jeu[i][j] = lettreAPlacer;
                    score=0;
                    chevalet_joueur[k] = '0';
                    valide=1;
                }
                if ( lettreAPlacer != chevalet_joueur[k] && valide==0) {
                    valide = 0;
                    if (k == taille_logique_chevalet-1 ) {
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

// On regarde combien de lettre le joueur veut placer durant son tour
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

//On demande au joueur le sens dans lequel il veut placer son mot sur le plateau de jeu
char sensDuMot() {
    char sensMot = '0';
    do {
        printf("Saisissez \"v\" pour placer votre mot a la verticale et \"h\" pour l'horizontale.\n");
        scanf(" %c", &sensMot);
    } while (sensMot != 'v' && sensMot != 'h');
    return sensMot;
}

//on demande quelle sera la première lettre à être posée sur le plateau de jeu (sur le #)
int placementPremiereLettrePremierMot(char plateau_de_jeu[MAX][MAX],
                                       char chevalet_joueur[MAX_DECK], int taille_logique_chevalet,
                                       char* alphabet, int occurrence_point[][COLONNES],int*i,int*j) {
    char lettreAPlacer = 0;
    int k, valide = 0,score;
    do {  //verification que le caractere est bien une lettre
        printf("Vous commencez la partie.\n");
        do {
            printf("Saisissez la lettre que vous souhaitez poser sur la case du milieu (P.S :(Ligne = 8; Colonne = 7)):\n");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < taille_logique_chevalet; k++) {
                *i=7;
                *j=7;
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    score=bonusPlateau(7,7, plateau_de_jeu, lettreAPlacer, alphabet, occurrence_point);
                    plateau_de_jeu[7][7] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = 0;//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois
                    valide = 1;
                    k = taille_logique_chevalet;
                }
                // on vérifie que si la lettre demandée n'est pas dans le chevalet, alors il peut y avoir un JOKER
                if (chevalet_joueur[k] == (char) JOKER && plateau_de_jeu[*i][*j] == (char)35 ){
                    printf("La saisie ne correspond pas aux lettres sur votre chevalet.\n"
                           "Utilisation du joker.\n");
                    printf("Saisissez la lettre que vous souhaitez placer:\n");
                    scanf(" %c", &lettreAPlacer);
                    plateau_de_jeu[*i][*j] = lettreAPlacer;
                    score=0;
                    chevalet_joueur[k] = '0';
                    valide=1;
                }
                if (lettreAPlacer != chevalet_joueur[k] && valide==0) {
                    valide = 0;
                    if (k == taille_logique_chevalet-1) {
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
//Ce code consiste à placer la première lettre du mot que chaque joueur placera durant la partie (à l'exception du premier joueur au tour 1 qui place directement sa première lettre sur le #)
int placementPremiereLettre(char plateau_de_jeu[MAX][MAX],int taille_logique_chevalet,
                            char chevalet_joueur[MAX_DECK], char*alphabet, int occurrence_point[][COLONNES],int*o,int*p) {
    char lettreAPlacer = 0;
    int k, valide = 0,i=0,j=0,score;
    char e = 65, b = 90; //J'ai pas compter le jocker
    do {  //verification que le caractere est bien une lettre
        do {
            do {
                printf("Saisissez le numero de ligne\n");
                scanf(" %d", &i);
                i--;
                *o=i;
                printf("Saisissez le numero de colonne (A=0 B=1...)\n");
                scanf("%d",&j);
                *p=j;
                if(plateau_de_jeu[i][j] < e && plateau_de_jeu[i][j] > b){
                    printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
                }
            }while(plateau_de_jeu[i][j] < e && plateau_de_jeu[i][j] > b);
            printf("Saisissez la lettre que vous souhaitez poser :\n");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < taille_logique_chevalet; k++) {
                if (lettreAPlacer == chevalet_joueur[k]) {//verification que la lettre est presente sur le chevalet
                    printf("Le caractere saisi a été trouvé !!\n");
                    score=bonusPlateau(i,j, plateau_de_jeu, lettreAPlacer, alphabet, occurrence_point);
                    plateau_de_jeu[i][j] = lettreAPlacer;//remplacement de la case du tableau par la lettre saisie
                    chevalet_joueur[k] = 0;//suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois
                    valide = 1;
                    k = taille_logique_chevalet;
                }
                if (lettreAPlacer != chevalet_joueur[k] && valide==0) {
                    valide = 0;
                    if (k == taille_logique_chevalet-1) {
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

//On réalise le code pour placer un mot en vertical et ainsi éviter des redondances de lecture d'informations provenant du joueur
int placementVertical( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],char* alphabet,int occurrence_point[][COLONNES], int j) {
    int i = 0,score;
    char e = 65, b = 90; //J'ai pas compter le jocker
    printf("\nProchaine lettre\n");
    do {
        printf("Saisissez le numero de la ligne\n");
        scanf(" %d", &i); //[i] pour que le mot soit ecrit vers le bas comme [j] ne change pas
        i -= 1;
        if (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b) {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }
        score=placementAutreLettre(i, j, plateau_de_jeu, chevalet_joueur, MAX_DECK, alphabet, occurrence_point);
    } while (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b);
    return score;
}

//On réalise le code pour placer un mot en horizontal et ainsi éviter des redondances de lecture d'informations provenant du joueur
int placementHorizontal( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],char* alphabet,int occurrence_point[][COLONNES], int i) {
    int j = 0,score;
    char e = 65, b = 90; //J'ai pas compter le jocker
    printf("\nProchaine lettre\n");
    do {
        printf("Saisissez le numero de colonne (A=0 B=1...)\n");
        scanf(" %d", &j);
        if (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b) {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }
        score=placementAutreLettre(i, j, plateau_de_jeu, chevalet_joueur, MAX_DECK,alphabet,occurrence_point);
    } while (plateau_de_jeu[i][j] <= e && plateau_de_jeu[i][j] >= b);
    return score;
}

//On effectue la pose du premier mot sur le plateau du jeu de Scrabble et de la partie
int placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],
                         unsigned int *pnombreLettres, char* alphabet, int occurrence_point[][COLONNES]) { //pour le tout premier mot du jeu
    char sensMot = 0;
    nombreDeLettres(pnombreLettres);
    sensMot = sensDuMot();
    int score=0,i,j;
    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            score+=placementPremiereLettrePremierMot( plateau_de_jeu, chevalet_joueur, MAX_DECK,alphabet,occurrence_point,&i,&j);
            *pnombreLettres-=1;
            do {
                score+=placementVertical(plateau_de_jeu, chevalet_joueur,alphabet,occurrence_point,j);
                *pnombreLettres-=1;
                if(*pnombreLettres==0){
                    printf("Le tour est terminé !\n");
                }
            } while (*pnombreLettres != 0);

            break;
        case 'h':
            score+=placementPremiereLettrePremierMot( plateau_de_jeu, chevalet_joueur, MAX_DECK,alphabet,occurrence_point,&i,&j);
            *pnombreLettres-=1;
            do {
                score+=placementHorizontal( plateau_de_jeu, chevalet_joueur,alphabet,occurrence_point,i);
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

//on effectue la pose du mot en général (sauf le premier mot du premier joueur au premier tour)
int placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],unsigned int *pnombreLettres, char*alphabet, int occurrence_point[][COLONNES]) { //pous tous les autres mots du jeu
    char sensMot = '0';
    int score=0, i,j;
    nombreDeLettres(pnombreLettres);
    sensMot = sensDuMot();

    switch (sensMot) {  //placement du mot sur le plateau de jeu
        case 'v':
            score+=placementPremiereLettre(plateau_de_jeu,MAX_DECK,chevalet_joueur, alphabet, occurrence_point, &i, &j);
            *pnombreLettres-=1;
            do {
                score+=placementVertical(plateau_de_jeu, chevalet_joueur,alphabet,occurrence_point,j);
                *pnombreLettres-=1;
                if(*pnombreLettres==0){
                    printf("Le tour est terminé !\n");
                }
            } while (*pnombreLettres != 0);
            break;
        case 'h':
            score+=placementPremiereLettre(plateau_de_jeu,MAX_DECK,chevalet_joueur, alphabet, occurrence_point,&i,&j);
            *pnombreLettres-=1;
            do {
                score+=placementHorizontal( plateau_de_jeu, chevalet_joueur,alphabet,occurrence_point,i);
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


