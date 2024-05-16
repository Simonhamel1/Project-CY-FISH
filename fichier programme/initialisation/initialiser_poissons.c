void initialiser_poissons(int ligne, int colonne, int** poissons, int nbre_joueur) {
    srand(time(0)); // Initialisation du générateur de nombres aléatoires
    int compteur = 1;
    printf("voulez vous que l'affichage des poissons soit aléatoire ou nom (0-> oui 1-> nom) : ");
    int choix;
    scanf("%d",&choix);
    while (choix!=0 && choix!= 1){
        printf("redonner votre choix : ");
        scanf("%d",&choix);
    }
    if (choix == 1){
        for (int i = 0 ; i< ligne ; i++){
            for (int j = 0; j < colonne  ; j++) {
                if (compteur>nbre_joueur){
                    (compteur = 1);
                }
                if (i != ligne-1){
                printf("joueur %d ",compteur);
                printf("donner le nombre de poissons dans la case [%d][%d] : ",i,j);
                scanf("%d",&poissons[i][j]);
                while (poissons[i][j]<0 || poissons[i][j]>3 ){
                    printf("redonner le nombre de poissons dans la case [%d][%d] :",i,j);
                    scanf("%d",&poissons[i][j]);}
                }
                else { if (j%2==0){
                printf("joueur %d ",compteur);
                printf("donner le nombre de poissons dans la case [%d][%d] : ",i,j);
                scanf("%d",&poissons[i][j]);
                while (poissons[i][j]<0 || poissons[i][j]>3 ){
                    printf("redonner le nombre de poissons dans la case [%d][%d] :",i,j);
                    scanf("%d",&poissons[i][j]);
                    }}
                }
                compteur++;
            }
        }
    }
    else{
        for (int i = 0; i < ligne; i++) {
            for (int j = 0; j < colonne; j++) {
                poissons[i][j] = rand() % 3+1; // Génération d'un nombre aléatoire de poissons (0 ou 3)
            }
        }
    }
}