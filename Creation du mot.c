/*#include "Creation du mot.h"

//j'ai cree une fonction mais peut-etre qu'il faudrait la mettre directement dans le main?
void SaisirMot(char tableau[],int taille_logique_deck, int *nombreLettres){
    do {
        printf("Combien de lettres souhaitez-vous placer ?\n");
        scanf("%d", nombreLettres);
    }while (*nombreLettres<2 || *nombreLettres>7);
    printf("Saisissez les lettres que vous souhaitez placer :\n");
    fgets(tableau, taille_logique_deck, stdin);
    tableau[strlen(tableau) - 1] = '\0';
}

void creationNouveauMot(const char VerticalHorizontal[],char tableau[],int taille_logique_deck, char *colonne, int *ligne ){
    char sensMot = 0;
    int nbrLettres = 0, valide=0;
    SaisirMot(tableau,taille_logique_deck,&nbrLettres);
        //comparaison lettres qu'on veut placer avec celles du chevalet
    do{
        printf("Dans quel sens souhaitez-vous placer votre mot\n"
               "Saisissez \"v\" pour placer votre mot a la vertical et \"h\" pour l'horizontal.\n");
        scanf(" %c", &sensMot);
    } while (sensMot != 'v' && sensMot != 'h');
    printf("Saisissez la case dans laquelle vous souhaitez commencer votre mot :(Lettre Numero\n");
    scanf("%c %d", colonne, ligne);
    switch(VerticalHorizontal[i]){
        case 'v': {
            //commencer le mot sur la case tab[i][j]
            while (nbrLettres > 2 && nbrLettres < 7) {
                for (int i = 0; i < taille_logique_deck; i++) {
                    printf("Analyse de lettre %d\n", i + 1);
                    if (lettre[j] == tableau[i]) {
                        valide = 1;
                        printf("Lettre %d valide\n", i + 1);
                    } else {
                        valide = 0;
                        printf("Lettre %d valide\n", i + 1);
                    }

                }
                for (int j = 0; j < strlen(lettre); j++) {
                    tableau[i] = 0;
                    --nbrLettres;
                }
            }
        }
            break;
        case 'h':
            //commencer le mot sur la case tab[i][j]
            while (nbrLettres> 2 && nbrLettres<7) {
                for (int i = 0; i < taille_logique_deck; i++) {
                    printf("Analyse de lettre %d\n", i + 1);
                    if (lettre[j] == tableau[i]) {
                        valide = 1;
                        printf("Lettre %d valide\n", i + 1);
                    }
                    else {
                        valide=0;
                        printf("Lettre %d valide\n", i + 1);
                    }

                }
                for (int j = 0; j < strlen(lettre); j++) {
                    tableau[i] = 0;
                    --nbrLettres;
                }
            }
            break;
        default:break;
    }
    //verification de l'existence de(s) nouveau(x) mot(s) cree(s)
}*/