
// fonction initialiser poissons
void initialiser_poissons(int ligne, int colonne, int** poissons, int pingouin_par_joueur , int nbre_joueur) {
    srand(time(0)); // Initialisation du générateur de nombres aléatoires

    printf("Voulez-vous initialiser les poissons automatiquement (0 -> oui, 1 -> non) : ");
    int choix;
    scanf("%d", &choix);

    //verification du choix
    while (choix != 1 && choix != 0) {
        printf("Redonnez votre choix : ");
        scanf("%d", &choix);

        while (getchar() != '\n');
    }

    if (choix == 1){// mode manuel
        for (int i = 0 ; i< ligne ; i++){
            for (int j = 0; j < colonne  ; j++) {
                printf("donner le nombre de poissons dans la case [%d][%d] : ",i,j);
                scanf("%d",&poissons[i][j]);
                while (poissons[i][j]<1 || poissons[i][j]>3 ){
                    printf("redonner le nombre de poissons dans la case [%d][%d] :",i,j);
                    scanf("%d",&poissons[i][j]);
                    while (getchar() != '\n');
                }
            }
        }
    }
    else{// Mode automatique
        for (int i = 0; i < ligne; i++) {
            for (int j = 0; j < colonne; j++) {
                poissons[i][j] = rand() % 3+1; // Génération d'un nombre aléatoire de poissons (0 ou 3)
            }
        }
    }

    //verification du nombre de poissons possible
    int compteur ;
    for (int i = 0 ; i< ligne ; i++){
            for (int j = 0; j < colonne  ; j++) {
                if (poissons[i][j]==1){
                    compteur++;
                }
            }
    }

    if (compteur < nbre_joueur*pingouin_par_joueur){
        printf("il n'y a pas assez de poissons pour tous les joueurs\n");
        initialiser_poissons(ligne,colonne,poissons, pingouin_par_joueur , nbre_joueur);
    }
}
