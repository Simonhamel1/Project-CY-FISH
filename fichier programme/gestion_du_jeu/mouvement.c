#include "mouvement.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// Fonction pour vérifier si le mouvement est valide
bool mouvement_valide(int x, int y, int nouvelle_x, int nouvelle_y, int ligne, int colonne, int **poissons) {
    // Vérification des limites du plateau et des cases interdites
    if (nouvelle_x < 0 || nouvelle_x >= ligne || nouvelle_y < 0 || nouvelle_y >= colonne || poissons[nouvelle_x][nouvelle_y] == 0 || poissons[nouvelle_x][nouvelle_y] == 4 || ((nouvelle_x==ligne-1) &&(nouvelle_y %2==1))) {
        return false;
    }

    else{
        return true;
    }

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


bool pingouin_peut_bouger(Pingouin pingouin, int ligne, int colonne, int **poissons) {
    int x = pingouin.x;
    int y = pingouin.y;

    // Vérification dans les six directions possibles
    // Le déplacement change en fonction de la parité de la coordonnée y
    int directions[6][2];
    if (y % 2 == 0) {
        // y pair
        directions[0][0] = -1; directions[0][1] = 0;   // haut
        directions[1][0] = 1;  directions[1][1] = 0;   // bas
        directions[2][0] = -1;  directions[2][1] = -1;  // haut-gauche
        directions[3][0] = 0;  directions[3][1] = 1;   // bas-droite
        directions[4][0] = -1; directions[4][1] = 1;  // haut-droite
        directions[5][0] = 0;  directions[5][1] = -1;   // bas-gauche
    } else {
        // y impair
        directions[0][0] = -1; directions[0][1] = 0;   // haut
        directions[1][0] = 1;  directions[1][1] = 0;   // bas
        directions[2][0] = 0;  directions[2][1] = 1;   // haut-droite
        directions[3][0] = 1;  directions[3][1] = -1;  // bas-gauche
        directions[4][0] = 0; directions[4][1] = -1;   // haut-gauche
        directions[5][0] = 1;  directions[5][1] = 1;  // bas-droite
    }

    for (int d = 0; d < 6; d++) {
        int nouvelle_x = x + directions[d][0];
        int nouvelle_y = y + directions[d][1];

        // Vérifier si le mouvement est valide
        if (mouvement_valide(x, y, nouvelle_x, nouvelle_y, ligne, colonne, poissons)) {
            return true;
        }
    }

    return false;
}

