#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "initialiser_poissons.c"
#include "initialiser_poisson1.c"
#include "afficher_support_de_jeux_pair.c"
#include "afficher_support_de_jeux_impair.c"
#include "demander_case.c"

int main() {
    int ligne = 3;
    int colonne = 3;
    printf("vous voulez combien de ligne : ");
    scanf("%d",&ligne);
    printf("vous voulez combien de colonne ");
    scanf("%d",&colonne);

    //Allocation de mémoire pour le tableau dynamique
    int **poissons = malloc(ligne * sizeof(int*));
    for (int i = 0; i < ligne; i++) {
    poissons[i] = malloc(colonne * sizeof(int));
    }

    //initialiser_poissons1(ligne, colonne, poissons) ;
    initialiser_poissons(ligne, colonne ,poissons) ;
    if ((colonne % 2) == 0){
        afficher_support_de_jeux_pair(ligne, colonne, poissons);
    } else {
        afficher_support_de_jeux_impair(ligne, colonne, poissons);
    }
    
    demander_case(poissons);

    // Libération de la mémoire allouée pour le tableau dynamique
    for (int i = 0; i < ligne; i++) {
        free(poissons[i]);
    }
    free(poissons);

    printf("finish programme \U0001F600");
    return 0;
}