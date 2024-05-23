#include <stdio.h>

// Définition des constantes pour les variantes
#define FISH_NORMAL 1
#define FISH_ROTTEN 2
#define FISH_GOLDEN 3

// Prototype de la fonction pour choisir la variante
int choisir_variante() {
    int variante;
    printf("Choisissez une variante pour le jeu:\n");
    printf("1: Normal (Chaque poisson vaut 1 point)\n");
    printf("2: Rotten (Poissons peuvent être avariés, valant -1 point)\n");
    printf("3: Golden (Poissons valent 1, 2 ou 3 points)\n");
    scanf("%d", &variante);
    while ( variante < 1 || variante > 3) {
        printf("Choix invalide. Veuillez choisir une variante valide:\n");
        printf("1: Normal\n");
        printf("2: Rotten\n");
        printf("3: Golden\n");
        scanf("%d", &variante);
        // Vider le tampon d'entrée pour éviter les problèmes de lecture ultérieure
        while (getchar() != '\n');
    }
    return variante;
}