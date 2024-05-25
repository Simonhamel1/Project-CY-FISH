# Définir le compilateur
CC = gcc

# Définir les options de compilation
CFLAGS = -Wall -Wextra -Werror -Iinitialisation/initialiser_joueur -Iinitialisation -Igestion_du_jeu -Iafficher

# Définir l'exécutable cible
TARGET = exec

# Définir les fichiers source
SRCS = main.c \
       initialisation/initialiser_joueur/initialiser_joueurs.c \
       initialisation/initialiser_pingouin.c \
       initialisation/initialiser_poissons.c \
       gestion_du_jeu/ajouter_points.c \
       gestion_du_jeu/derouler_du_jeux.c \
       gestion_du_jeu/derouler_du_jeu_automatique.c \
       gestion_du_jeu/afficher_joueur.c \
       gestion_du_jeu/afficher_pingouin.c \
       gestion_du_jeu/mouvement.c \
       afficher/afficher_support_de_jeux_impair.c \
       afficher/afficher_support_de_jeux_pair.c \
       gestion_du_jeu/demander_case_inutile.c \
       gestion_du_jeu/demander_variante.c

# Définir les fichiers objets correspondants
OBJS = $(SRCS:.c=.o)

# Cible par défaut
all: $(TARGET)

# Règle pour construire l'exécutable final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Règles pour construire les fichiers objets
main.o: main.c initialisation/initialiser_joueur/player.h initialisation/placement.h
	$(CC) $(CFLAGS) -c main.c -o main.o

initialisation/initialiser_joueur/initialiser_joueurs.o: initialisation/initialiser_joueur/initialiser_joueurs.c initialisation/initialiser_joueur/player.h initialisation/placement.h
	$(CC) $(CFLAGS) -c initialisation/initialiser_joueur/initialiser_joueurs.c -o initialisation/initialiser_joueur/initialiser_joueurs.o

initialisation/initialiser_pingouin.o: initialisation/initialiser_pingouin.c initialisation/initialiser_joueur/player.h initialisation/placement.h
	$(CC) $(CFLAGS) -c initialisation/initialiser_pingouin.c -o initialisation/initialiser_pingouin.o

initialisation/initialiser_poissons.o: initialisation/initialiser_poissons.c initialisation/placement.h
	$(CC) $(CFLAGS) -c initialisation/initialiser_poissons.c -o initialisation/initialiser_poissons.o

gestion_du_jeu/ajouter_points.o: gestion_du_jeu/ajouter_points.c gestion_du_jeu/ajouter_points.h initialisation/initialiser_joueur/player.h initialisation/placement.h
	$(CC) $(CFLAGS) -c gestion_du_jeu/ajouter_points.c -o gestion_du_jeu/ajouter_points.o

gestion_du_jeu/derouler_du_jeux.o: gestion_du_jeu/derouler_du_jeux.c initialisation/initialiser_joueur/player.h initialisation/placement.h gestion_du_jeu/afficher_pingouin.h
	$(CC) $(CFLAGS) -c gestion_du_jeu/derouler_du_jeux.c -o gestion_du_jeu/derouler_du_jeux.o

gestion_du_jeu/derouler_du_jeu_automatique.o: gestion_du_jeu/derouler_du_jeu_automatique.c initialisation/initialiser_joueur/player.h initialisation/placement.h gestion_du_jeu/afficher_pingouin.h
	$(CC) $(CFLAGS) -c gestion_du_jeu/derouler_du_jeu_automatique.c -o gestion_du_jeu/derouler_du_jeu_automatique.o

gestion_du_jeu/afficher_joueur.o: gestion_du_jeu/afficher_joueur.c gestion_du_jeu/afficher_joueur.h
	$(CC) $(CFLAGS) -c gestion_du_jeu/afficher_joueur.c -o gestion_du_jeu/afficher_joueur.o

gestion_du_jeu/afficher_pingouin.o: gestion_du_jeu/afficher_pingouin.c gestion_du_jeu/afficher_pingouin.h
	$(CC) $(CFLAGS) -c gestion_du_jeu/afficher_pingouin.c -o gestion_du_jeu/afficher_pingouin.o

gestion_du_jeu/mouvement.o: gestion_du_jeu/mouvement.c gestion_du_jeu/mouvement.h
	$(CC) $(CFLAGS) -c gestion_du_jeu/mouvement.c -o gestion_du_jeu/mouvement.o

afficher/afficher_support_de_jeux_impair.o: afficher/afficher_support_de_jeux_impair.c afficher/afficher_support_de_jeux_impair.h
	$(CC) $(CFLAGS) -c afficher/afficher_support_de_jeux_impair.c -o afficher/afficher_support_de_jeux_impair.o

afficher/afficher_support_de_jeux_pair.o: afficher/afficher_support_de_jeux_pair.c afficher/afficher_support_de_jeux_pair.h
	$(CC) $(CFLAGS) -c afficher/afficher_support_de_jeux_pair.c -o afficher/afficher_support_de_jeux_pair.o

gestion_du_jeu/demander_case_inutile.o: gestion_du_jeu/demander_case_inutile.c gestion_du_jeu/case.h
	$(CC) $(CFLAGS) -c gestion_du_jeu/demander_case_inutile.c -o gestion_du_jeu/demander_case_inutile.o

gestion_du_jeu/demander_variante.o: gestion_du_jeu/demander_variante.c
	$(CC) $(CFLAGS) -c gestion_du_jeu/demander_variante.c -o gestion_du_jeu/demander_variante.o

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
