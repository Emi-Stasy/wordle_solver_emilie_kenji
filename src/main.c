#include <stdio.h>
#include <string.h>
#include "solver.h"

int main() {
    char mots[MAX_MOTS][LEN_MOT];
    char resultat[MAX_MOTS][LEN_MOT];

    int nb = charger_dict(mots, "ressource/bdd_wordle.txt");

    if (nb == 0) {
        printf("Erreur chargement mots\n");
        return 1;
    }

    printf(" %d mots chargés\n", nb);

    int choix;
    char lettre;
    int pos;

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Filtre contient lettre\n");
        printf("2. Filtre exclut lettre\n");
        printf("3. Filtre position\n");
        printf("4. Afficher mots\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        if (choix == 0) break;

        switch (choix) {

            case 1:
                printf("Lettre: ");
                scanf(" %c", &lettre);
                nb = filtre_contient(mots, nb, lettre, resultat);
                memcpy(mots, resultat, sizeof(resultat));
                break;

            case 2:
                printf("Lettre à exclure: ");
                scanf(" %c", &lettre);
                nb = filtre_exclut(mots, nb, lettre, resultat);
                memcpy(mots, resultat, sizeof(resultat));
                break;

            case 3:
                printf("Lettre: ");
                scanf(" %c", &lettre);
                printf("Position (0-4): ");
                scanf("%d", &pos);

                nb = filtre_position(mots, nb, lettre, pos, resultat);
                memcpy(mots, resultat, sizeof(resultat));
                break;

            case 4:
                afficher_mot(mots, nb, NULL);
                break;

            default:
                printf("Choix invalide\n");
        }

        printf(" %d mots restants\n", nb);
    }

    return 0;
}
