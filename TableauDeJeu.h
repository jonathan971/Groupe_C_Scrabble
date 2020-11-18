#include <stdio.h>
#define MAX 15

typedef struct{ //deck du joueur sur le chevalet
    char lettre;
    int nb_occurence, valeur;
}pioche;

#ifndef PROJET_SCRABBLE_TABLEAUDEJEU_H
#define PROJET_SCRABBLE_TABLEAUDEJEU_H

void chevalet(char tableau[],pioche *Pioche, int taille_logique_deck);
void affichage_tableau_2D(char tab[MAX][MAX],int taille_logique);

#endif //PROJET_SCRABBLE_TABLEAUDEJEU_H
