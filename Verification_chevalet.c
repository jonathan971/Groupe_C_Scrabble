#include "Verification_chevalet.h"
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

int nombreDeLettres(){
    int nombreLettres = 0;
    printf("Combien de lettres souhaitez-vous placer?");
    scanf("%d", &nombreLettres);
    return nombreLettres;
}

char sensDuMot(){
    char sensMot = '0';
    do {
        printf("Saisissez \"v\" pour placer votre mot a la verticale et \"h\" pour l'horizontale.");
        scanf(" %c", &sensMot);
    } while (sensMot != 'v' && sensMot != 'h');
    return sensMot;
}

void placementPremiereLettrePremierMot(int nombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]){
    char lettreAPlacer = '0';
    int k = 0;
    do { //verification que la lettre est presente sur le chevalet
        do{ //verification que le caractere est bien une lettre
            printf("Vous commencez la partie. Saisissez la lettre que vous souhaitez poser sur la case du milieu:");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < nombreLettres; k++) {
                if (lettreAPlacer == chevalet_joueur[k]) {
                    plateau_de_jeu[8][8] = lettreAPlacer;
                    chevalet_joueur[k] = '0'; //suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois
                }
            }
            if (islower(lettreAPlacer == 0) && isupper(lettreAPlacer == 0)){
                printf("Le caractere saisi ne correspond pas a une lettre. Veuillez recommencer:\n");
            }
        } while (islower(lettreAPlacer) == 0 && isupper(lettreAPlacer == 0));
        if (plateau_de_jeu[8][8] == ' ') {
            printf("Le caractere saisi ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
        }
    } while (plateau_de_jeu[8][8] == ' ');
}

void placementPremiereLettre(char plateau_de_jeu[MAX][MAX]){
    int i = 0, j = 0;
    do {
        printf("Saisissez la case dans laquelle vous souhaitez commencer votre mot:");
        scanf("%d %d", &i, &j);
        if (plateau_de_jeu[i][j] != ' ') {
            printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
        }
    }while (plateau_de_jeu[i][j] != ' ');
}

void placementVertical(int nombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]){
    int i = 0, j = 0;
    while (nombreLettres > 0) {
        do {
            printf("Saisissez le numero de la case suivante (deuxieme composant de la case)");
            scanf("%d", &j); //[j] pour que le mot soit ecrit vers le bas comme [i] ne change pas
            if (plateau_de_jeu[i][j] != ' ') {
                printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
            }
        }while (plateau_de_jeu[i][j] != ' ');
        placementAutreLettre(nombreLettres, i, j, plateau_de_jeu, chevalet_joueur);
        nombreLettres--;
    }
}
void placementAutreLettre(int nombreLettres, int i, int j, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]){
    int k= 0;
    char lettreAPlacer = '0';
    do { //verification que la lettre est presente sur le chevalet
        do{ //verification que le caractere est bien une lettre
            printf("Saisissez la lettre que vous souhaitez placer:");
            scanf(" %c", &lettreAPlacer);
            for (k = 0; k < nombreLettres; k++) {
                if (lettreAPlacer == chevalet_joueur[k]) {
                    plateau_de_jeu[i][j] = lettreAPlacer;
                    chevalet_joueur[k] = '0'; //suppression de la lettre utilisee pour ne pas pouvoir la remettre une autre fois
                }
            }
            if (islower(lettreAPlacer == 0) && isupper(lettreAPlacer == 0)){
                printf("Le caractere saisi ne correspond pas a une lettre. Veuillez recommencer:\n");
            }
        }while (islower(lettreAPlacer) == 0 && isupper(lettreAPlacer == 0));
        if (plateau_de_jeu[i][j] == ' ') {
            printf("La saisie ne correspond pas aux lettres sur votre chevalet. Veuillez recommencer:\n");
        }
    }while (plateau_de_jeu[i][j] == ' ');
}

void placementHorizontal(int nombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]){
    int i = 0, j = 0;
    while (nombreLettres > 0) {
        do {
            printf("Saisissez le numero de la case suivante (premier composant de la case)");
            scanf("%d", &i); //[i] pour que le mot soit ecrit vers le bas comme [j] ne change pas
            if (plateau_de_jeu[i][j] != ' ') {
                printf("La case que vous avez saisie est deja prise. Veuillez recommencer.\n");
            }
        }while (plateau_de_jeu[i][j] != ' ');
        placementAutreLettre(nombreLettres, i, j, plateau_de_jeu, chevalet_joueur);
        nombreLettres--;
    }
}


