#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "initialiser_poissons.c"
#include "afficher_support_de_jeux_pair.c"
#include "afficher_support_de_jeux_impair.c"

int main() {
    int ligne = 3;
    int colonne = 3;
    int poissons[ligne][colonne];
    if ((colonne % 2) == 0){
    afficher_support_de_jeux_pair(ligne, ((colonne/2)+1), poissons);
    } else {
    afficher_support_de_jeux_impair(ligne, (colonne/2+1), poissons);
    }
    return 0;
}
