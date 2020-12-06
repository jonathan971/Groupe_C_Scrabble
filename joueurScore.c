#include "joueurScore.h"
//Cette fonction permet de connaître la valeur en point de la lettre qui a été placée
int valeurLettre(char caractere,const char* alphabet,int occurence_point[][COLONNES]){
    int point=0,i;
    for(i=0;i<LIGNES;i++){
        if(caractere==alphabet[i]){
            point=occurence_point[i][1];
        }
    }
    return point;
}

//On utilise ici la valeur des lettres posées et on leur ajoute ou non des bonus en fonction de la case sur laquelle elles se trouvent
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
        case '#'://départ
        case (char) 32:// les espaces vides
        default:{
            scorelettre=valeurLettre(caractere, alphabet, occurence_point);
            break;
        }
    }
    return scorelettre;
}