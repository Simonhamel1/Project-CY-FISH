#include "player.h"

void initialiser_joueurs(int nbre_joueur, Joueur joueurs[6]) {

        for (int i = 0; i < nbre_joueur; i++) {
            printf("Entrez le nom du joueur %d : ", i + 1);
            scanf("%s", joueurs[i].nom);
            joueurs[i].score = 0; // Initialize the score to 0
        }

        printf("Les joueurs sont :\n");
        for (int i = 0; i < nbre_joueur; i++) {
            printf("%s (Score: %d)\n", joueurs[i].nom, joueurs[i].score);
        }
}
