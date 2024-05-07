#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "initialiser_poissons.c"
#include "afficher_support_de_jeux_pair.c"
#include "afficher_support_de_jeux_impair.c"

int main() {
    int ligne = 5;
    int colonne = 7;
    //printf("vous voulez combien de ligne : ");
    //scanf("%d",&ligne);
    //printf("vous voulez combien de colonne ");
    //scanf("%d",&colonne);

    // Allocation de mémoire pour le tableau dynamique
    int **poissons = malloc(ligne * sizeof(int*));
    for (int i = 0; i < ligne; i++) {
        poissons[i] = malloc(colonne * sizeof(int));
    }
    initialiser_poissons(ligne, colonne ,poissons) ;
    if ((colonne % 2) == 0){
        afficher_support_de_jeux_pair(ligne, ((colonne/2)+1), poissons);
    } else {
        afficher_support_de_jeux_impair(ligne, (colonne/2+1), poissons);
    }
    printf("quelle case ? ");
    int case_x,case_y;
    scanf("%d %d",& case_x,&case_y);
    printf("il y a %d poissons dans la case [%d][%d]",poissons[case_x][case_y],case_x,case_y);

    // Libération de la mémoire allouée pour le tableau dynamique
    for (int i = 0; i < ligne; i++) {
        free(poissons[i]);
    }
    free(poissons);

    return 0;
}