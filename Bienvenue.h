#include <stdio.h>
#include <stdlib.h>
#include "TableauDeJeu.h"
#include "Regle.h"
#include "joueur_initializer.h"

#ifndef GROUPE_C_SCRABBLE_BIENVENUE_H
#define GROUPE_C_SCRABBLE_BIENVENUE_H
void bienvenue_jeu(unsigned int *choix);
void afficherMenuPendantPartie(unsigned int *choix,int *pi, Joueur Player[], int *modiftaillephysique, char lapioche[],int taille_logique_chevalet,char chevalet_joueur[MAX_DECK],int occurence_point[LIGNES][COLONNES], const char* alphabet);
int nb_player;
#endif //GROUPE_C_SCRABBLE_BIENVENUE_H
