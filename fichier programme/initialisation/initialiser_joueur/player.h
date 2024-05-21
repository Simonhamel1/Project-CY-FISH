#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    int x, y;
    int numero_pingouin ;
} Pingouin;

typedef struct {
    int numero;
    char nom[50];
    int nombre_pingouins;
    Pingouin *pingouins;  // tableau de pingouins, ajuster selon le nombre maximum de pingouins par joueur
    int score;
} Joueur;

#endif // JOUEUR_H
