void demander_case(int** poissons){
    printf("\nvous voulez voir quelle case ? ");
    int case_x,case_y;
    scanf("%d %d",& case_x,&case_y);
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