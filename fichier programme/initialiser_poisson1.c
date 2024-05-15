void initialiser_poissons1(int ligne, int colonne, int** poissons) {
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            poissons[i][j] = 3;  // Initialise toutes les valeurs à 1
        }
    }
}