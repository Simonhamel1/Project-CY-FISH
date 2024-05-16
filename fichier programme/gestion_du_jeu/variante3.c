int variante3(int fishes[], int size) {
    int score = 0;
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < fishes[i]; j++) {
            score += 1 + rand() % 3;  // Chaque poisson vaut 1, 2 ou 3 points
        }
    }
    return score;
}