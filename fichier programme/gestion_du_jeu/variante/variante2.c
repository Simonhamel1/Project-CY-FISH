int variante2(int fishes[], int size) {
    int score = 0;
    srand(time(0));  // Initialiser le générateur de nombres aléatoires
    for (int i = 0; i < size; i++) {
        int rotten = 0;
        if (fishes[i] > 1) {
            rotten = rand() % 2;  // 50% de chance d'avoir un poisson avarié si plus d'un poisson
        }
        score += fishes[i] - 2 * rotten;  // Soustraire 2 pour chaque poisson avarié
    }
    return score;
}