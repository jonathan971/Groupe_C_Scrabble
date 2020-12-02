#ifndef CREATIONMOT_VERIFICATION_CHEVALET_H
#define CREATIONMOT_VERIFICATION_CHEVALET_H
#include <stdio.h>
#include <ctype.h>
#define MAX_DECK 8
#define MAX 15

int nombreDeLettres();
char sensDuMot();
void placementPremiereLettrePremierMot(int nombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementPremiereLettre(char plateau_de_jeu[MAX][MAX]);
void placementVertical(int nombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementHorizontal(int nombreLettres, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementAutreLettre(int nombreLettres, int i, int j, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);

#endif