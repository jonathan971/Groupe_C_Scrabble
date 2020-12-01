#include <stdio.h>
#include "laPioche.h"
#define MAX 15

#ifndef PROJET_SCRABBLE_TABLEAUDEJEU_H
#define PROJET_SCRABBLE_TABLEAUDEJEU_H

void affichage_tableau_2D(char tab[MAX][MAX],int taille_logique);
void affichagechevalet(char tableau[], int taille_logique_deck, int occurence_point[LIGNES][COLONNES], const char* alphabet);
#endif
