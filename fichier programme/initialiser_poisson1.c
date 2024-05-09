void initialiser_poissons1(int ligne, int colonne, int** poissons) {
    for (int i = 0; i < ligne; i++) {
            for (int j = 0; j < colonne; j++) {
                poissons[i][j] = 1; // Génération d'un nombre aléatoire de poissons (0 ou 3)
            }
        }
}    