#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "gestion_du_jeu/derouler_du_jeux.c"
#include "gestion_du_jeu/demander_variante.c"
#include "gestion_du_jeu/ajouter_points.c"
#include "gestion_du_jeu/case.h"
#include "gestion_du_jeu/mouvement.h"
#include "gestion_du_jeu/mouvement.c"
#include "gestion_du_jeu/afficher_pingouin.c"
#include "gestion_du_jeu/derouler_du_jeu_automatique.c"
#include "initialisation/initialiser_joueur/player.h"
#include "afficher_support_de_jeux_pair.c"
#include "afficher_support_de_jeux_impair.c"
#include "initialisation/initialiser_joueur/initialiser_joueurs.c"
#include "initialisation/initialiser_pingouin.c"
#include "initialisation/initialiser_poissons.c"
#include "initialisation/placement.h"
#include "demander_case.c"
#include "essai.h"
#include "essai.c"


int main() {
    system("chcp 65001");  // Configure l'encodage en UTF-8 sur la console Windows

    
    int nbre_joueur;
    printf("Vous êtes combien de joueurs? ");
    scanf("%d", &nbre_joueur);

    // Vider le tampon d'entrée pour éviter les problèmes de lecture ultérieure
    while (getchar() != '\n');

    while (nbre_joueur > 6 || nbre_joueur < 2) {
        printf("Le nombre de joueurs doit être entre 2 et 6. Redonnez le nombre de joueurs : ");
        scanf("%d", &nbre_joueur);

        // Vider le tampon d'entrée pour éviter les problèmes de lecture ultérieure
        while (getchar() != '\n');
    }

    Joueur joueurs[6]; // Suppose qu'il peut y avoir jusqu'à 6 joueurs
    initialiser_joueurs(nbre_joueur, joueurs);

    // Initialisation des dimensions du plateau de jeu
    int ligne, colonne;
    printf("Combien de lignes souhaitez-vous? ");
    scanf("%d", &ligne);
    while (ligne < 9) {
        printf("Veuillez entrer un nombre de lignes valide (au moins 9) : ");
        scanf("%d",&ligne);
        // Vider le tampon d'entrée pour éviter les problèmes de lecture ultérieure
        while (getchar() != '\n');
    }


    printf("Combien de colonnes souhaitez-vous? ");
    scanf("%d", &colonne);
    while ( colonne < 9) {
        printf("Veuillez entrer un nombre de colonnes valide (au moins 9) : ");
        scanf("%d", &colonne);
        // Vider le tampon d'entrée pour éviter les problèmes de lecture ultérieure
        while (getchar() != '\n');
    }
    // a enlever c'est pour gagner du temps sinon c'est trop long 
    //colonne = 5;
    //  ligne = 5;

    // Allocation dynamique de mémoire pour le tableau de poissons
    int **poissons = (int **)malloc(ligne * sizeof(int *));
    for (int i = 0; i < ligne; i++) {
        poissons[i] = (int *)malloc(colonne * sizeof(int));
        if (poissons[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire.\n");
            return 1;
        }
    }

    // Choix de la variante du jeu
    int mode = choisir_variante();

    // Initialisation du plateau de poissons
    initialiser_poissons(ligne, colonne, poissons);

    // Initialisation des pingouins
    initialisation_Pingouin(joueurs, nbre_joueur, ligne, colonne, poissons);

    // Affichage du support de jeu en fonction du nombre de colonnes
    if ((colonne % 2) == 0) {
        //essai(ligne, colonne, poissons, nbre_joueur, joueurs);
        afficher_support_de_jeux_pair(ligne, colonne, poissons, nbre_joueur, joueurs);
    } else {
        afficher_support_de_jeux_impair(ligne, colonne, poissons, nbre_joueur, joueurs);
    }

    // Dérouler le jeu
    derouler_jeu(ligne, colonne, poissons, nbre_joueur, joueurs, mode );
    //derouler_jeu_automatique(ligne, colonne, poissons, nbre_joueur, joueurs, mode);
    // Libération de la mémoire allouée pour le tableau dynamique
    for (int i = 0; i < ligne; i++) {
        free(poissons[i]);
    }
    free(poissons);

    printf("Fin du programme \U0001F600\n");
    return 0;
}