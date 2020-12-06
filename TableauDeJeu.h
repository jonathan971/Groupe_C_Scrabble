#include <stdio.h>
#include "laPioche.h"
#define MAX 15
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#ifndef PROJET_SCRABBLE_TABLEAUDEJEU_H
#define PROJET_SCRABBLE_TABLEAUDEJEU_H

void affichage_tableau_2D(char tab[MAX][MAX],int taille_logique);
void affichagechevalet(char tableau[], int taille_logique_deck, int occurence_point[LIGNES][COLONNES], const char* alphabet);
#endif
