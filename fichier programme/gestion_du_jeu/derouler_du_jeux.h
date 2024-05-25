#ifndef DEROULEMENT_JEU_H
#define DEROULEMENT_JEU_H

#include "../afficher/afficher_support_de_jeux_pair.h"
#include "../afficher/afficher_support_de_jeux_impair.h"
#include "derouler_du_jeux.h"
#include "afficher_joueur.h"
#include "afficher_pingouin.h"
#include "ajouter_points.h"

#define FISH_NORMAL 1
#define FISH_ROTTEN 2
#define FISH_GOLDEN 3


// Déclaration de la fonction derouler_jeu
void derouler_jeu(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6], int variante);

#endif // DEROULEMENT_JEU_H
