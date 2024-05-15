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
                
                    if (poissons[i][j+1] == 0 || poissons[i][j] == 1) {
                        printf(" /    \\     ");
                    } else if (poissons[i][j+1] == 3) {
                        printf(" /    \\ \U0001F41F\U0001F41F");
                    } else if (poissons[i][j+1] == 2){
                        printf(" /    \\  \U0001F41F ");
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
            if (poissons[i][j] == 0 || poissons[i][j] == 1) {
                printf("\\      /    ");
            } else if (poissons[i][j] == 3) {
                printf("\\ \U0001F41F\U0001F41F /    ");
            } else if (poissons[i][j] == 2) {
                printf("\\  \U0001F41F  /    ");
            }
        }
        printf("\n");

        // Affichage de la partie inférieure du motif avec des poissons
        for (int j = 0; j < colonne; j++) {   
            if ( i== ligne-1 || j == colonne-1){
                printf(" \\____/     ");
            }
            else {
                if (poissons[i][j+1]==1){
                    printf(" \\____/  \U0001F41F ");
                }
                else {
                printf(" \\____/     ");
                }
            }
        }
    
    }
}
