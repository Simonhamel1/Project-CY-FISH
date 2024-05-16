int variante1(int fishes[], int size) {
    int score = 0;
    for (int i = 0; i < size; i++) {
        score += fishes[i];  // Chaque poisson vaut 1 point
    }
    return score;
}