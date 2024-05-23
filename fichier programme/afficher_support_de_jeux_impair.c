#include "initialisation/initialiser_joueur/player.h"
#include <stdio.h>

// Fonction pour afficher le plateau de jeu avec les numéros des pingouins sur les cases impaires
void afficher_support_de_jeux_impair(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6]) {
    for (int i = 0; i < ligne; i++) {
        // Affichage de la partie supérieure du motif
        for (int j = 0; j < colonne; j += 2) {
            if (i == 0) {
                printf("  ____      ");
            }
        }
        printf("\n");

        // Affichage de la partie centrale du motif avec des poissons et des pingouins
        for (int j = 0; j <= colonne; j += 2) {
            if (i == 0) {
                printf(" /    \\     ");
            } else {
                int joueur_id = -1;
                int pingouin_numero = -1;
                for (int k = 0; k < nbre_joueur; k++) {
                    for (int p = 0; p < joueurs[k].nombre_pingouins; p++) {
                        if (joueurs[k].pingouins[p].x == i - 1 && joueurs[k].pingouins[p].y == j + 1) {
                            joueur_id = joueurs[k].numero;
                            pingouin_numero = joueurs[k].pingouins[p].numero_pingouin;
                        }
                    }
                }
                if (poissons[i - 1][j + 1] == 0 || poissons[i - 1][j + 1] == 1 || j == colonne - 1) {
                    printf(" /    \\     ");
                } else if (joueur_id != -1) {
                    printf(" /    \\ \U0001F427J%d", joueur_id);
                } else if (poissons[i - 1][j + 1] == 3) {
                    printf(" /    \\ \U0001F41F\U0001F41F");
                } else if (poissons[i - 1][j + 1] == 2) {
                    printf(" /    \\  \U0001F41F ");
                }
            }
        }
        printf("\n");

        // Affichage de la partie intermédiaire du motif avec des poissons et des pingouins
        for (int j = 0; j < colonne; j += 2) {
            int joueur_id = -1;
            int pingouin_numero = -1;
            for (int k = 0; k < nbre_joueur; k++) {
                for (int p = 0; p < joueurs[k].nombre_pingouins; p++) {
                    if (joueurs[k].pingouins[p].x == i && joueurs[k].pingouins[p].y == j) {
                        joueur_id = joueurs[k].numero;
                        pingouin_numero = joueurs[k].pingouins[p].numero_pingouin;
                    }
                }
            }
            if (j != colonne - 1) {
                if (poissons[i][j] == 0 || (poissons[i][j] == 4 && joueur_id == -1)) {
                    printf("/      \\____");
                } else if (joueur_id != -1) {
                    printf("/  P%d  \\____", pingouin_numero-1);
                } else {
                    printf("/  \U0001F41F  \\____");
                }
            } else {
                if (poissons[i][j] == 0 || (poissons[i][j] == 4 && joueur_id == -1)) {
                    printf("/      \\");
                } else if (joueur_id != -1) {
                    printf("/  P%d  \\", pingouin_numero-1);
                } else {
                    printf("/  \U0001F41F  \\");
                }
            }
            if (i != 0 && j == colonne - 2) {
                printf("/");
            }
        }
        printf("\n");

        // Affichage de la dernière ligne du motif avec des poissons et des pingouins
        for (int j = 0; j < colonne; j += 2) {
            int joueur_id = -1;
            int pingouin_numero = -1;
            for (int k = 0; k < nbre_joueur; k++) {
                for (int p = 0; p < joueurs[k].nombre_pingouins; p++) {
                    if (joueurs[k].pingouins[p].x == i && joueurs[k].pingouins[p].y == j) {
                        joueur_id = joueurs[k].numero;
                        pingouin_numero = joueurs[k].pingouins[p].numero_pingouin;
                    }
                }
            }
            if (poissons[i][j] == 0 || (poissons[i][j] == 1 && joueur_id == -1)) {
                printf("\\      /    ");
            } else if (joueur_id != -1) {
                printf("\\ \U0001F427J%d /    ", joueur_id);
            } else if (poissons[i][j] == 3) {
                printf("\\ \U0001F41F\U0001F41F /    ");
            } else if (poissons[i][j] == 2) {
                printf("\\  \U0001F41F  /    ");
            }
            if (j == colonne - 2 && i != ligne - 1) {
                printf("\\");
            }
        }
        printf("\n");

        // Affichage de la partie inférieure du motif avec des poissons et des pingouins
        for (int j = 0; j < colonne; j += 2) {
            int joueur_id = -1;
            int pingouin_numero = -1;
            for (int k = 0; k < nbre_joueur; k++) {
                for (int p = 0; p < joueurs[k].nombre_pingouins; p++) {
                    if (joueurs[k].pingouins[p].x == i && joueurs[k].pingouins[p].y == j + 1) {
                        joueur_id = joueurs[k].numero;
                        pingouin_numero = joueurs[k].pingouins[p].numero_pingouin;
                    }
                }
            }
            if (i == ligne - 1 || j == colonne - 1) {
                printf(" \\____/     ");
            } else {
                if (poissons[i][j + 1] != 0 && poissons[i][j + 1] != 4) {
                    printf(" \\____/  \U0001F41F ");
                } else if (joueur_id != -1 || poissons[i][j + 1] == 4) {
                    printf(" \\____/  P%d ", pingouin_numero-1);
                } else {
                    printf(" \\____/     ");
                }
            }
            if (j == colonne - 2 && i != ligne - 1) {
                printf(" \\");
            }
        }
    }
    printf("\n");

    // Afficher les noms et les scores des joueurs
    printf("Les joueurs sont :\n");
    for (int i = 0; i < nbre_joueur; i++) {
        printf("Joueur %d : %s (Score: %d)\n", joueurs[i].numero, joueurs[i].nom, joueurs[i].score);
    }
}
