#ifndef JOUEUR_H
#define JOUEUR_H
#include <stdio.h>

// Structure pour les pingouins
typedef struct {
    int x, y;
    int numero_pingouin ;
} Pingouin;

// Structure pour les joueurs
typedef struct {
    int numero;
    char nom[50];
    int nombre_pingouins;
    Pingouin *pingouins;  // tableau de pingouins, ajuster selon le nombre maximum de pingouins par joueur
    int score;
} Joueur;

#endif // JOUEUR_H
