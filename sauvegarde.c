#include "sauvegarde.h"

void sauvegarder(Joueur Player[], char plateau_de_jeu[][MAX], char* lapioche,const int* nb_player,int*i, const int* modiftaillephysique){
    FILE* sauvegardeTXT= fopen("..\\sauvegardeTXT.txt","w");
    FILE* sauvegardeChiffre= fopen("..\\sauvegardeChiffre.dat","w");
    fputs((char *) plateau_de_jeu,sauvegardeTXT);
    fputs((char *) lapioche,sauvegardeTXT);
    for(int t=0;t<(*nb_player);t++){
        fputs(Player[t].nom,sauvegardeTXT);
        fputs(Player[t].chevalet_joueur,sauvegardeTXT);
    }
    for(int t=0;t<(*nb_player);t++){
        fwrite((const void *) Player[t].score, sizeof(int), 1, sauvegardeChiffre);
    }
    fwrite(i, sizeof(int), 1, sauvegardeChiffre);
    fwrite((const void *) *modiftaillephysique, sizeof(int), 1, sauvegardeChiffre);
    fclose(sauvegardeTXT);
    fclose(sauvegardeChiffre);
    printf("Sauvegarde réalisé avec succès!\n");
}

void retourSauvegarde(Joueur Player[], char plateau_de_jeu[][MAX], char* lapioche,const int* nb_player,int*i, const int* modiftaillephysique){
    FILE* sauvegardeTXT= fopen("..\\sauvegardeTXT.txt","r");
    FILE* sauvegardeChiffre= fopen("..\\sauvegardeChiffre.dat","r");
    fread((void *) *modiftaillephysique, sizeof(int), 1, sauvegardeChiffre);
    fgets((char *) plateau_de_jeu,MAX,sauvegardeTXT);
    fgets((char *) lapioche,*modiftaillephysique,sauvegardeTXT);
    int t;
    while(fgetc(sauvegardeTXT)!=EOF){
        for(t=0;t<(*nb_player);t++){
            if(fgetc(sauvegardeTXT)=='|'){
                fseek(sauvegardeTXT,+1,SEEK_CUR);
            }
            fgets(Player[t].nom,MAX_PSEUDO,sauvegardeTXT);
            fgets(Player[t].chevalet_joueur,MAX_DECK,sauvegardeTXT);
        }
    }
    while(fgetc(sauvegardeChiffre)!=EOF){
        for(t=0;t<(*nb_player);t++){
            fread((void *) Player[t].score, sizeof(int), 1, sauvegardeChiffre);
        }
    }
    fread(i, sizeof(int), 1, sauvegardeChiffre);
    fclose(sauvegardeTXT);
    fclose(sauvegardeChiffre);
    printf("Informations récupérées!\n");
}