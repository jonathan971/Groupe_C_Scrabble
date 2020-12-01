#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define JETONS 102
#define LIGNES 27
#define COLONNES 2
#define JOKER 219
#define DEBUT_PIOCHE 1
#define FIN_PIOCHE 102
#define MAX_DECK 8


#ifndef GROUPE_C_SCRABBLE_LAPIOCHE_H
#define GROUPE_C_SCRABBLE_LAPIOCHE_H

void saisieAlphabet(char alphabet[]);

void saisieOccurrenceValeurs(const char alphabet[],int occurrence_point[][COLONNES]);

void suivitDeLaPioche(char alphabet[],int occurrence_point[][COLONNES]);

void melangeDuSac(char lapioche[]);

void leSacAJetons(char lapioche[],const char alphabet[LIGNES],int occurrence_point[LIGNES][COLONNES]);

void laPioche(char* alphabet, char* lapioche,int occurrence_point[LIGNES][COLONNES]);

char pickJetons(char lapioche[JETONS+1], int* modiftaillephysique);

#endif
