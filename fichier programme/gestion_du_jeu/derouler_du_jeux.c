#include "../afficher/afficher_support_de_jeux_pair.h"
#include "../afficher/afficher_support_de_jeux_impair.h"
#include "afficher_joueur.h"
#include "afficher_pingouin.h"
#include "ajouter_points.h"
#include "mouvement.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FISH_NORMAL 1
#define FISH_ROTTEN 2
#define FISH_GOLDEN 3

// Fonction derouler jeu
void derouler_jeu(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6], int variante) {
    bool jeu_termine = false;

    while (!jeu_termine) {
        jeu_termine = true;
        for (int i = 0; i < nbre_joueur; i++) {
            printf("Tour de %s\n", joueurs[i].nom);

            bool pingouin_peut_se_deplacer = false;
            for (int j = 0; j < joueurs[i].nombre_pingouins; j++) {
                if (pingouin_peut_bouger(joueurs[i].pingouins[j], ligne, colonne, poissons)) {
                    pingouin_peut_se_deplacer = true;
                    break;
                }
            }

            if (pingouin_peut_se_deplacer) {
                jeu_termine = false;

                int pingouin_id = -1;
                while (true) {
                    printf("Choisissez le pingouin à déplacer (0 à %d) (-1 si vous voulez quitter la partie) : ", joueurs[i].nombre_pingouins - 1);
                    scanf("%d", &pingouin_id);
                    if (pingouin_id == -1) {
                        printf("Voulez-vous vraiment quitter la partie ? (1: oui, 0: non) : ");
                        int quitter = -1;
                        scanf("%d", &quitter);
                        while (getchar() != '\n'); // Vider le tampon d'entrée pour éviter les problèmes de lecture ultérieure
                        if (quitter == 1) {
                            jeu_termine = true;
                            break;
                        } else {
                            continue;
                        }
                    }
                    if (pingouin_id >= 0 && pingouin_id < joueurs[i].nombre_pingouins && pingouin_peut_bouger(joueurs[i].pingouins[pingouin_id], ligne, colonne, poissons)) {
                        break;
                    } else {
                        printf("Entrée invalide ou le pingouin ne peut pas bouger. Veuillez réessayer.\n");
                    }
                }

                if (jeu_termine) break; // Sort de la boucle principale si le joueur a choisi de quitter

                bool mouvement_valide_flag = false;
                while (!mouvement_valide_flag) {
                    int direction = -1;
                    while (direction < 0 || direction > 5) {
                        printf("Choisissez la direction (0: haut, 1: bas, 2: haut gauche, 3: bas-droite, 4: haut-droite, 5: bas-gauche) : ");
                        scanf("%d", &direction);
                        if (direction < 0 || direction > 5) {
                            printf("Entrée invalide. Veuillez réessayer.\n");
                        }
                        while (getchar() != '\n'); // Vider le tampon d'entrée pour éviter les problèmes de lecture ultérieure
                    }

                    int dx = 0, dy = 0;
                    switch (direction) {
                        case 0: dx = -1; break; // haut
                        case 1: dx = 1; break; // bas
                        case 2: if (joueurs[i].pingouins[pingouin_id].y % 2 == 0) { dy = -1; dx = -1; } else { dy = -1; } break; // haut-gauche
                        case 3: if (joueurs[i].pingouins[pingouin_id].y % 2 == 0) { dy = 1; } else { dy = 1; dx = 1; } break; // bas-droite
                        case 4: if (joueurs[i].pingouins[pingouin_id].y % 2 == 0) { dy = 1; dx = -1; } else { dy = 1; } break; // haut-droite
                        case 5: if (joueurs[i].pingouins[pingouin_id].y % 2 == 0) { dy = -1; } else { dy = -1; dx = 1; } break; // bas-gauche
                    }

                    int nouvelle_x = joueurs[i].pingouins[pingouin_id].x + dx;
                    int nouvelle_y = joueurs[i].pingouins[pingouin_id].y + dy;

                    if (mouvement_valide(joueurs[i].pingouins[pingouin_id].x, joueurs[i].pingouins[pingouin_id].y, nouvelle_x, nouvelle_y, ligne, colonne, poissons)) {
                        int x = joueurs[i].pingouins[pingouin_id].x;
                        int y = joueurs[i].pingouins[pingouin_id].y;
                        joueurs[i].pingouins[pingouin_id].x = nouvelle_x;
                        joueurs[i].pingouins[pingouin_id].y = nouvelle_y;

                        ajouter_points(poissons, nouvelle_x, nouvelle_y, &joueurs[i], variante);

                        poissons[x][y] = 0;
                        poissons[nouvelle_x][nouvelle_y] = 4;

                        afficher_pingouin(nbre_joueur, joueurs, poissons);

                        if ((colonne % 2) == 0) {
                            afficher_support_de_jeux_pair(ligne, colonne, poissons, nbre_joueur, joueurs);
                        } else {
                            afficher_support_de_jeux_impair(ligne, colonne, poissons, nbre_joueur, joueurs);
                        }

                        mouvement_valide_flag = true; // Le mouvement est valide, on sort de la boucle
                    } else {
                        printf("Mouvement invalide. Veuillez réessayer.\n");
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

    printf("Merci d'avoir joué!\n");
}
