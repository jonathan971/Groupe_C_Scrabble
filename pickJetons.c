#include "pickJetons.h"

char pickJetons(char lapioche[]){
    srand(time(NULL));
    int alea,modiftaillephysique=0;
    char lettre, securite;
    alea=rand()%(JETONS-modiftaillephysique);
    lettre=lapioche[alea];
    securite=lapioche[JETONS-modiftaillephysique];
    lapioche[JETONS-modiftaillephysique]=lettre;
    lapioche[alea]=securite;
    modiftaillephysique++;
    return lettre;
}