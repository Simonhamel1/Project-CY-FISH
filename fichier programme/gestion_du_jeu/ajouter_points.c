#include "case.h"
#include "demander_case.h"
#include "../initialisation/initialiser_joueur/player.h"

void ajouter_points(int** poissons, int colonne, int ligne, Player* joueurs, int nbre_joueur, int joueur_actuel) {
    if (joueur_actuel < 0 || joueur_actuel >= nbre_joueur) {
        printf("Index du joueur actuel invalide.\n");
        return;
    }

    Case case_choisie = demander_case(poissons, colonne, ligne);
    int x = case_choisie.x;
    int y = case_choisie.y;

    // Validation des indices x et y
    if (x < 0 || x >= colonne || y < 0 || y >= ligne) {
        printf("Indices de case hors limites.\n");
        return;
    }

    int nbre_poisson = poissons[x][y];
    joueurs[joueur_actuel].score += nbre_poisson;
    printf("Le joueur %d a maintenant %d points.\n", joueur_actuel, joueurs[joueur_actuel].score);
}
