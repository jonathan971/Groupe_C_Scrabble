#ifndef CREATIONMOT_VERIFICATION_CHEVALET_H
#define CREATIONMOT_VERIFICATION_CHEVALET_H
#include <stdio.h>
#include <ctype.h>
#include "joueurScore.h"
#define MAX_DECK 8
#define MAX 15

void nombreDeLettres(unsigned int *pnombreLettres);
char sensDuMot();
int placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],unsigned int *pnombreLettres, char alphabet[], int occurrence_point[][COLONNES]);
int placementPremiereLettre(char plateau_de_jeu[MAX][MAX],int taille_logique_chevalet,char chevalet_joueur[MAX_DECK], char*alphabet, int occurrence_point[][COLONNES]);
int placementVertical( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],char* alphabet,int occurrence_point[][COLONNES]);
int placementHorizontal( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],char* alphabet,int occurrence_point[][COLONNES]);
int placementAutreLettre( int i, int j, char plateau_de_jeu[MAX][MAX],char chevalet_joueur[MAX_DECK], int taille_logique_chevalet, char* alphabet,int occurrence_point[][COLONNES]);
int placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],unsigned int *pnombreLettres, char*alphabet, int occurrence_point[][COLONNES]);


#endif