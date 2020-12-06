#include "TableauDeJeu.h"
#include "laPioche.h"

#ifndef GROUPE_C_SCRABBLE_JOUEURSCORE_H
#define GROUPE_C_SCRABBLE_JOUEURSCORE_H

int valeurLettre(char caractere,const char* alphabet,int occurence_point[][COLONNES]);
int bonusPlateau(int i, int j, char plateau_de_jeu[MAX][MAX], char caractere, char* alphabet ,int occurence_point[][COLONNES]);

#endif
