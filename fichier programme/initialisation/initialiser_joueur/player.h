#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int x, y;
} Pingouin;

typedef struct {
    char nom[50];
    int nombre_pingouins;
    Pingouin pingouins[4];  // tableau de pingouins, ajuster selon le nombre maximum de pingouins par joueur
    int score;
} Player;

#endif // PLAYER_H
