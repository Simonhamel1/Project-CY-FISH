typedef struct {
    int x;
    int y;
} Placement;

typedef struct {
    int occupe;  // Indique si la case est occupée (0 = non, 1 = oui)
    int fish;    // Nombre de poissons dans la case (pré-initialisé ailleurs)
} Verif;

void initialisation_Penguins(Placement tab[], Verif grille[][10], int lignes, int colonnes, int nb_joueur) {
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    for (int i = 0; i < nb_joueur; i++) {
        int placed = 0;
        while (!placed) {
            int x = rand() % lignes; 
            int y = rand() % colonnes;

            // Vérifier si la case est libre et contient exactement un poisson
            if (grille[x][y].occupe == 0 && grille[x][y].fish == 1) {
                tab[i].x = x;
                tab[i].y = y;
                grille[x][y].occupe = 1; // Marquer la case comme occupée
                placed = 1; // Indiquer qu'un pingouin a été placé
                printf("Pingouin %d placé à (%d,%d)\n", i, x, y);
            }
        }
    }
}

void afficherGrille(Verif grille[][10], int lignes, int colonnes) {
    printf("État actuel de la grille:\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (grille[i][j].occupe) {
                printf("X "); // Afficher une croix pour une case occupée
            } else {
                printf(". "); // Afficher un point pour une case non occupée
            }
        }
        printf("\n");
    }
}