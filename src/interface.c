#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void afficher_menu()
{
    printf("\n=== Menu Utilisateur ===\n");
    printf("1. Charger deux matrices (saisie ou fichier)\n");
    printf("2. Afficher les matrices chargees\n");
    printf("3. Faire le produit matriciel\n");
    printf("4. Afficher le resultat du produit matriciel\n");
    printf("5. Sauvegarder le resultat dans un fichier\n");
    printf("6. Afficher l'aide\n");
    printf("7. Quitter\n");
}

void menu()
{
    afficher_menu();
    int choix;
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        chargerMatrices();
        break;
    case 2:
        afficher2matrices();
        break;
    case 3:
        afficherProduit();
        break;
    case 4:
        afficherProduit();
        break;
    case 5:
        afficherProduit();
        break;
    case 6:
        afficher_menu();
        break;
    case 7:

        return 0;
    default:
        break;
    }
}
