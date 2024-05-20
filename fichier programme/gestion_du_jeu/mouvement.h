#ifndef MOUVEMENT_H
#define MOUVEMENT_H
#include <stdbool.h>
#include "../initialisation/initialiser_joueur/player.h"

bool mouvement_valide(int x, int y, int nouvelle_x, int nouvelle_y, int ligne, int colonne, int **poissons);
bool joueur_peut_bouger(Joueur joueur, int ligne, int colonne, int **poissons);

#endif