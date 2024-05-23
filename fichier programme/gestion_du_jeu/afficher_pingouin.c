#include "../initialisation/initialiser_joueur/player.h"
#include "afficher_pingouin.h"

void afficher_pingouin(int nb_joueur, Joueur joueurs[6], int **poissons) {
    for (int i = 0; i < nb_joueur; i++) {
        for (int j = 0; j < joueurs[i].nombre_pingouins; j++) {
            int x = joueurs[i].pingouins[j].x;
            int y = joueurs[i].pingouins[j].y;
            poissons[x][y] = 4; // Marquer la cellule comme occupée
            printf("Pingouin %d de %s placé à (%d, %d)\n", joueurs[i].pingouins[j].numero_pingouin-1, joueurs[i].nom, x, y);
        }
    }
}
