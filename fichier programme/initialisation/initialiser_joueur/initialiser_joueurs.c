#include "player.h"
#include "../../gestion_du_jeu/afficher_joueur.c"
void initialiser_joueurs(int nbre_joueur, Joueur joueurs[6]) {

        for (int i = 0; i < nbre_joueur; i++) {
            printf("Entrez le nom du joueur %d : ", i + 1);
            joueurs[i].numero=i+1;
            scanf("%s", joueurs[i].nom);
            joueurs[i].score = 0; // Initialize the score to 0
        }

        afficher_joueur(nbre_joueur , joueurs);
}
