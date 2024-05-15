#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "afficher_support_de_jeux/afficher_support_de_jeux_pair.c"
#include "afficher_support_de_jeux/afficher_support_de_jeux_pair.h"
#include "afficher_support_de_jeux/afficher_support_de_jeux_impair.c"
#include "afficher_support_de_jeux/afficher_support_de_jeux_impair.h"
#include "initialisation/initialiser_joueur/initialiser_joueurs.c"
#include "initialisation/initialiser_joueur/initialiser_joueurs.h"
#include "initialisation/initialiser_joueur/player.h"
#include "initialisation/debut_du_jeu.c"
#include "initialisation/initialiser_pingouin.c"
#include "initialisation/initialiser_poissons.c"
#include "pas_necessaire/demander_case.c"
#include "pas_necessaire/demander_case.c"

int main() {
    system("chcp 65001");

    // Initialisation joueurs
    int nbre_joueur;
    Player joueurs[6]; // Assume there can be up to 6 players

    initialiser_joueurs(&nbre_joueur, joueurs);

    // Initialisation plateau
    int ligne, colonne;
    printf("Vous voulez combien de ligne : ");
    scanf("%d", &ligne);
    printf("Vous voulez combien de colonne : ");
    scanf("%d", &colonne);
    
    // Allocation de mémoire pour le tableau dynamique
    int **poissons = malloc(ligne * sizeof(int *));
    if (poissons == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return 1; // Exit the program due to memory allocation failure
    }
    for (int i = 0; i < ligne; i++) {
        poissons[i] = malloc(colonne * sizeof(int));
        if (poissons[i] == NULL) {
            printf("Erreur d'allocation de mémoire.\n");
            return 1; // Exit the program due to memory allocation failure
        }
    }

    // Initialize and display the board
    //initialiser_poissons1(ligne, colonne, poissons);
    initialiser_poissons(ligne, colonne, poissons);
    if ((colonne % 2) == 0) {
        afficher_support_de_jeux_pair(ligne, colonne, poissons, nbre_joueur, joueurs);
    } else {
        afficher_support_de_jeux_impair(ligne, colonne, poissons, nbre_joueur, joueurs);
    }
    
    // Demander case
    demander_case(poissons);

    // Libération de la mémoire allouée pour le tableau dynamique
    for (int i = 0; i < ligne; i++) {
        free(poissons[i]);
    }
    free(poissons);

    printf("Finish programme \U0001F600\n");
    return 0;
}
