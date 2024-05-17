#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    int x, y;
} Pingouin;

typedef struct {
    char nom[50];
    int nombre_pingouins;
    Pingouin *pingouins;  // tableau de pingouins, ajuster selon le nombre maximum de pingouins par joueur
    int score;
} Joueur;

#endif // JOUEUR_H
