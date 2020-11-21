#define JOKER 219
#define JETONS 102
#define LIGNES 27
#define COLONNES 2
#define DEBUT_PIOCHE 1
#define FIN_PIOCHE 102

#include <stdlib.h>
#include <time.h>
#define NB_ITERATION_BOUCLERANDOM 102

#ifndef GROUPE_C_SCRABBLE_LAPIOCHE_H
#define GROUPE_C_SCRABBLE_LAPIOCHE_H

void laPioche(char alphabet[], char lapioche[], int occurrence_point[][COLONNES]);

#endif
