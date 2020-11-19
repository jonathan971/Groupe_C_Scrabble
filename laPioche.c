#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define JETONS 102
#define LIGNES 27
#define COLONNES 2
#define JOKER 219
#define DEBUT_PIOCHE 1
#define FIN_PIOCHE 102
#define NB_ITERATION_BOUCLERANDOM 102

void saisieAlphabet(char alphabet[]){//on crée un tableau avec les lettres de l'alphabet
    int i,a=(int)'A';
    for(i=0;i<LIGNES;i++) {
        alphabet[i]=(char) a;
        a+=1;
    }
    alphabet[LIGNES-1]=(char)JOKER;
}

void saisieOccurrenceValeurs(const char alphabet[],int occurrence_point[][COLONNES]){//on initialise le nb de fois la présence des lettres dans la pioche + leurs valeurs
    int i;
    for(i=0;i<LIGNES;i++){
        switch(alphabet[i]){
            case 'A':{
                occurrence_point[i][0]=9;
                occurrence_point[i][1]=1;
                break;
            }
            case 'B':
            {
                occurrence_point[i][0]=2;
                occurrence_point[i][1]=3;
                break;
            }
            case 'C':
            {
                occurrence_point[i][0]=2;
                occurrence_point[i][1]=3;
                break;
            }
            case 'D':
            {
                occurrence_point[i][0]=3;
                occurrence_point[i][1]=2;
                break;
            }
            case 'E':
            {
                occurrence_point[i][0]=15;
                occurrence_point[i][1]=1;
                break;
            }
            case 'F':
            {
                occurrence_point[i][0]=2;
                occurrence_point[i][1]=4;
                break;
            }
            case 'G':
            {
                occurrence_point[i][0]=2;
                occurrence_point[i][1]=2;
                break;
            }
            case 'H':
            {
                occurrence_point[i][0]=2;
                occurrence_point[i][1]=4;
                break;
            }
            case 'I':
            {
                occurrence_point[i][0]=8;
                occurrence_point[i][1]=1;
                break;
            }
            case 'J':
            {
                occurrence_point[i][0]=1;
                occurrence_point[i][1]=8;
                break;
            }
            case 'K':
            {
                occurrence_point[i][0]=1;
                occurrence_point[i][1]=10;
                break;
            }
            case 'L':
            {
                occurrence_point[i][0]=5;
                occurrence_point[i][1]=1;
                break;
            }
            case 'M':
            {
                occurrence_point[i][0]=3;
                occurrence_point[i][1]=2;
                break;
            }
            case 'N':
            {
                occurrence_point[i][0]=6;
                occurrence_point[i][1]=1;
                break;
            }
            case 'O':
            {
                occurrence_point[i][0]=6;
                occurrence_point[i][1]=1;
                break;
            }
            case 'P':
            {
                occurrence_point[i][0]=2;
                occurrence_point[i][1]=3;
                break;
            }
            case 'Q':
            {
                occurrence_point[i][0]=1;
                occurrence_point[i][1]=8;
                break;
            }
            case 'R':
            {
                occurrence_point[i][0]=6;
                occurrence_point[i][1]=1;
                break;
            }
            case 'S':
            {
                occurrence_point[i][0]=6;
                occurrence_point[i][1]=1;
                break;
            }
            case 'T':
            {
                occurrence_point[i][0]=6;
                occurrence_point[i][1]=1;
                break;
            }
            case 'U':
            {
                occurrence_point[i][0]=6;
                occurrence_point[i][1]=1;
                break;
            }
            case 'V':
            {
                occurrence_point[i][0]=2;
                occurrence_point[i][1]=4;
                break;
            }
            case 'W':
            {
                occurrence_point[i][0]=1;
                occurrence_point[i][1]=10;
                break;
            }
            case 'X':
            {
                occurrence_point[i][0]=1;
                occurrence_point[i][1]=10;
                break;
            }
            case 'Y':
            {
                occurrence_point[i][0]=1;
                occurrence_point[i][1]=10;
                break;
            }
            case 'Z':
            {
                occurrence_point[i][0]=1;
                occurrence_point[i][1]=10;
                break;
            }
            case (char) JOKER: {
                occurrence_point[i][0] = 2;
                occurrence_point[i][1] = 0;
                break;
            }
        }
    }
}

void suivitDeLaPioche(char alphabet[],int occurrence_point[][COLONNES]) {//on initialise avec les 2 procédures précédantes le GRAND tableau
    saisieAlphabet(alphabet);
    saisieOccurrenceValeurs(alphabet, occurrence_point);
}

void melangeDuSac(char lapioche[]){
    int i,lettreadeplace, interverser;
    char securite1, securite2;
    for(i=0;i<NB_ITERATION_BOUCLERANDOM;i++){
        lettreadeplace=rand()%(DEBUT_PIOCHE-FIN_PIOCHE)+DEBUT_PIOCHE;
        interverser=rand()%(DEBUT_PIOCHE-FIN_PIOCHE)+DEBUT_PIOCHE;
        securite1=lapioche[lettreadeplace];
        securite2=lapioche[interverser];
        lapioche[interverser]=securite1;
        lapioche[lettreadeplace]=securite2;
    }
}

void leSacAJetons(char lapioche[],const char alphabet[LIGNES],int occurrence_point[LIGNES][COLONNES]){
    int i,j, nbLettres=0, securite=0;
    for(i=0;i<LIGNES;i++){
        nbLettres += occurrence_point[i][0];
        for(j=securite;j<nbLettres;j++){
            lapioche[j]=alphabet[i];
        }
        securite=nbLettres;
    }
    melangeDuSac(lapioche);
}

void laPioche(char alphabet[], char lapioche[],int occurrence_point[][COLONNES]){
    srand(time(NULL));
    suivitDeLaPioche(alphabet, occurrence_point);
    leSacAJetons(lapioche, alphabet, occurrence_point);
}