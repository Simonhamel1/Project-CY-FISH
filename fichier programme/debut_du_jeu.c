void debut_du_jeu() {
    int nombre_joueurs;
    char noms_joueurs[6][50]; // Assumer que le nom de chaque joueur ne dépasse pas 50 caractères

    printf("Entrez le nombre de joueurs (entre 2 et 6) : ");
    scanf("%d", &nombre_joueurs);

    if (nombre_joueurs < 2 || nombre_joueurs > 6) {
        printf("Le nombre de joueurs doit être entre 2 et 6.\n");
    } else {
        for (int i = 0; i < nombre_joueurs; i++) {
            printf("Entrez le nom du joueur %d : ", i + 1);
            scanf("%s", noms_joueurs[i]);
        }

        printf("Les joueurs sont :\n");
        for (int i = 0; i < nombre_joueurs; i++) {
            printf("%s\n", noms_joueurs[i]);
        }
    }
}