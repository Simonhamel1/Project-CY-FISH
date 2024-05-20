#include "mouvement.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// Fonction pour vérifier si le mouvement est valide
bool mouvement_valide(int x, int y, int nouvelle_x, int nouvelle_y, int ligne, int colonne, int **poissons) {
    // Vérification des limites du plateau et des cases interdites
    if (nouvelle_x < 0 || nouvelle_x >= ligne || nouvelle_y < 0 || nouvelle_y >= colonne || poissons[nouvelle_x][nouvelle_y] == 0 || poissons[nouvelle_x][nouvelle_y] == 4) {
        return false;
    }

    // Les six directions possibles dans une grille hexagonale
    int dx = nouvelle_x - x;
    int dy = nouvelle_y - y;

    // Vérifier les déplacements valides dans une grille hexagonale
    if ((dx == 1 && dy == 0) || (dx == -1 && dy == 0) || 
        (dx == 0 && dy == 1) || (dx == 0 && dy == -1) || 
        (dx == 1 && dy == -1) || (dx == -1 && dy == 1)) {
        return true;
    }

    return false;
}


bool joueur_peut_bouger(Joueur joueur, int ligne, int colonne, int **poissons) {
    for (int i = 0; i < joueur.nombre_pingouins; i++) {
        int x = joueur.pingouins[i].x;
        int y = joueur.pingouins[i].y;
        // Vérification dans les six directions possibles
        int directions[6][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}};
        for (int d = 0; d < 6; d++) {
            int nouvelle_x = x + directions[d][0];
            int nouvelle_y = y + directions[d][1];
            if (mouvement_valide(x, y, nouvelle_x, nouvelle_y, ligne, colonne, poissons)) {
                return true;
            }
        }
    }
    return false;
}
