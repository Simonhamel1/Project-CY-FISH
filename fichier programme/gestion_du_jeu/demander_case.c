void demander_case(int** poissons , int colonne, int ligne){
    printf("\nvous voulez voir quelle case ? ");
    int case_x,case_y;
    scanf("%d %d",& case_x,&case_y);
    while ((case_x == ligne -1 && case_y%2 == 1) || case_x > ligne-1 || case_y > colonne-1 || case_x < 0 || case_y < 0 ){
        printf("la case n'existe pas veuillez la redonnez\n");
        scanf("%d %d",& case_x,&case_y);
    }
    printf("il y a %d poissons dans la case [%d][%d]",poissons[case_x][case_y],case_x,case_y);
    int choix;
    printf("\nvous voulez revoir une case (1->non) ? ");
    scanf("%d",&choix);
    while (choix !=1 ){
        printf("\nquelle case ? ");
        scanf("%d %d",& case_x,&case_y);
        printf("il y a %d poissons dans la case [%d][%d]",poissons[case_x][case_y],case_x,case_y);
        printf("\nvous voulez revoir une case (1->non) ? ");
        scanf("%d",&choix);
    }
}