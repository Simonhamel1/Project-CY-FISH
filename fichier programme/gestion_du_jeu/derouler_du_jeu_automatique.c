#include "../afficher_support_de_jeux_pair.h"
#include "../afficher_support_de_jeux_impair.h"
#include "afficher_joueur.h"
#include "ajouter_points.h"
#include "mouvement.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FISH_NORMAL 1
#define FISH_ROTTEN 2
#define FISH_GOLDEN 3
void derouler_jeu_automatique(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6], int variante) {
    bool jeu_termine = false;
    while (!jeu_termine) {
        jeu_termine = true;
        for (int i = 0; i < nbre_joueur; i++) {
            if (joueur_peut_bouger(joueurs[i], ligne, colonne, poissons)) {
                jeu_termine = false;
                printf("Tour de %s\n", joueurs[i].nom);
                
                int pingouin_id = rand() % joueurs[i].nombre_pingouins; // Sélection aléatoire du pingouin
                int nouvelle_x, nouvelle_y;
                bool move_found = false;

                for (int direction = 0; direction < 6; direction++) {
                    int dx = 0, dy = 0;
                    switch (direction) {
                        case 0: dx = -1; break; // gauche
                        case 1: dx = 1; break; // droite
                        case 2: dy = -1; break; // haut
                        case 3: dy = 1; break; // bas
                        case 4: dx = -1; dy = 1; break; // haut-gauche
                        case 5: dx = 1; dy = -1; break; // bas-droite
                    }
                    nouvelle_x = joueurs[i].pingouins[pingouin_id].x + dx;
                    nouvelle_y = joueurs[i].pingouins[pingouin_id].y + dy;

                    if (mouvement_valide(joueurs[i].pingouins[pingouin_id].x, joueurs[i].pingouins[pingouin_id].y, nouvelle_x, nouvelle_y, ligne, colonne, poissons)) {
                        move_found = true;
                        break;
                    }
                }

                if (move_found) {
                    int x = joueurs[i].pingouins[pingouin_id].x;
                    int y = joueurs[i].pingouins[pingouin_id].y;
                    joueurs[i].pingouins[pingouin_id].x = nouvelle_x;
                    joueurs[i].pingouins[pingouin_id].y = nouvelle_y;
                    
                    ajouter_points(poissons, x, y, &joueurs[i], variante);

                    poissons[x][y] = 0;
                    poissons[nouvelle_x][nouvelle_y] = 4;
                    if ((colonne % 2) == 0) {
                        afficher_support_de_jeux_pair(ligne, colonne, poissons, nbre_joueur, joueurs);
                    } else {
                        afficher_support_de_jeux_impair(ligne, colonne, poissons, nbre_joueur, joueurs);
                    }
                }
            }
        }
    }

    printf("Fin du jeu!\n");
    afficher_joueur(nbre_joueur, joueurs);
    int gagnant = 0;
    for (int i = 1; i < nbre_joueur; i++) {
        if (joueurs[i].score > joueurs[gagnant].score) {
            gagnant = i;
        }
    }
    printf("Le gagnant est %s avec %d points!\n", joueurs[gagnant].nom, joueurs[gagnant].score);
}
