#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialiser_poissons(int ligne, int colonne, int poissons[][colonne]) {
        srand(time(0)); // Initialisation du générateur de nombres aléatoires

        for (int i = 0; i < ligne; i++) {
            for (int j = 0; j < colonne; j++) {
            poissons[i][j] = rand() % 4; // Génération d'un nombre aléatoire de poissons (0 ou 3)
            while (poissons[i][j]==0){
                poissons[i][j] = rand() % 4;
            }
        }
  }
}

void afficher_support_de_jeux_impair(int ligne, int colonne, int poissons[][colonne]) {
    initialiser_poissons(ligne, colonne ,poissons) ;// Initialisation du générateur de nombres aléatoires

    for (int i = 0; i < ligne+1; i++) {
        // Affichage de la partie supérieure du motif
        for (int j = 0; j < colonne; j++) {
            if (i==0){
                printf("  ____      ");
            }
        }
        printf("\n");

        // Affichage de la partie centrale du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
            if (i==ligne && j ==0){
               printf("      \\     "); 
            }
            else if (i== ligne && j == colonne-1){
                printf(" /          ");
            }
            else if (i==0){
                    printf(" /    \\     ");
                }
            else if (i!= 0 && j==colonne-1){
                    printf(" /    \\");
                    }
            else{ if(j+1 < colonne) {
                    if (poissons[i][j] == 0 ) {
                        printf(" /    \\     ");
                    } else if (poissons[i][j] == 3){
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
            if ( (i==ligne) && j==colonne-1){
                printf("/");
                }
            else if (j != colonne - 1) {
                if (i==ligne && j==0){
                    printf("       \\____");
                }
                else if(poissons[i][j] == 0 || i == ligne){
                    printf("/      \\____");
                } else {
                    printf("/  \U0001F41F  \\____");
                }
            } else {
                if(poissons[i][j] == 0){
                    printf("/      \\");
                } else {
                    printf("/  \U0001F41F  \\");
                }
            }
        }
        printf("\n");
        if (i!=ligne){
        // Affichage de la partie centrale du motif (inversée) avec des poissons
        for (int j = 0; j < colonne; j++) {
            if (j != colonne - 1) {
                if(poissons[i][j] == 0){
                    printf("\\      /    ");
                } 
                else if(poissons[i][j] == 2){
                    printf("\\ \U0001F41F\U0001F41F /    ");
                }else {
                    printf("\\  \U0001F41F  /    ");
                }
            } else {
                if(poissons[i][j] == 0){
                    printf("\\      /");
                } else {
                    printf("\\ \U0001F41F\U0001F41F /");
                }
            }
        }
        printf("\n");

        // Affichage de la partie inférieure du motif avec des poissons
        for (int j = 0; j < colonne; j++) {
                if (i==ligne-1){
                    printf(" \\____/     ");
                }
                else{
                    if (poissons[i][j] == 3) {
                        if (j==colonne-1){
                            printf(" \\____/");
                            }else{
                            printf(" \\____/  \U0001F41F ");
                            }
                    } else {
                        printf(" \\____/     ");
                    }
                }
                
            }
        ;
    }
    }
}





void afficher_support_de_jeux_pair(int ligne, int colonne, int poissons[][colonne]) {
    initialiser_poissons(ligne, colonne, poissons); // Initialisation du générateur de nombres aléatoires

    for (int i = 0; i < ligne+1; i++) {
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

int main() {
    int ligne = 5;
    int colonne = 8;
    int poissons[ligne][colonne];
    if ((colonne % 2) == 0){
    afficher_support_de_jeux_pair(ligne, ((colonne/2)+1), poissons);
    } else {
    afficher_support_de_jeux_impair(ligne, (colonne/2+1), poissons);
    }
    
    return 0;
}
