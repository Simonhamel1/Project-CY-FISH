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

void derouler_jeu(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6], int variante) {
    bool jeu_termine = false;
    while (!jeu_termine) {
        jeu_termine = true;
        for (int i = 0; i < nbre_joueur; i++) {
            if (joueur_peut_bouger(joueurs[i], ligne, colonne, poissons)) {
                jeu_termine = false;
                printf("Tour de %s\n", joueurs[i].nom);
                
                int pingouin_id = rand() % joueurs[i].nombre_pingouins; // Sélection aléatoire du pingouin
                int nouvelle_x, nouvelle_y;

                do {
                    int direction = rand() % 4; // 0: gauche, 1: droite, 2: haut, 3: bas
                    int dx = 0, dy = 0;
                    switch (direction) {
                        case 0: dy = -1; break; // gauche
                        case 1: dy = 1; break; // droite
                        case 2: dx = -1; break; // haut
                        case 3: dx = 1; break; // bas
                    }
                    nouvelle_x = joueurs[i].pingouins[pingouin_id].x + dx;
                    nouvelle_y = joueurs[i].pingouins[pingouin_id].y + dy;
                } while (!mouvement_valide(joueurs[i].pingouins[pingouin_id].x, joueurs[i].pingouins[pingouin_id].y, nouvelle_x, nouvelle_y, ligne, colonne, poissons));

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

    printf("Fin du jeu!\n");
    afficher_joueur(nbre_joueur, joueurs);
    int gagnant = 0;
    for (int i = 1; i < nbre_joueur; i++) {
        if (joueurs[i].score > joueurs[gagnant].score) {
            gagnant = i;
        }
    }
    printf("Le gagnant est %s avec %d points!\n", joueurs[gagnant].nom, joueurs[gagnant].score);

    int recommencer = -1;
    while (recommencer < 0 || recommencer > 1) {
        printf("Voulez-vous recommencer une partie? (0 -> oui, 1 -> non) : ");
        if (scanf("%d", &recommencer) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            recommencer = -1;
            printf("Entrée invalide. ");
        }
    }

    if (recommencer == 0) {
        for (int i = 0; i < ligne; i++) {
            for (int j = 0; j < colonne; j++) {
                poissons[i][j] = (rand() % 3) + 1;
            }
        }
        for (int i = 0; i < nbre_joueur; i++) {
            joueurs[i].score = 0;
        }
        derouler_jeu(ligne, colonne, poissons, nbre_joueur, joueurs, variante);
    } else {
        printf("Merci d'avoir joué!\n");
    }
}
