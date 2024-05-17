#include "case.h"
#include <stdio.h>

// Fonction qui demande à l'utilisateur de choisir une case et retourne cette case
Case demander_case(int** poissons, int colonne, int ligne) {
    Case case_choisie; // Pour stocker les coordonnées de la case choisie
    int choix;
    do {
        printf("\nVous voulez voir quelle case ? ");
        scanf("%d %d", &case_choisie.x, &case_choisie.y);
        
        // Vérification que les indices fournis sont dans les limites de la grille
        while ((case_choisie.x == ligne - 1 && case_choisie.y % 2 == 1) || 
               case_choisie.x > ligne - 1 || case_choisie.y > colonne - 1 || 
               case_choisie.x < 0 || case_choisie.y < 0) {
            printf("La case n'existe pas, veuillez la redonner : \n");
            scanf("%d %d", &case_choisie.x, &case_choisie.y);
        }
        
        // Affichage du nombre de poissons dans la case donnée
        printf("Il y a %d poissons dans la case [%d][%d].\n", poissons[case_choisie.x][case_choisie.y], case_choisie.x, case_choisie.y);
        
        // Demande à l'utilisateur s'il souhaite continuer à voir d'autres cases
        printf("Voulez-vous revoir une case ? (0 pour oui, 1 pour non) : ");
        scanf("%d", &choix);
    } while (choix != 1);

    return case_choisie; // Retourne la dernière case consultée
}
