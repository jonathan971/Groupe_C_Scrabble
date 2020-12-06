cmake_minimum_required(VERSION 3.17)
project(Groupe_C_Scrabble C)

set(CMAKE_C_STANDARD 99)

add_executable(Groupe_C_Scrabble main.c Bienvenue.c Bienvenue.h joueur_initializer.c joueur_initializer.h Regle.c Regle.h TableauDeJeu.c TableauDeJeu.h laPioche.c laPioche.h Verification_chevalet.c Verification_chevalet.h joueurScore.c joueurScore.h)