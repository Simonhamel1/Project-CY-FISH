#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "initialiser_poissons.c"
#include "afficher_support_de_jeux_pair.c"
#include "afficher_support_de_jeux_impair.c"

int main() {
    int ligne = 3;
    int colonne = 4;
    //printf("vous voulez combien de ligne : ");
    //scanf("%d",&ligne);
    //printf("vous voulez combien de colonne ");
    //scanf("%d",&colonne);
    int poissons[ligne][colonne];
    if ((colonne % 2) == 0){
    initialiser_poissons(ligne, colonne ,poissons) ;// Initialisation du générateur de nombres aléatoires
    afficher_support_de_jeux_pair(ligne, ((colonne/2)+1), poissons);
    } else {
    afficher_support_de_jeux_impair(ligne, (colonne/2+1), poissons);
    }
    return 0;
}
