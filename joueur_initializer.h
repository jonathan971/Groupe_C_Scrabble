#include <stdio.h>
#include "TableauDeJeu.h"
#define MAX 15
#define MAX_PSEUDO 11
#define MAX_DECK 8
typedef struct {
    char nom[MAX_PSEUDO],chevalet_joueur[MAX_DECK];
    int score, temps;
}Joueur;

#ifndef GROUPE_C_SCRABBLE_JOUEUR_INITIALIZER_H
#define GROUPE_C_SCRABBLE_JOUEUR_INITIALIZER_H

void intialisation_joueur(Joueur player[],unsigned int *nb_joueur,char tableau[]);

#endif //GROUPE_C_SCRABBLE_JOUEUR_INITIALIZER_H
