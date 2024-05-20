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


void derouler_jeu(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6],int variante) {

    bool jeu_termine = false;

    while (!jeu_termine) {
        jeu_termine = true;
        for (int i = 0; i < nbre_joueur; i++) {
            if (joueur_peut_bouger(joueurs[i], ligne, colonne, poissons)) {
                jeu_termine = false;
                printf("Tour de %s\n", joueurs[i].nom);
                
                int pingouin_id = -1;
                while (pingouin_id < 0 || pingouin_id >= joueurs[i].nombre_pingouins) {
                    printf("Choisissez le pingouin à déplacer (0 à %d) : ", joueurs[i].nombre_pingouins - 1);
                    if (scanf("%d", &pingouin_id) != 1) {
                        while (getchar() != '\n'); // Clear input buffer
                        pingouin_id = -1;
                        printf("Entrée invalide. ");
                    }
                }

                int direction = -1;
                while (direction < 0 || direction > 5) {
                    printf("Choisissez la direction (0: gauche, 1: droite, 2: haut, 3: bas, 4: haut-gauche, 5: bas-droite) : ");
                    if (scanf("%d", &direction) != 1) {
                        while (getchar() != '\n'); // Clear input buffer
                        direction = -1;
                        printf("Entrée invalide. ");
                    }
                }

                int dx = 0, dy = 0;
                switch (direction) {
                    case 0: dx = -1; break; // gauche
                    case 1: dx = 1; break; // droite
                    case 2: dy = -1; break; // haut
                    case 3: dy = 1; break; // bas
                    case 4: dx = -1; dy = 1; break; // haut-gauche
                    case 5: dx = 1; dy = -1; break; // bas-droite
                }

                int nouvelle_x = joueurs[i].pingouins[pingouin_id].x + dx;
                int nouvelle_y = joueurs[i].pingouins[pingouin_id].y + dy;

                if (mouvement_valide(joueurs[i].pingouins[pingouin_id].x, joueurs[i].pingouins[pingouin_id].y, nouvelle_x, nouvelle_y, ligne, colonne, poissons)) {
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
                } else {
                    printf("Mouvement invalide. Veuillez réessayer.\n");
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

        printf("Merci d'avoir joué!\n");
}
