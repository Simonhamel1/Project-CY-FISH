#ifndef MOUVEMENT_H
#define MOUVEMENT_H
#include <stdbool.h>
#include <stdio.h>
#include "../initialisation/initialiser_joueur/player.h"

// focntion mouvement valide
bool mouvement_valide(int x, int y, int nouvelle_x, int nouvelle_y, int ligne, int colonne, int **poissons);

// fonction joueur peut bouger
bool joueur_peut_bouger(Joueur joueur, int ligne, int colonne, int **poissons);

// fonction pingouin peut bouger
bool pingouin_peut_bouger(Pingouin pingouin, int ligne, int colonne, int **poissons);

#endif
