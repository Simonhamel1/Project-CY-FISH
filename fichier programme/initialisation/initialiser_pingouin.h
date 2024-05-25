#ifndef INITIALISER_PINGOUINS_H
#define INITIALISER_PINGOUINS_H

#include "initialiser_joueur/player.h"
#include "initialiser_poissons.h"

// Déclaration des fonctions
int definir_nombre_pingouins(Joueur* joueurs, int nb_joueur);
void initialisation_Pingouin(Joueur* joueurs, int nb_joueur, int lignes, int colonnes, int** poissons);

#endif // INITIALISER_PINGOUINS_H

