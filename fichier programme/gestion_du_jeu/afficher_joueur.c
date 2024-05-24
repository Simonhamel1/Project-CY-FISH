#include "../initialisation/initialiser_joueur/player.h"


// Fonction pour afficher les joueurs
void afficher_joueur(int nbre_joueur, Joueur joueurs[6]){
        for (int i = 0; i < nbre_joueur; i++) {
            printf(" %s est le %d joueur et son Score est de %d\n",joueurs[i].nom,joueurs[i].numero,joueurs[i].score);
        }
}