#include "joueurScore.h"

int valeurLettre(char caractere,const char* alphabet,int occurence_point[][COLONNES]){
    int point=0,i;
    for(i=0;i<LIGNES;i++){
        if(caractere==alphabet[i]){
            point=occurence_point[i][1];
        }
    }
    return point;
}


int bonusPlateau(int i, int j,char plateau_de_jeu[MAX][MAX], char caractere, char* alphabet ,int occurence_point[][COLONNES]){
    int scorelettre;
    switch(plateau_de_jeu[i][j]){
        case '&':{//lettre compte double
            scorelettre=2*valeurLettre(caractere, alphabet, occurence_point);
            break;
        }
        case '%':{//lettre compte triple
            scorelettre=3*valeurLettre(caractere, alphabet, occurence_point);
            break;
        }
        /*case '@':{//mot compte triple
            scoreMot;
            break;
        }
        case '$':{//mot compte triple
            scoreMot;
            break;
        }*/
        case '#':
        case (char) 32://départ
        default:{
            scorelettre=valeurLettre(caractere, alphabet, occurence_point);
            break;
        }
    }
    return scorelettre;
}