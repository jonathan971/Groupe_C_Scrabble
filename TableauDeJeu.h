#include <stdio.h>
#include "laPioche.h"
#include "pickJetons.h"
#define MAX 15

#ifndef PROJET_SCRABBLE_TABLEAUDEJEU_H
#define PROJET_SCRABBLE_TABLEAUDEJEU_H

void creationchevalet(char tableau[], int taille_logique_deck,char lapioche[], int * modiftaillephysique);
void affichage_tableau_2D(char tab[MAX][MAX],int taille_logique);
void affichagechevalet(char tableau[], int taille_logique_deck,int occurrence_point[LIGNES][COLONNES]);
#endif //PROJET_SCRABBLE_TABLEAUDEJEU_H
