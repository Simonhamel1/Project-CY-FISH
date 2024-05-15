#include <stdio.h>
#include "initialiser_joueurs.h"

void initialiser_joueurs(int *nbre_joueur, char noms_joueurs[6][50]) {
    printf("Entrez le nombre de joueurs (entre 2 et 6) : ");
    scanf("%d", nbre_joueur);

    if (*nbre_joueur < 2 || *nbre_joueur > 6) {
        printf("Le nombre de joueurs doit être entre 2 et 6.\n");
        exit(1); // Exit the program as the number of players is invalid
    } else {
        for (int i = 0; i < *nbre_joueur; i++) {
            printf("Entrez le nom du joueur %d : ", i + 1);
            scanf("%s", noms_joueurs[i]);
        }

        printf("Les joueurs sont :\n");
        for (int i = 0; i < *nbre_joueur; i++) {
            printf("%s\n", noms_joueurs[i]);
        }
    }
}
