#include <stdio.h>
#include "case.h"
#include "../initialisation/initialiser_joueur/player.h"


// Fonction pour déplacer un pingouin
void deplacer_pingouin(Case** poissons, int colonne, int ligne, Joueur* joueurs, int nbre_joueur, int joueur_index, Case case_choisie, Pingouin pingouin_choisi, int variante) {
    int x = pingouin_choisi.x;
    int y = pingouin_choisi.y;

    // Vérifiez si le déplacement est valide
    if (case_choisie.occupee == 0) {
        // Mettre à jour la position du pingouin
        poissons[x][y].occupee = 0;
        poissons[case_choisie.poissons][case_choisie.occupee].occupee = 1;
        for (int i = 0; i < joueurs[joueur_index].nombre_pingouins; i++) {
            if (joueurs[joueur_index].pingouins[i].x == x && joueurs[joueur_index].pingouins[i].y == y) {
                joueurs[joueur_index].pingouins[i].x = case_choisie.poissons;
                joueurs[joueur_index].pingouins[i].y = case_choisie.occupee;
                break;
            }
        }

        // Mettre à jour le score du joueur
        joueurs[joueur_index].score += case_choisie.poissons;
        
        // Afficher le déplacement
        printf("Le pingouin de %s a été déplacé de (%d,%d) à (%d,%d)\n", joueurs[joueur_index].nom, x, y, case_choisie.poissons, case_choisie.occupee);
    } else {
        printf("Déplacement invalide. La case est déjà occupée.\n");
    }
}
