void afficher_support_de_jeux_pair(int ligne, int colonne, int** poissons) {

    for (int i = 0; i < ligne; i++) {
        // Affichage de la partie supérieure du motif
        for (int j = 0; j < colonne; j++) {
            if ((i==0)&&(j!=colonne-1)){
                printf("  ____      ");
            }
        }
        printf("\n");
        // Affichage de la partie centrale 
        for (int j = 0; j < colonne; j++) {
            if (j != colonne - 1) {
                if(i==ligne&&j==0){
                    if (poissons[i][j]==0){
                    printf("      \\     ");
                    }else{
                    printf("      \\  \U0001F41F ");
                    }
                }else{ if(j+1 < colonne) {
                    if (i==0){
                        printf(" /    \\     ");
                    }
                    else {if (poissons[i][j] == 0 ) {
                        printf(" /    \\     ");
                    } else if (poissons[i][j] == 3){
                        printf(" /    \\ \U0001F41F\U0001F41F");
                    } else {
                        printf(" /    \\  \U0001F41F ");
                    }
                    }
                }
                }            
            } else if (i != 0) {
                printf(" /");
            }
        }
        printf("\n");

        // Affichage de la partie intermédiaire du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
            int num_fish = rand() % 2; // Génération d'un nombre aléatoire de poissons (0 à 3)
            if (j != colonne - 1) {
                if(num_fish == 0 || i == ligne){
                    if (i==ligne && j==0){
                    printf("       \\____");
                }else{
                    printf("/      \\____");
                }
                } else {
                    printf("/  \U0001F41F  \\____");
                }
            } else {
                if(i != 0){
                   printf("/");
                }
            }
        }
        printf("\n");
        if (i != ligne ){
        // Affichage de la partie centrale du motif (inversée) avec des poissons
        for (int j = 0; j < colonne; j++) {
            int num_fish = rand() % 3; // Génération d'un nombre aléatoire de poissons (0 à 3)
            
            if (j != colonne - 1) {
                if(num_fish == 0){
                    printf("\\      /    ");
                } 
                else if(num_fish == 2){
                    printf("\\ \U0001F41F\U0001F41F /    ");
                }else {
                    printf("\\  \U0001F41F  /    ");
                }
            } else {
                if(i != ligne){
                    printf("\\");
                }
            }
        }
        printf("\n");

        // Affichage de la partie inférieure du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
            
            if (j != colonne - 1) {
                printf(" \\____/     ");
            } else if (i != ligne) {
                printf(" \\");
            }
        }}
        ;
    }
}