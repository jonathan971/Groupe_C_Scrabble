#include <stdio.h>
#include "Regle.h"
#include "Bienvenue.h"
#include "laPioche.h"


void mapping_pioche(pioche pioche1){

}
void distribution_pioche(pioche pioche1){

}

int main() {
    unsigned int choix, nb_player=0, valide=0, jeu=1;
    int occurrence_point[LIGNES][COLONNES] = {{0}};
    char alphabet[LIGNES], lapioche[JETONS];
    char lettre;
    Joueur Player;
    pioche pioche1;
    char chevalet_joueur[MAX_DECK]={36};
    char plateau_de_jeu[MAX][MAX]={{36,32,32,38,32,32,32,36,32,32,32,38,32,32,36},
                                   {32,64,32,32,32,37,32,32,32,37,32,32,32,64,32},
                                   {32,32,64,32,32,32,38,32,38,32,32,32,64,32,32},
                                   {38,32,32,64,32,32,32,38,32,32,32,64,32,32,38},
                                   {32,32,32,32,64,32,32,32,32,32,64,32,32,32,32},
                                   {32,37,32,32,32,37,32,32,32,37,32,32,32,37,32},
                                   {32,32,38,32,32,32,38,32,38,32,32,32,38,32,32},
                                   {36,32,32,38,32,'P','L','A','N','E','T',32,32,32,36},
                                   {32,32,38,32,32,32,38,32,38,32,32,32,38,32,32},
                                   {32,37,32,32,32,37,32,32,32,37,32,32,32,37,32},
                                   {32,32,32,32,64,32,32,32,32,32,64,32,32,32,32},
                                   {38,32,32,64,32,32,32,38,32,32,32,64,32,32,38},
                                   {32,32,64,32,32,32,38,32,38,32,32,32,64,32,32},
                                   {32,64,32,32,32,37,32,32,32,37,32,32,32,64,32},
                                   {36,32,32,38,32,32,32,36,32,32,32,38,32,32,36}};
    bienvenue_jeu(&choix);
    switch (choix) {
        case 1:
            intialisation_joueur(&Player,&nb_player);
            printf("\t\t\t\t\t\t\t\t\t    DEBUT DE LA PARTIE\n");
            do {
                affichage_tableau_2D(plateau_de_jeu, MAX);
                printf("\n");
                printf("%s a vous\n",Player[i].nom);//Utiliser le nom du joueur (pointeur sur nom joeur)
                chevalet(chevalet_joueur, &pioche1, MAX_DECK);
                printf("\n");
                afficherMenuPendantPartie(&choix);
                /*do {
                    if (choix == 2) {
                        do {
                            printf("Placer votre mot"
                                   "Entrer lettre par lettre");
                            scanf("%c", &lettre);
                            for (int i=0;i<MAX_DECK;i++){
                            if(lettre==chevalet_joueur[i]){
                                valide=1;
                            }
                            else {
                                valide=0;
                            }
                            }
                        }while (valide=1);//répète si lettre saisie est différente des lettres presente dans ke chevalier
                        printf("Saisir les coordonnées de la case\n");
                        scanf("%d %d",&x,&y)//case du tableau
                        do{
                            //regarder si la case est occupée
                        }
                        //fonction qui place la lettre
                        compteur_de_lettre+=1; //compteur qui va servir a obligé le depot de 2 lettres à 7
                        //fonction qui reactualise le tableau
                    }
                     printf("Voulez-vous poser une autre lettre ?\n
                         1-OUI\n
                         2-NON\n");
                         scanf("%d",&choix);
                         printf("\n");
                         if(choix==2 && compteur_de_lettre==1){
                         printf("Vous ne pouvez pas poser une seule lettre, veuillez saisir une seconde lettre");
                         choix==1;
                         }
                    }while(choix==1 && (compteur_de_lettre>1 && compteur_de_lettre<7));
                        //fonction qui recharge le chevalet
                    }
                }while (choix == 2);*/
            }while (jeu!=1);//jeu fini (il faudra changer la valeur à 0 quand on aura tout fini)
            break;
        case 2:
            choix=0;
            regle_jeu(&choix);
            break;
        case 3:
            credits(&choix);
        case 4:
            break;
    }
    return 0;
}
