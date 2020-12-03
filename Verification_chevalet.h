#ifndef CREATIONMOT_VERIFICATION_CHEVALET_H
#define CREATIONMOT_VERIFICATION_CHEVALET_H
#include <stdio.h>
#include <ctype.h>
#define MAX_DECK 8
#define MAX 15

int nombreDeLettres();
char sensDuMot();
void placementPremiereLettrePremierMot(int *pnombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementPremiereLettre(char plateau_de_jeu[MAX][MAX]);
void placementVertical(int *pnombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementHorizontal(int *pnombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementAutreLettre(int *pnombreLettres, int i, int j, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);


#endif