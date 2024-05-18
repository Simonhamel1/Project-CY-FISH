    #include "initialisation/initialiser_joueur/player.h"

    void afficher_support_de_jeux_pair(int ligne, int colonne, int **poissons, int nbre_joueur, Joueur joueurs[6]) {
        for (int i = 0; i < ligne; i++) {
            // Affichage de la partie supérieure du motif
            for (int j = 0; j < colonne; j += 2) {
                if (i == 0) {
                    printf("  ____      ");
                }
            }
            printf("\n");

            // Affichage de la partie centrale du motif avec des poissons
            for (int j = 0; j < colonne; j += 2) {
                if (i == 0) {
                    printf(" /    \\     ");
                } else if (i != 0 && j == colonne - 1) {
                    printf(" /    \\");
                } else {
                        if (poissons[i-1][j+1] == 0 || poissons[i-1][j+1] == 1) {
                            printf(" /    \\     ");
                        } else if (poissons[i-1][j+1] == 3) {
                            printf(" /    \\ \U0001F41F\U0001F41F");
                        } else if (poissons[i-1][j+1] == 2){
                            printf(" /    \\  \U0001F41F ");
                        }
                }
                if (j==colonne-2 && i != 0){
                    printf(" /") ;
                }
            }
            printf("\n");

            // Affichage de la partie intermédiaire du motif avec des poissons
            for (int j = 0; j < colonne; j += 2) {
                if (j != colonne - 1) {
                    if (poissons[i][j] == 0) {
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
                if (i != 0 && j== colonne -2){
                    printf("/");
                }
            }
            printf("\n");

            // Affichage de la dernière ligne du motif avec des poissons
            for (int j = 0; j < colonne; j += 2) {
                if (poissons[i][j] == 0 || poissons[i][j] == 1) {
                    printf("\\      /    ");
                } else if (poissons[i][j] == 3) {
                    printf("\\ \U0001F41F\U0001F41F /    ");
                } else if (poissons[i][j] == 2) {
                    printf("\\  \U0001F41F  /    ");
                }
            if (j==colonne-2 && i!=ligne-1){
                printf("\\");
            }
            }
            printf("\n");

            // Affichage de la partie inférieure du motif avec des poissons
            for (int j = 0; j < colonne; j += 2) {   
                if ( i== ligne-1){
                    printf(" \\____/     ");
                }
                else { 
                    if (poissons[i][j+1]!=0){
                        printf(" \\____/  \U0001F41F ");
                    }
                    else {
                    printf(" \\____/     ");
                    }
                }
                if (j==colonne-2 && i != ligne-1){
                    printf(" \\") ;
                }
            } 
        }
        printf("\n\n");
        // Display player names and scores
        printf("Les joueurs sont :\n");
        for (int i = 0; i < nbre_joueur; i++)   {
            printf("Joueur %d : %s (Score: %d)\n", i + 1, joueurs[i].nom, joueurs[i].score);
        }
    }
