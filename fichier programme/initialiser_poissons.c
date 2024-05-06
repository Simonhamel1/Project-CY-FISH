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
