#include "Creation du mot.h"
#include <stdio.h>
#include <string.h>
#define NOMBRE_DE_LETTRES 7

//j'ai cree une fonction mais peut-etre qu'il faudrait la mettre directement dans le main?

int creationNouveauMot(){
    char sensMot = 0, lettresAUtiliser[NOMBRE_DE_LETTRES] = {'\0'};
    int nombreLettres = 0, i = 0, j = 0;
    printf("Combien de lettres souhaitez-vous placer?");
    scanf("%d", &nombreLettres);
    printf("Saisissez les lettres que vous souhaitez placer:");
    fgets(lettresAUtiliser, NOMBRE_DE_LETTRES, stdin);
    lettresAUtiliser[strlen(lettresAUtiliser)-1]='\0';
    //comparaison lettres qu'on veut placer avec celles du chevalet
    do{
        printf("Saisissez \"v\" pour placer votre mot a la verticale et \"h\" pour l'horizontale.");
        scanf(" %c", &sensMot);
    } while (sensMot != 'v' || sensMot != 'h');
    printf("Saisissez la case dans laquelle vous souhaitez commencer votre mot:");
    scanf("%d %d", &i, &j);
    switch(sensMot){
        case 'v':
            //commencer le mot sur la case tab[i][j]
            while (nombreLettres > 0){
                printf("Saisissez le numero de la case suivante (deuxieme composant de la case)");
                //equivalent de [j] pour que le mot soit ecrit vers le bas comme [i] ne change pas
                --nombreLettres;
            }
        case 'h':
            //commencer le mot sur la case tab[i][j]
            while (nombreLettres > 0){
                printf("Saisissez le numero de la case suivante (premier composant de la case)");
                //equivalent de [i] pour que le mot soit ecrit vers la droite comme [j] ne change pas
                --nombreLettres;
            }
            break;
    }
    //verification de l'existence de(s) nouveau(x) mot(s) cree(s)
}