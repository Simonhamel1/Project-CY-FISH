#include <stdio.h>
#include "case.h"
#include "../initialisation/initialiser_joueur/player.h"
#include "demander_case.c"
#include "../initialisation/initialiser_pingouin.c"
#include "deplacer_pinguoin.c"

bool peut_joueur_bouger(Player joueur, Case** poissons, int colonne, int ligne);
void afficher_support_de_jeux_pair(int ligne, int colonne, Case** poissons, int nbre_joueur, Player* joueurs);
void afficher_support_de_jeux_impair(int ligne, int colonne, Case** poissons, int nbre_joueur, Player* joueurs);
void afficher_scores(Player* joueurs, int nbre_joueur);

void derouler_du_jeu(Case** poissons, int colonne, int ligne, Player* joueurs, int nbre_joueur, int variante) {
    int i;
    bool tous_bloques = false;

    while (!tous_bloques) {
        tous_bloques = true;

        for (i = 0; i < nbre_joueur; i++) {
            if (peut_joueur_bouger(joueurs[i], poissons, colonne, ligne)) {
                tous_bloques = false;
                printf("\nC'est au tour de %s de jouer.\n", joueurs[i].nom);
                // Demande à l'utilisateur de choisir une case
                Case case_choisie = demander_case(poissons, colonne, ligne);
                // Demande à l'utilisateur de choisir un pingouin
                Pingouin pingouin_choisi = joueurs[i].pingouins[0]; // Example placeholder
                // Déplacement du pingouin
                deplacer_pingouin(poissons, colonne, ligne, joueurs, nbre_joueur, i, case_choisie, pingouin_choisi, variante);
                // Affichage du support de jeu
                if ((colonne % 2) == 0) {
                    afficher_support_de_jeux_pair(ligne, colonne, poissons, nbre_joueur, joueurs);
                } else {
                    afficher_support_de_jeux_impair(ligne, colonne, poissons, nbre_joueur, joueurs);
                }
            } else {
                printf("\n%s ne peut pas bouger.\n", joueurs[i].nom);
            }
        }
    }

    // Affichage du message de fin de jeu et des scores
    printf("\nTous les joueurs sont bloqués. Fin du jeu!\n");
    afficher_scores(joueurs, nbre_joueur);
}
