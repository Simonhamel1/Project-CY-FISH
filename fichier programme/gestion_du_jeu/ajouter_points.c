#include "ajouter_points.h"
#include <stdio.h>
#include <stdlib.h>

// Ajoute les points au joueur en fonction de la variante choisie
#define FISH_NORMAL 1
#define FISH_ROTTEN 2
#define FISH_GOLDEN 3

// fonction ajouter points 
void ajouter_points(int **poissons, int x, int y, Joueur *joueur, int variante) {
    int points = 0;
    int nbre_poisson = poissons[x][y];
    
    switch (variante) {
        // Variante 1
        case FISH_NORMAL:
            points = nbre_poisson; // Chaque poisson vaut 1 point
            break;

        case FISH_ROTTEN:
        // Variante 2
            if (nbre_poisson > 1 && (rand() % 2 == 0)) { // Ajouter de l'aléatoire pour les poissons avariés
                points = nbre_poisson - 1;
                printf("Le joueur %s a trouvé un poisson avarié!\n", joueur->nom);
            } else {
                points = nbre_poisson;
            }
            break;

        case FISH_GOLDEN:
        // Variante 3
        for (int i = 0; i<nbre_poisson ;i++){
                points += (rand() % 3) + 1; // Poisson seul peut valoir 1, 2 ou 3 points
        }
            break;

        default:
            printf("Variante non reconnue.\n"); // normalement inutile car on verifie avant
            return;
    }

    joueur->score += points;
}
