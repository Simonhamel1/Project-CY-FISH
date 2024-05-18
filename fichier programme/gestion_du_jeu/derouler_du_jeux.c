#include "../afficher_support_de_jeux_pair.h"
#include "../afficher_support_de_jeux_impair.h"
#include "afficher_joueur.h"
#include <stdbool.h>


bool mouvement_valide(int x, int y, int nouvelle_x, int nouvelle_y, int ligne, int colonne, int **poissons) {
    if (nouvelle_x < 0 || nouvelle_x >= ligne || nouvelle_y < 0 || nouvelle_y >= colonne || poissons[nouvelle_x][nouvelle_y] == 0) {
        return false;
    }
    if (x == nouvelle_x || y == nouvelle_y) {
        int dx = (nouvelle_x - x) != 0 ? (nouvelle_x - x) / abs(nouvelle_x - x) : 0;
        int dy = (nouvelle_y - y) != 0 ? (nouvelle_y - y) / abs(nouvelle_y - y) : 0;
        int i = x + dx, j = y + dy;
        while (i != nouvelle_x || j != nouvelle_y) {
            if (poissons[i][j] == 0 || poissons[i][j] == 4) {
                return false;
            }
            i += dx;
            j += dy;
        }
        return true;
    }
    return false;
}

bool joueur_peut_bouger(Joueur joueur, int ligne, int colonne, int **poissons) {
    for (int i = 0; i < joueur.nombre_pingouins; i++) {
        int x = joueur.pingouins[i].x;
        int y = joueur.pingouins[i].y;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx != 0 || dy != 0) && mouvement_valide(x, y, x + dx, y + dy, ligne, colonne, poissons)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void derouler_jeu(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6]) {
    bool jeu_termine = false;
    while (!jeu_termine) {
        jeu_termine = true;
        for (int i = 0; i < nbre_joueur; i++) {
            if (joueur_peut_bouger(joueurs[i], ligne, colonne, poissons)) {
                jeu_termine = false;
                printf("Tour de %s\n", joueurs[i].nom);
                int pingouin_id, nouvelle_x, nouvelle_y;
                printf("Choisissez le pingouin à déplacer (0 à %d) : ", joueurs[i].nombre_pingouins - 1);
                scanf("%d", &pingouin_id);
                printf("Entrez les nouvelles coordonnées (x y) : ");
                scanf("%d %d", &nouvelle_x, &nouvelle_y);
                while (!mouvement_valide(joueurs[i].pingouins[pingouin_id].x, joueurs[i].pingouins[pingouin_id].y, nouvelle_x, nouvelle_y, ligne, colonne, poissons)) {
                    printf("Déplacement invalide. Entrez de nouvelles coordonnées (x y) : ");
                    scanf("%d %d", &nouvelle_x, &nouvelle_y);
                }
                int x = joueurs[i].pingouins[pingouin_id].x;
                int y = joueurs[i].pingouins[pingouin_id].y;
                joueurs[i].pingouins[pingouin_id].x = nouvelle_x;
                joueurs[i].pingouins[pingouin_id].y = nouvelle_y;
                joueurs[i].score += poissons[x][y];
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
    printf("Voulez-vous recommencer une partie? (0 -> oui, 1 -> non) : ");
    int recommencer;
    scanf("%d", &recommencer);
    if (recommencer == 0) {
        for (int i = 0; i < ligne; i++) {
            for (int j = 0; j < colonne; j++) {
                poissons[i][j] = (rand() % 3) + 1;
            }
        }
        for (int i = 0; i < nbre_joueur; i++) {
            joueurs[i].score = 0;
        }
        derouler_jeu(ligne, colonne, poissons, nbre_joueur, joueurs);
    } else {
        printf("Merci d'avoir joué!\n");
    }
}
