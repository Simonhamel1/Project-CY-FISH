#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initialiser_joueur/player.h"

// Define the number of penguins based on the number of players
void definir_nombre_pingouins(Joueur* joueurs, int nb_joueur) {
    int pingouins_par_joueur;

    while (1) {
        if (nb_joueur == 2) {
            pingouins_par_joueur = 4;
            break;
        } else if (nb_joueur == 3) {
            pingouins_par_joueur = 3;
            break;
        } else if (nb_joueur == 4) {
            pingouins_par_joueur = 2;
            break;
        } else if (nb_joueur == 5 || nb_joueur == 6) {
            pingouins_par_joueur = 1;
            break;
        } else {
            printf("Le nombre de joueurs doit être entre 2 et 6.\n");
            printf("Redonner le nombre de joueurs : ");
            scanf("%d", &nb_joueur);
        }
    }

    for (int i = 0; i < nb_joueur; i++) {
        joueurs[i].nombre_pingouins = pingouins_par_joueur;
        joueurs[i].pingouins = (Pingouin*) malloc(pingouins_par_joueur * sizeof(Pingouin));
        for (int j = 0; j < pingouins_par_joueur; j++) {
            joueurs[i].pingouins[j].numero_pingouin = j + 1; // Assign a unique number to each penguin
        }
    }
}

void initialisation_Pingouin(Joueur* joueurs, int nb_joueur, int lignes, int colonnes, int** poissons) {
    srand(time(0)); // Seed random number generator

    definir_nombre_pingouins(joueurs, nb_joueur);

    printf("Voulez-vous initialiser les pingouins automatiquement (0 -> oui, 1 -> non) : ");
    int choix;
    scanf("%d", &choix);
    while (choix != 1 && choix != 0) {
        printf("Redonnez votre choix : ");
        scanf("%d", &choix);
    }

    for (int i = 0; i < nb_joueur; i++) {
        for (int j = 0; j < joueurs[i].nombre_pingouins; j++) {
            int x, y;
            if (choix == 1) { // Manual mode
                printf("Entrez les coordonnées pour le pingouin %d de %s (x y) : ", joueurs[i].pingouins[j].numero_pingouin, joueurs[i].nom);
                scanf("%d %d", &x, &y);
                while (x < 0 || x >= lignes || y < 0 || y >= colonnes || poissons[x][y] != 1) {
                    printf("Case non possible. Entrez de nouvelles coordonnées pour le pingouin %d de %s (x y) : ", joueurs[i].pingouins[j].numero_pingouin, joueurs[i].nom);
                    scanf("%d %d", &x, &y);
                }
            } else if (choix == 0) { // Automatic mode
                do {
                    x = rand() % lignes;
                    y = rand() % colonnes;
                } while (poissons[x][y] != 1 || (x==lignes-1 && y%2==1));
            }
            joueurs[i].pingouins[j].x = x;
            joueurs[i].pingouins[j].y = y;
            poissons[x][y] = 4; // Mark the cell as occupied
            printf("Pingouin %d de %s placé à (%d, %d)\n", joueurs[i].pingouins[j].numero_pingouin-1, joueurs[i].nom, x, y);
        }
    }
}
