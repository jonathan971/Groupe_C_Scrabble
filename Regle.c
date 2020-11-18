#include "Bienvenue.h"
void regle_jeu(unsigned int *choix) {
    do {
        for (int i = 0; i < 19; ++i) {
            printf("_");
        }
        printf("LES REGLES");
        for (int i = 0; i < 20; ++i) {
            printf("_");
        }
        printf("\n");
        printf("\t\t\t\t    Sommaire\n"
               "\t\t\t\t1. Generalités\n"
               "\t\t\t\t2. Matériel de jeu\n"
               "\t\t\t\t3. Début de partie\n"
               "\t\t\t\t4. Le tour de jeu\n"
               "\t\t\t\t5. La contestation\n"
               "\t\t\t\t6. Le chronométrage de la partie\n"
               "\t\t\t\t7. La fin de partie\n");
        for (int i = 0; i < 49; ++i) {
            printf("_");
        }
        printf("\n");
        printf("Choisissez votre partie\n");
        scanf("%d", choix);
        printf("\n");
        switch (*choix) {
            case 1 :
                printf("1. Généralités\n"
                       "Le Scrabble classique est un jeu de lettres qui se pratique à deux, trois ou quatre joueurs. Les parties opposant deux joueurs, assis l’un en face de l’autre, sont les seules pratiquées en compétition, c'est pourquoi le présent règlement ne traite que de celles-ci, mais les règles suivantes sont facilement applicables aux parties à trois ou quatre joueurs.\n"
                       "Le jeu consiste à former des mots entrecroisés sur une grille avec des lettres de valeurs différentes, les cases de couleur de la grille permettant de multiplier la valeur des lettres ou des mots. Le gagnant est celui qui cumule le plus grand nombre de points à l'issue de la partie.");
                retour(choix);
                break;

            case 2:do{
                    printf("2. Matériel de jeu\n"
                           "2.1. Le matériel des joueurs\n"
                           "2.2. Le matériel des arbitres\n");
                    scanf("%d", choix);
                    printf("\n");}while (*choix>2);
                switch (*choix) {
                    case 1:do{
                            printf("2.1. Le matériel des joueurs\n");
                            *choix = 0;
                            printf("2.1.1. Le plateau de jeu et les lettres\n"
                                   "2.1.2. Chevalets\n"
                                   "2.1.3. La pendule\n");
                            printf("Choisissez votre sous-partie (saisir le dernier chiffre de la sous-partie)\n");
                            scanf("%d", choix);
                            printf("\n");}while (*choix>3);

                        switch (*choix) {
                            case 1:
                                printf("2.1.1. Le plateau de jeu et les lettres\n"
                                       "Le plateau de jeu est constitué de cases rangées dans 15 lignes et 15 colonnes (soit 225 cases en tout).\n"
                                       "Les lignes sont précédées d’un nombre et les colonnes d’une lettre. Le type de ses cases est soit simple, soit complexe (dites « multiplicatrices »)\n"
                                       "Le jeu est composé de 102 pièces dont 2 jokers\n");
                                retour(choix);
                                break;
                            case 2:
                                printf("2.1.2. Chevalets\n"
                                       "Chaque joueur dispose d'un chevalet pour y placer leurs lettres. Ce chevalet se compose de 7 pieces de jeu.\n"
                                       "Dans le jeu du joueur, chaque lettre est accompagnée par son score : ex A1 représente le jeton A de score 1, G2, représente le jeton G de score 2, etc.\n");
                                retour(choix);
                                break;
                            case 3:
                                printf("2.1.3. La pendule\n"
                                       "La durée des parties est contrôlée par une pendule, décomptant le temps de jeu de chaque joueur.\n"
                                       "En début de partie, la pendule est initialisé sur le temps de jeu fixé par l’organisateur(1 min).\n");
                                retour(choix);
                                break;
                            default:
                                break;
                        }

                    case 2:
                        printf("2.2. Le matériel des arbitres\n"
                               "L'arbitre (l'odinateur) dispose de verificateur, permettant de verifier l'exsistance du mot. Ce verificateur prend pour source un dictionnaire.\n");
                        retour(choix);
                        break;
                    default:
                        break;
                }
                break;

            case 3 :
                *choix = 0;do{
            printf("3. Début de partie\n"
                   "3.1. Détermination du joueur qui commence\n"
                   "3.2. Tirage des lettres\n"
                   "Choisissez votre sous-partie (saisir le dernier chiffre de la sous-partie)\n");
            scanf("%d", choix);
            printf("\n");}while (*choix>2);
                switch (*choix) {

                    case 1:
                        printf("3.1. Détermination du joueur qui commence\n"
                               "Le joueur qui commence est le premier à avoir saisi son nom\n");
                        retour(choix);
                        break;
                    case 2:
                        printf("3.2. Tirage des lettres\n"
                               "Le tirage des lettre se fait de maniere aleatoire\n");
                        retour(choix);
                        break;
                    default:
                        break;
                }
                break;

            case 4:do{
                    printf("4. Le tour de jeu\n"
                           "Chaque joueur a la possibilité, à son tour de jeu, de placer un mot, de passer son tour ou de rejeter une ou plusieurs lettres.\n");
                    printf("4.1. Placer un mot\n"
                           "4.2. Passer son tour\n"
                           "4.3. Changer une ou plusieurs lettres\n"
                           "Choisissez votre sous-partie (saisir le dernier chiffre de la sous-partie)\n");
                    scanf("%d", choix);
                    printf("\n");}while (*choix>3);

                switch (*choix) {
                    case 1:do{
                            printf("4.1. Placer un mot\n");
                            *choix = 0;
                            printf("4.1.1. Formation et placement des mots\n"
                                   "4.1.2. Décompte des points\n"
                                   "4.1.3. Fin du tour\n"
                                   "Choisissez votre sous-partie (saisir le dernier chiffre de la sous-partie)\n");
                            scanf("%d", choix);
                            printf("\n");}while (*choix>3);

                        switch (*choix) {
                            case 1:
                                printf("4.1.1. Formation et placement des mots\n"
                                       "Le joueur forme avec une ou plusieurs lettres de son tirage ainsi qu’avec les lettres du ou des mots éventuellement placés, un mot de deux lettres ou plus.\n"
                                       "Le premier mot doit recouvrir la case étoilée centrale. Les mots suivants sont placés soit perpendiculairement, soit parallèlement à un mot déjà placé.\n"
                                       "Les mots doivent toujours être écrits de gauche à droite ou de haut en bas.\n"
                                       "Un mot déjà placé peut être prolongé par l’avant, par l’arrière ou simultanément par l’avant et l’arrière.\n"
                                       "Pendant son tour de jeu, un joueur est libre de poser et de reprendre librement ses lettres sur la grille, mais il ne doit pas déplacer les lettres jouées aux coups précédents.\n");
                                retour(choix);
                                break;
                            case 2:
                                printf("4.1.2. Décompte des points\n"
                                       "Chaque lettre a une valeur indiquée dans son angle inférieur droit, sauf les jokers qui sont de valeur nulle. a. Incidence des cases de couleur\n"
                                       "Le placement d'une lettre sur une case :\n"
                                       "%c, double la valeur de la lettre ;\n"
                                       "%c, triple la valeur de la lettre ;\n"
                                       "%c, double la valeur du mot ;\n"
                                       "%c, triple la valeur du mot.\n"
                                       "Les règles se combinent le cas échéant. Dès qu'une case de couleur est recouverte, elle perd son effet multiplicateur pour les coups ultérieurs.\n",
                                       38, 37, 64, 36);
                                printf("4.1.2.1. Mots formés simultanément\n"
                                       "Lorsque deux ou plusieurs mots sont formés lors d'un même coup, les valeurs de chacun de ces mots se cumulent, la valeur de la ou des lettres communes est reprise dans chaque mot avec ses points de prime éventuels : si une lettre placée sur une case de couleur est commune à deux mots, le coefficient multiplicateur s'applique aux deux mots formés.\n");
                                retour(choix);
                                break;

                            case 3:
                                printf("4.1.3. Fin du tour\n"
                                       "Après avoir posé le mot, le programme annonce le score et reinitialise l'horloge à zero\n"
                                       "Le programme extrait le nombre de lettres permettant de compléter le jeu du jeu à sept lettres - sauf dans le cas où il ne reste pas suffisamment de lettres, dans ce cas il prend ce qu’il reste.\n");
                                retour(choix);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        printf("4.2. Passer son tour\n"
                               "Il est possible, pour un joueur dont c’est le tour, de n’effectuer aucun mouvement. Ainsi, à n’importe quel moment, il peut passer son tour en annonçant clairement : « JE PASSE ».\n"
                               "Chaque joueur peut passer son tour autant de fois qu’il le souhaite au cours d’une partie. Toutefois, si les deux joueurs passent chacun leur tour trois fois consécutivement (donc six « JE PASSE »), la partie s’arrête et chaque joueur défalque de son cumul la valeur de ses lettres. Ceci est également valable si aucun mot n’a été posé.\n");
                        retour(choix);
                        break;
                    case 3:
                        printf("4.3. Changer une ou plusieurs lettres\n"
                               "Lorsqu’il reste au moins sept lettres dans le sac, il est possible pour un joueur dont c’est le tour, de changer tout ou partie de ses lettres.\n"
                               "Le joueur qui change de lettres ne peut pas en placer sur la grille dans le même tour.\n"
                               "Le joueur doit annoncer « JE CHANGE n LETTRES », n étant le nombre de lettres qu’il désire changer. La pendule se met en pause et le joeur termine son tour. Il tire ensuite n lettres dans le sac, puis remet les lettres qu’il rejette dans le sac.\n"
                               "Le joueur ne peut pas changer plus ou moins de lettres que le nombre qu’il a annoncé.\n"
                               "\n");
                        retour(choix);
                        break;
                    default:
                        break;
                }
                break;

            case 5:
                printf("5. La contestation\n"
                       "5.1. Validité des mots\n"
                       "Sont admis au Scrabble classique tous les mots repris en tête d'article dans l’édition de l'Officiel du Scrabble (ODS) en vigueur. Les flexions de ces mots (féminins, pluriels, formes verbales) sont admises si l'ODS les valide explicitement ou implicitement.\n"
                       "La liste des mots valables est intégrée dans un logiciel de validation, agréé par la FISF, qui peut être utilisé lors de vérifications effectuées par les joueurs eux-mêmes.\n"
                       "5.2 Procédure de contestation\n"
                       "Le programme indique au joueur que son mot est incorrect");
                retour(choix);
                break;


            case 6:
                printf("6. Le chronométrage de la partie\n"
                       "6.1. Chaque joueur a 1 min de jeu par tour\n"
                       "6.2. Des l'affichage du chavalet du joeur, la pendule est actionnée\n"
                       "6.3. Quand il a fini de jouer le joueur arrete le temps\n");
                retour(choix);
                break;


            case 7 :
                printf("7. La fin de partie\n"
                       "%c Les différents types de fin de partie\n"
                       "Reliquat épuisé : c’est la situation la plus courante, qui se produit lorsqu’un joueur a épuisé toutes ses lettres et que le sac est vide.\n"
                       "La valeur des lettres restant à l’adversaire est alors défalquée de son cumul et est ajoutée au cumul du joueur ayant terminé.\n"
                       "Blocage : il se peut que les joueurs ne trouvent plus de mots à jouer, et qu’il ne reste pas suffisamment de lettres dans le sac pour changer de lettres, dans ce cas chaque joueur défalque de son cumul la somme de la valeur des lettres qui lui restent.\n"
                       "Refus de jeu : si les deux joueurs ont passé chacun trois fois consécutivement sans qu’aucun mot n’ait été posé, chacun marque en négatif, la valeur de la somme de ses lettres.\n"
                       "%c Gain de la partie\n"
                       "Une fois appliquées les éventuelles pénalités et les règles du paragraphe Les différents types de fin de partie, le joueur qui a au moins un point de plus que l’autre, est déclaré vainqueur de la partie. En cas d’égalité, ils sont déclarés ex æquo.\n",42,42);
                retour(choix);
                break;
            default:
                break;
        }
        printf("\n\n");
    }while(*choix>7);
}


void credits(unsigned int *choix) {
    printf("Scrabble par des ING1 "
           "Jonathan VELIN & Paul NAVON & Kenza ERRAJI\n"
           "\t\t\t\t\t\t\t2020-2021\n"
           "\t\t\t\t\t\t\t   ECE\n");
    do{
        printf("Revenir au menu principal ?\n");
        printf("1-Oui\n");
        printf("2-Non\n");
        scanf("%d",choix);}while (*choix>2);
    switch (*choix) {
        case 1 :
            choix=0;
            bienvenue_jeu(choix);
            break;
        default: break;
    }
}
void retour(unsigned int *choix){
    do{
        do{
            *choix=0;

            printf("\n"
                   "\n"
                   "Revenir au sommaire?\n");
            printf("1-Oui\n");
            printf("2-Non\n");
            scanf("%d",choix);}while (*choix>2);
        if(*choix==1){
            *choix=0;
            regle_jeu(choix);
        }
        else if (*choix==2){
            *choix=0;
            bienvenue_jeu(choix);
        }
    }while (*choix==1);
}

