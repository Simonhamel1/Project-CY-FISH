void afficher_support_de_jeux_impair(int ligne, int colonne, int** poissons) {

    for (int i = 0; i < ligne; i++) {
        // Affichage de la partie supérieure du motif
        for (int j = 0; j < colonne; j++) {
            if (i == 0) {
                printf("  ____      ");
            }
        }
        printf("\n");

        // Affichage de la partie centrale du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
            if (i == 0) {
                printf(" /    \\     ");
            } else if (i != 0 && j == colonne - 1) {
                printf(" /    \\");
            } else {
                if (j + 1 < colonne) {
                    if (poissons[i][j] == 0) {
                        printf(" /    \\     ");
                    } else if (poissons[i][j] == 3) {
                        printf(" /    \\ \U0001F41F\U0001F41F");
                    } else {
                        printf(" /    \\  \U0001F41F ");
                    }
                }
            }
        }
        printf("\n");

        // Affichage de la partie intermédiaire du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
            if (j != colonne - 1) {
                if (poissons[i][j] == 0 || i == ligne - 1) {
                    printf("/      \\____");
                } else {
                    printf("/  \U0001F41F  \\____");
                }
            } else {
                if (poissons[i][j] == 0) {
                    printf("/      \\");
                } else {
                    printf("/  \U0001F41F  \\");
                }
            }
        }
        printf("\n");

        // Affichage de la dernière ligne du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
            if (poissons[i][j] == 0) {
                printf("\\      /    ");
            } else if (poissons[i][j] == 3) {
                printf("\\ \U0001F41F\U0001F41F /    ");
            } else {
                printf("\\  \U0001F41F  /    ");
            }
        }
        printf("\n");

        // Affichage de la partie inférieure du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
            if (i == ligne - 1 && i != ligne-1) {
                if (j == colonne - 1 ) {
                    printf(" \\____/");
                } else {
                    printf(" \\____/  \U0001F41F ");
                }
            } else {
                printf(" \\____/     ");
            }
        }
    
    }
}
