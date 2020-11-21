#include "pickJetons.h"

char pickJetons(char lapioche[], int* modiftaillephysique){
    srand(time(NULL));
    int alea;
    char lettre, securite;
    alea=rand()%(JETONS-*modiftaillephysique);
    lettre=lapioche[alea];
    securite=lapioche[JETONS-*modiftaillephysique];
    lapioche[JETONS-*modiftaillephysique]=lettre;
    lapioche[alea]=securite;
    (*modiftaillephysique)++;
    return lettre;
}