#ifndef CREATIONMOT_VERIFICATION_CHEVALET_H
#define CREATIONMOT_VERIFICATION_CHEVALET_H
#include <stdio.h>
#include <ctype.h>
#define MAX_DECK 8
#define MAX 15

void nombreDeLettres(unsigned int *pnombreLettres);
char sensDuMot();
void placementPremiereLettrePremierMot( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],int taille_logique_chevalet);
void placementPremiereLettre(char plateau_de_jeu[MAX][MAX],int taille_logique_chevalet,char chevalet_joueur[MAX_DECK]);
void placementVertical( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementHorizontal( char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK]);
void placementAutreLettre( int i, int j, char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],int taille_logique_chevalet);
void placementPremierMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],unsigned int *pnombreLettres);
void placementMot(char plateau_de_jeu[MAX][MAX], char chevalet_joueur[MAX_DECK],unsigned int *pnombreLettres);


#endif