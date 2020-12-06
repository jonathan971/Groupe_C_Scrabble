#include "laPioche.h"

//On crée un tableau comportant les lettres de A à Z ainsi que le JOKER qui est un rectangle blanc JOKER = (int) 219
void saisieAlphabet(char alphabet[]){
    int i,a=(int)'A';
    for(i=0;i<LIGNES-1;i++) {
        alphabet[i]=(char) a;
        a+=1;
    }
    alphabet[LIGNES-1]=(char)JOKER;
}

//On saisit à l'aide du tableau de lettre, les différentes valeurs telles que : leurs occurrences et leurs points
void saisieOccurrenceValeurs(const char alphabet[],int occurrence_point[LIGNES][COLONNES]){//on initialise le nb de fois la présence des lettres dans la pioche + leurs valeurs
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
            default :
                break;
        }
    }
}

//On gère grâce à cette fonction notre tableau de lettre et notre tableau de valeurs (occurences et points)
void suivitDeLaPioche(char alphabet[],int occurrence_point[LIGNES][COLONNES]) {
    saisieAlphabet(alphabet);
    saisieOccurrenceValeurs(alphabet, occurrence_point);
}

//On mélance le tableau qui va nous servir de pioche pour le chevalet
void melangeDuSac(char lapioche[]){
    int i,lettreadeplace, interverser;
    char securite1, securite2;
    for(i=0;i<FIN_PIOCHE;i++){
        lettreadeplace=rand()%(FIN_PIOCHE-DEBUT_PIOCHE+1)+DEBUT_PIOCHE;
        interverser=rand()%(FIN_PIOCHE-DEBUT_PIOCHE+1)+DEBUT_PIOCHE;
        securite1=lapioche[lettreadeplace];
        securite2=lapioche[interverser];
        lapioche[interverser]=securite1;
        lapioche[lettreadeplace]=securite2;
    }
}

//On initialise notre tableau qui servira de pioche
void leSacAJetons(char* lapioche,const char* alphabet,int occurrence_point[LIGNES][COLONNES]) {
    int i,j, nbLettres = 0, securite = 0;
    for (i = 0; i < LIGNES; i++) {
        nbLettres += occurrence_point[i][0];
        for (j = securite; j < nbLettres; j++) {
            lapioche[j]=alphabet[i];
        }
        securite = nbLettres;
    }
    melangeDuSac(lapioche);
}

//Cette fonction a pour but de créer la pioche
void leSac(char *alphabet, char *lapioche, int occurrence_point[LIGNES][COLONNES]) {
    suivitDeLaPioche(alphabet, occurrence_point);
    leSacAJetons(lapioche, alphabet, occurrence_point);
}

//On réalise le tirage des lettres une par une, on interverse la lettre sélectionnée avec la dernière et
//on baisse la taille logique à laquelle on peut piocher pour ne pas obtenir des lettres déjà tirées
char pickJetons(char* lapioche, int* modiftaillephysique){
    int alea;
    char lettre, securite;
    alea=rand()%(JETONS-*modiftaillephysique);
    lettre=lapioche[alea];
    securite=lapioche[JETONS-1-*modiftaillephysique];
    lapioche[JETONS-1-*modiftaillephysique]=lettre;
    lapioche[alea]=securite;
    (*modiftaillephysique)++;
    return lettre;
}