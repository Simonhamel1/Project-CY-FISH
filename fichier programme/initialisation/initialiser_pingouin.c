#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "verif.h"
#include "initialiser_joueur/player.h"

void initialisation_Pingouin(Joueur* joueurs, int nb_joueur, Verif grille[][10], int lignes, int colonnes, int mode) {
    srand(time(0)); // Initialisation du générateur de nombres aléatoires

    for (int i = 0; i < nb_joueur; i++) {
        for (int j = 0; j < joueurs[i].nombre_pingouins; j++) {
            if (mode == 1) { // Mode manuel
                int x, y;
                printf("Entrez les coordonnées pour le pingouin %d de %s (x y) : ", j + 1, joueurs[i].nom);
                scanf("%d %d", &x, &y);
                while (grille[x][y].occupe != 0 || grille[x][y].fish != 1) {
                    printf("Case invalide. Entrez de nouvelles coordonnées pour le pingouin %d de %s (x y) : ", j + 1, joueurs[i].nom);
                    scanf("%d %d", &x, &y);
                }
                joueurs[i].pingouins[j].x = x;
                joueurs[i].pingouins[j].y = y;
                grille[x][y].occupe = 1; // Marquer la case comme occupée
                printf("Pingouin %d de %s placé à (%d,%d)\n", j + 1, joueurs[i].nom, x, y);
            } else { // Mode automatique
                int placed = 0;
                while (!placed) {
                    int x = rand() % lignes; 
                    int y = rand() % colonnes;

                    // Vérifier si la case est libre et contient exactement un poisson
                    if (grille[x][y].occupe == 0 && grille[x][y].fish == 1) {
                        joueurs[i].pingouins[j].x = x;
                        joueurs[i].pingouins[j].y = y;
                        grille[x][y].occupe = 1; // Marquer la case comme occupée
                        placed = 1; // Indiquer qu'un pingouin a été placé
                        printf("Pingouin %d de %s placé à (%d,%d)\n", j + 1, joueurs[i].nom, x, y);
                    }
                }
            }
        }
    }
}
