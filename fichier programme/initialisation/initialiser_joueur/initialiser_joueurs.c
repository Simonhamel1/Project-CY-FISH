#include "player.h"

void initialiser_joueurs(int *nbre_joueur, Player joueurs[6]) {
    printf("Entrez le nombre de joueurs (entre 2 et 6) : ");
    scanf("%d", nbre_joueur);

    if (*nbre_joueur < 2 || *nbre_joueur > 6) {
        printf("Le nombre de joueurs doit être entre 2 et 6.\n");
        exit(1); // Exit the program as the number of players is invalid
    } else {
        for (int i = 0; i < *nbre_joueur; i++) {
            printf("Entrez le nom du joueur %d : ", i + 1);
            scanf("%s", joueurs[i].name);
            joueurs[i].score = 0; // Initialize the score to 0
        }

        printf("Les joueurs sont :\n");
        for (int i = 0; i < *nbre_joueur; i++) {
            printf("%s (Score: %d)\n", joueurs[i].name, joueurs[i].score);
        }
    }
}
