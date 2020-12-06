#include <stdio.h>
#include <string.h>
#include "TableauDeJeu.h"

#define MAX 15
#define MAX_PSEUDO 11
#define MAX_DECK 8
#define MAX_CHOIX 4

typedef struct {
    char nom[MAX_PSEUDO],chevalet_joueur[MAX_DECK];
    int score;
}Joueur;

#ifndef GROUPE_C_SCRABBLE_JOUEUR_INITIALIZER_H
#define GROUPE_C_SCRABBLE_JOUEUR_INITIALIZER_H

void intialisation_joueur(Joueur Player[], int*modiftaillephysique,char lapioche[],int *nb_joueur);
void recharge_chevalet(Joueur Player[], int*modiftaillephysique,char lapioche[],const int *pi);
void echange_chevalet_pioche(Joueur Player[], int *modiftaillephysique, char lapioche[], int taille_logique_chevalet,
                             const char chevalet_joueur[MAX_DECK], const char *alphabet, int *i,char pchoixx[MAX_CHOIX],
                             char pchoix1[MAX_CHOIX] , char pchoix2[MAX_CHOIX]);

#endif
