#include "case.h"

Case demander_case(Case** poissons, int colonne, int ligne) {
    int x, y;
    printf("Entrez les coordonnées de la case (x y) : ");
    scanf("%d %d", &x, &y);

    while (x < 0 || x >= ligne || y < 0 || y >= colonne) {
        printf("Coordonnées invalides. Entrez de nouvelles coordonnées de la case (x y) : ");
        scanf("%d %d", &x, &y);
    }

    printf("Il y a %d poissons dans la case [%d][%d].\n", poissons[x][y].poissons, x, y);
    return poissons[x][y];
}
