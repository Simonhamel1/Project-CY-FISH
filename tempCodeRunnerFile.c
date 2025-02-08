#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int numeroRue;
    char nomRue[100];
    char nomVille[100];
} Adresse;

typedef struct {
    char nom[100];
    char prenom[100];
    Adresse adresse;
    int pointsFidelite;
    Date dateNaissance;
    Date dateAdhesion;
} Client;

// 2. Fonction afficheAdresse
void afficheAdresse(Adresse adresse) {
    printf("%d %s, %s\n", adresse.numeroRue, adresse.nomRue, adresse.nomVille);
}

// 3. Fonction memeDate
int memeDate(Date date1, Date date2) {
    if (date1.jour == date2.jour && date1.mois == date2.mois){

        return 1;
    } 
    else{
        return 0;
    }
}



int memeMot(char *chaine1, char *chaine2) {
    if (strcmp(chaine1, chaine2) == 0) {
        return 1;
    } else {
        return 0;
    }
}


// 6. Fonction constructeur d’un client
Client creerClient() {
    Client client;
    
    int valid;

    printf("Entrez le nom: ");
    scanf("%s", client.nom);
    printf("Entrez le prénom: ");
    scanf("%s", client.prenom);

    do {
        valid = 1;
        printf("Entrez le numéro de rue: ");
        scanf("%d", &client.adresse.numeroRue);
        if (client.adresse.numeroRue <= 0) {
            printf("Numéro de rue invalide.\n");
            valid = 0;
        }
    } while (valid != 1);

    printf("Entrez le nom de rue: ");
    scanf("%s", client.adresse.nomRue);
    printf("Entrez le nom de ville: ");
    scanf("%s", client.adresse.nomVille);

    do {
        valid = 1;
        printf("Entrez le jour de naissance: ");
        scanf("%d", &client.dateNaissance.jour);
        if (client.dateNaissance.jour < 1 || client.dateNaissance.jour > 31) {
            printf("Jour invalide.\n");
            valid = 0;
        }
    } while (valid != 1);

    do {
        valid = 1;
        printf("Entrez le mois de naissance: ");
        scanf("%d", &client.dateNaissance.mois);
        if (client.dateNaissance.mois < 1 || client.dateNaissance.mois > 12) {
            printf("Mois invalide.\n");
            valid = 0;
        }
    } while (valid != 1);

    printf("Entrez l'année de naissance: ");
    scanf("%d", &client.dateNaissance.annee);

    client.pointsFidelite = 0;
    client.dateAdhesion.jour = 23;
    client.dateAdhesion.mois = 2;
    client.dateAdhesion.annee = 2023;

    return client;
}

// 7. Fonction majPoint
void majPoint(Client *client, int montantAchats) {
    client->pointsFidelite += montantAchats / 100;
}

// 8. Fonction reduction
int reduction(Client client) {
    int anneesAdhesion = nombreAnnees(client.dateAdhesion, (Date){23, 2, 2023});
    int reduction = anneesAdhesion * 5 + client.pointsFidelite;
    if (reduction > 50) {
        reduction = 50;
    }
    return reduction;
}

// 9. Fonction anniversaire
void anniversaire(Client clients[], int taille, Date date) {
    for (int i = 0; i < taille; i++) {
        if (memeDate(clients[i].dateNaissance, date)) {
            printf("Anniversaire de %s %s aujourd'hui.\n", clients[i].nom, clients[i].prenom);
        }
    }
}

// 10. Fonction adressePublicite
void adressePublicite(Client clients[], int taille, char *ville) {
    for (int i = 0; i < taille; i++) {
        if (memeMot(clients[i].adresse.nomVille, ville)) {
            afficheAdresse(clients[i].adresse);
        }
    }
}

int main() {
    // Tests des fonctions
    Client client1 = creerClient();
    Client clients[] = {client1};
    majPoint(&client1, 250);
    printf("Points de fidélité mis à jour : %d\n", client1.pointsFidelite);
    printf("Réduction : %d%%\n", reduction(client1));

    Date dateTest = {23, 2, 2023};
    anniversaire(clients, 1, dateTest);

    adressePublicite(clients, 1, client1.adresse.nomVille);

    return 0;
}
