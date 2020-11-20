#include <stdio.h>
#include <string.h>

#ifndef GROUPE_C_SCRABBLE_CREATION_DU_MOT_H
#define GROUPE_C_SCRABBLE_CREATION_DU_MOT_H

void creationNouveauMot(const char VerticalHorizontal[],char tableau[],int taille_logique_deck,char *colonne, int *ligne);
void SaisirMot(char tableau[],int taille_logique_deck, int *nombreLettres);

#endif